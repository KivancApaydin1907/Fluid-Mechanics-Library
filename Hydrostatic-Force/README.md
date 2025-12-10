# 🛡️ Hydrostatic Force Calculator

![Language](https://img.shields.io/badge/language-C++-blue.svg) ![Physics](https://img.shields.io/badge/physics-Fluid%20Statics-green.svg)

A fundamental engineering tool designed to calculate the resultant hydrostatic force acting on submerged rectangular surfaces. It handles varying orientations (Tilted, Vertical, Horizontal) by calculating the pressure at the center of gravity (CG).

## 📜 Project History
> *Originally written in 2023 for a Fluid Mechanics module. Refactored in 2025 to fix unit conversions (degrees to radians) and improve code modularity.*

## 📐 Mathematical Model

The total hydrostatic force $F_R$ is calculated using the pressure at the centroid:

$$F_R = (P_{atm} + \rho g h_{cg}) \cdot A$$

Where $h_{cg}$ (depth of centroid) changes based on orientation:
* **Tilted:** $h_{cg} = s + \frac{b}{2}\sin(\theta)$
* **Vertical:** $h_{cg} = s + \frac{b}{2}$
* **Horizontal:** $h_{cg} = s$

### Variable Legend
* **$s$**: Distance from free surface to the top edge of the plate (m).
* **$b$**: Length of the plate perpendicular to the surface (m).
* **$\theta$**: Tilt angle with the horizontal axis.

## 🛠️ Usage

```bash
g++ Hydrostatic_Force.cpp -o HydroCalc
./HydroCalc
```
## ✍️ Author

**Kıvanç Apaydın** – Aerospace Engineer  

