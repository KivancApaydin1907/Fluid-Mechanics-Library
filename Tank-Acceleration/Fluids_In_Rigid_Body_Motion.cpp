// Tool: Tank Acceleration & Sloshing Analyzer
// Physics: Fluid Statics in Rigid Body Motion

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const double G = 9.81;
const double PI = 3.141592653589793;

// --- Helper Functions ---
double to_rad(double deg) { return deg * PI / 180.0; }
double to_deg(double rad) { return rad * 180.0 / PI; }

// --- Solver 1: Linear Acceleration (Translation) ---
void analyze_linear() {
    double ax, az, h_fluid, h_tank, length, width, rho;

    cout << "\n--- Linear Acceleration Analysis ---\n";
    cout << "Enter x-acceleration (m/s^2): "; cin >> ax;
    cout << "Enter z-acceleration (m/s^2): "; cin >> az;
    cout << "Enter fluid height (m): ";       cin >> h_fluid;
    cout << "Enter tank height (m): ";        cin >> h_tank;
    cout << "Enter tank length (m) [Direction of motion]: "; cin >> length;
    cout << "Enter tank width (m)  [Perpendicular]: ";       cin >> width;
    cout << "Enter fluid density (kg/m^3): "; cin >> rho;

    // 1. Calculate Surface Angle (Theta)
    // tan(theta) = ax / (g + az)
    double theta_rad = atan(ax / (G + az));
    double theta_deg = to_deg(theta_rad);

    // 2. Calculate Fluid Rise (Delta Z)
    double delta_z = (length / 2.0) * tan(theta_rad);

    // 3. Max Acceleration Check
    double a_max = ((G + az) * (h_tank - h_fluid)) / (length / 2.0);

    cout << "\n--- Results ---\n";
    cout << "Surface Angle: " << fixed << setprecision(2) << theta_deg << " degrees" << endl;
    cout << "Fluid Rise (dz): " << delta_z << " m" << endl;
    cout << "Max Ax before spill: " << a_max << " m/s^2" << endl;

    if (delta_z <= (h_tank - h_fluid)) {
        cout << "Status: [SAFE] No overflow detected." << endl;

        // Pressure Calculation (Simplified at bottom corner)
        double p_static = rho * (G + az) * h_fluid;
        // Simplified dynamic addition approximation
        cout << "Est. Static Pressure at bottom: " << p_static / 1000.0 << " kPa" << endl;

    }
    else {
        cout << "Status: [WARNING] FLUID OVERFLOW!" << endl;

        // Overflow Volume Logic
        // Calculate new effective length where liquid hits the top edge
        double x_effective = (h_tank - h_fluid) / tan(theta_rad);
        // Note: Full volume loss calculation requires complex geometry integration
        // leaving basic warning for now.
    }
}

// --- Solver 2: Rotational Acceleration (Rigid Body Rotation) ---
void analyze_rotational() {
    double rpm, az, h_fluid, h_tank, radius;

    cout << "\n--- Rotational Acceleration Analysis ---\n";
    cout << "Enter Rotation Speed (RPM): ";   cin >> rpm;
    cout << "Enter z-acceleration (m/s^2): "; cin >> az; // Usually 0 unless vertical lift
    cout << "Enter fluid height (m): ";       cin >> h_fluid;
    cout << "Enter tank height (m): ";        cin >> h_tank;
    cout << "Enter tank radius (m): ";        cin >> radius;

    double omega = (rpm * 2.0 * PI) / 60.0; // rad/s

    // 1. Calculate Paraboloid Height Difference
    // z = (w^2 * r^2) / (2g)
    double total_paraboloid_height = (pow(omega, 2) * pow(radius, 2)) / (2 * (G + az));

    // The fluid surface drops at center and rises at walls.
    // Rise from original level = h_total / 2 (for cylinder)
    double rise_at_wall = total_paraboloid_height / 2.0;
    double drop_at_center = total_paraboloid_height / 2.0;

    double z_max = h_fluid + rise_at_wall;
    double z_min = h_fluid - drop_at_center;

    cout << "\n--- Results ---\n";
    cout << "Angular Velocity: " << omega << " rad/s" << endl;
    cout << "Max Fluid Height (at wall): " << z_max << " m" << endl;
    cout << "Min Fluid Height (at center): " << z_min << " m" << endl;

    // Check Spill
    if (z_max > h_tank) {
        cout << "Status: [WARNING] FLUID OVERFLOW (Spill over rim)" << endl;
    }
    else {
        cout << "Status: [SAFE] No overflow." << endl;
    }

    // Check Bottom Exposure
    if (z_min < 0) {
        cout << "Status: [WARNING] DRY SPOT (Vortex touches bottom)" << endl;
        double r_dry = sqrt((2 * (G + az) * abs(z_min)) / pow(omega, 2));
        cout << "Dry Spot Radius: " << r_dry << " m" << endl;
    }
}

int main() {
    char mode;

    cout << "==========================================\n";
    cout << "               TANK ANALYZER              \n";
    cout << "==========================================\n";
    cout << "Select Analysis Mode:\n";
    cout << " [L] Linear Acceleration (Translation)\n";
    cout << " [R] Rotational Acceleration (Centrifuge)\n";
    cout << "Choice: ";
    cin >> mode;

    if (mode == 'l' || mode == 'L') {
        analyze_linear();
    }
    else if (mode == 'r' || mode == 'R') {
        analyze_rotational();
    }
    else {
        cout << "Invalid selection. Aborting.\n";
    }

    return 0;
}