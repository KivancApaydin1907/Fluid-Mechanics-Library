// Tool: Hydraulic Pipe Flow Calculator
// Physics: Darcy-Weisbach & Colebrook-White Equations

#include <iostream>
#include <cmath>
#include <iomanip> // For clean output formatting

using namespace std;

const double PI = 3.141592653589793;
const double G = 9.81;

// --- Colebrook-White Residual Function ---
// Solves for: 1/sqrt(f) = -2.0 * log10( (e/D)/3.7 + 2.51/(Re * sqrt(f)) )
double colebrook_residual(double f, double Re, double relative_roughness) {
    double left = 1.0 / sqrt(f);
    double right = -2.0 * log10((relative_roughness / 3.7) + (2.51 / (Re * sqrt(f))));
    return left - right;
}

// --- Solver: Bisection Method ---
// Automatically finds friction factor 'f' without user guessing
double solve_friction_factor(double Re, double relative_roughness) {
    double lower = 0.001; // Minimum physical f
    double upper = 0.15;  // Maximum physical f (very rough pipe)
    double mid, f_mid, f_lower;
    double tolerance = 1e-6;
    int max_iter = 100;

    // Safety check: Ensure root is bracketed
    if (colebrook_residual(lower, Re, relative_roughness) * colebrook_residual(upper, Re, relative_roughness) > 0) {
        cerr << "Error: Root not bracketed. Check Reynolds number or roughness." << endl;
        return -1.0;
    }

    for (int i = 0; i < max_iter; i++) {
        mid = (lower + upper) / 2.0;
        f_mid = colebrook_residual(mid, Re, relative_roughness);
        f_lower = colebrook_residual(lower, Re, relative_roughness);

        if (abs(f_mid) < tolerance) return mid; // Found exact root

        if (f_lower * f_mid < 0) {
            upper = mid; // Root is in lower half
        }
        else {
            lower = mid; // Root is in upper half
        }
    }
    return mid; // Return best estimate
}

int main() {
    // Inputs
    double theta_deg, flow_rate, diameter, length, density, viscosity, roughness;

    cout << "\n=== Pipe Flow Analyzer ===\n";
    cout << "Enter pipe angle (deg, 0=horizontal): "; cin >> theta_deg;
    cout << "Enter flow rate (m^3/s): ";              cin >> flow_rate;
    cout << "Enter pipe diameter (m): ";              cin >> diameter;
    cout << "Enter pipe length (m): ";                cin >> length;
    cout << "Enter fluid density (kg/m^3): ";         cin >> density;
    cout << "Enter dynamic viscosity (Pa.s): ";       cin >> viscosity;

    // Calculations
    double area = (PI * pow(diameter, 2)) / 4.0;
    double velocity = flow_rate / area;
    double Re = (density * velocity * diameter) / viscosity;

    cout << "\n----------------------------------\n";
    cout << "Reynolds Number: " << fixed << setprecision(2) << Re << endl;

    double f; // Friction factor

    // Determine Flow Regime
    if (Re < 2300) {
        cout << "Flow Regime: LAMINAR" << endl;
        f = 64.0 / Re;
    }
    else {
        if (Re < 4000) cout << "Flow Regime: TRANSITION (Using Colebrook)" << endl;
        else           cout << "Flow Regime: TURBULENT" << endl;

        cout << "Enter pipe roughness height (m) [e.g. 0.000045 for steel]: ";
        cin >> roughness;
        double relative_roughness = roughness / diameter;

        f = solve_friction_factor(Re, relative_roughness);
    }

    // Darcy-Weisbach Equation (Pressure Drop in Pascals)
    double pressure_drop_Pa = f * (length / diameter) * (0.5 * density * pow(velocity, 2));

    // Head Loss (in meters) -> Uses Pascals!
    double head_loss = pressure_drop_Pa / (density * G);

    // Pumping Power (in Watts) -> Uses Pascals * m^3/s
    double power_watts = pressure_drop_Pa * flow_rate;

    // Elevation Change (optional to add to total head, but keeping simple friction loss here)
    // double elevation_head = length * sin(theta_deg * PI / 180.0);

    cout << "----------------------------------\n";
    cout << "Friction Factor (f): " << setprecision(5) << f << endl;
    cout << "Pressure Drop:       " << setprecision(2) << pressure_drop_Pa / 1000.0 << " kPa" << endl;
    cout << "Head Loss:           " << setprecision(3) << head_loss << " m" << endl;
    cout << "Power Required:      " << setprecision(2) << power_watts << " W (" << power_watts / 1000.0 << " kW)" << endl;
    cout << "----------------------------------\n";

    return 0;
}