// Tool: Hydrostatic Force Calculator (Submerged Surfaces)

#include <iostream>
#include <cmath>

using namespace std;

const double P_ATM = 101325.0; // Pascal
const double G = 9.81;         // m/s^2
const double PI = 3.141592653589793;

int main()
{
  r:cout << "--- Hydrostatic Force Calculator ---\n";
    cout << "Calculates the resultant force on a submerged rectangular plate.\n\n";

    char pos;
    cout << "Select Orientation:\n";
    cout << " [t] Tilted\n";
    cout << " [v] Vertical\n";
    cout << " [h] Horizontal\n";
    cout << "Choice: ";
    cin >> pos; 

    // Common variables
    double rho, s, a, b, force;

    // Error check for input
    if (pos != 't' && pos != 'v' && pos != 'h') {
        cout << "Error: Invalid selection. Please restart.\n";
		goto r;
    }

    // Input physics properties (Common for all cases)
    cout << "Enter fluid density (kg/m^3): ";
    cin >> rho;
    // Error check for input
    if (pos != 't' && pos != 'v' && pos != 'h') {
        cout << "Error: Invalid selection. Please restart.\n";
        goto r;
    }
    cout << "Enter distance from surface to top edge 's' (m): ";
    cin >> s;
    cout << "Enter plate length 'b' (perpendicular to surface) (m): ";
    cin >> b;
    cout << "Enter plate width 'a' (m): ";
    cin >> a;

    double area = a * b;

    if (pos == 't') // Tilted
    {
        double theta_deg;
        cout << "Enter tilt angle (degrees): ";
        cin >> theta_deg;

        // Convert degrees to radians for C++ math functions
        double theta_rad = theta_deg * PI / 180.0;

        // F = (P_atm + rho * g * h_cg) * Area
        // h_cg = s + (b/2)*sin(theta)
        double h_cg = s + (b / 2.0) * sin(theta_rad);
        force = (P_ATM + rho * G * h_cg) * area;
    }
    else if (pos == 'v') // Vertical (Theta = 90 degrees)
    {
        // h_cg = s + b/2
        double h_cg = s + (b / 2.0);
        force = (P_ATM + rho * G * h_cg) * area;
    }
    else if (pos == 'h') // Horizontal (Theta = 0, but distinct depth)
    {
        // For horizontal, 's' is the depth itself, 'b' doesn't affect depth
        // Note: The original code asked for 'he' separately, but logically 's' is depth here.
        // Let's stick to the logic: P = P_atm + rho*g*s
        force = (P_ATM + rho * G * s) * area;
    }

    cout << "\n----------------------------------\n";
    cout << "Hydrostatic Force: " << force << " N (" << force / 1000.0 << " kN)\n";
    cout << "----------------------------------\n";

    return 0;
}