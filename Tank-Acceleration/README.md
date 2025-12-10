# 🌊 Tank Acceleration & Sloshing Analysis

![Language](https://img.shields.io/badge/language-C++-blue.svg) ![Physics](https://img.shields.io/badge/physics-Rigid%20Body%20Motion-purple.svg)

A C++ solver for analyzing fluid statics under rigid body acceleration. This tool is essential for designing fuel tanks, reservoirs, and fluid transport systems where acceleration forces cause free-surface deformation.

## 📜 Project History
> *Originally developed in 2023 to solve "Fluids with Acceleration" problems.*

## 📐 Mathematical Models

### 1. Linear Translation
When a tank accelerates linearly ($a_x$), the free surface creates an angle $\theta$ with the horizontal:

$$\tan(\theta) = \frac{a_x}{g + a_z}$$

The code calculates:
* Surface inclination angle.
* Maximum fluid rise ($\Delta z$) at the walls.
* Spill/Overflow conditions based on tank geometry.

### 2. Rigid Body Rotation
When a cylindrical tank rotates ($\omega$), the fluid surface forms a paraboloid shape defined by:

$$z(r) = \frac{\omega^2 r^2}{2(g + a_z)} + C$$

The code calculates:
* Paraboloid height.
* "Dry Spot" detection (if the vortex reaches the tank bottom).
* Angular velocity limits before spilling.

## 🛠️ Build & Run

```bash
g++ Fluids_In_Rigid_Body_Motion.cpp -o Tank-Acceleration
./Tank-Acceleration
```

## ✍️ Author

**Kıvanç Apaydın** – Aerospace Engineer  
