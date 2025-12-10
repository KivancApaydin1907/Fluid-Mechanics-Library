# 🌊 Fluid Mechanics Library

![Language](https://img.shields.io/badge/language-C++-blue.svg) ![Field](https://img.shields.io/badge/field-Aerospace%20Engineering-orange.svg) ![License](https://img.shields.io/badge/license-MIT-green.svg)

A centralized C++ library of engineering tools and solvers for Fluid Dynamics (CFD), Hydraulics, and Hydrostatics. Developed by **Airwolf Dynamics** to automate complex analyses in aerospace applications.

## 📂 Internal Modules

| Category | Module | Description | Status |
| :--- | :--- | :--- | :--- |
| **Hydraulics** | **[Hydraulic Pipe Flow](./Pipe-Flow)** | Solves the Colebrook-White equation for pressure drop and head loss in internal flows. | ✅ Stable |
| **Dynamics** | **[Tank Sloshing Analysis](./Tank-Acceleration)** | Analyzes fluid surface deformation and spill conditions under linear & angular acceleration. | ✅ Stable |
| **Statics** | **[Hydrostatic Force Calc](./Hydrostatic-Force)** | Calculates resultant forces on submerged rectangular surfaces (Tilted/Vertical). | ✅ Stable |

## 🔗 Related Projects

Check out the standalone CFD meshing tool developed by the author:
* **[Boundary-Layer-Tool](https://github.com/KivancApaydin1907/Boundary-Layer-Tool):** Geometric growth ratio calculator for inflation layers ($y^+$).

## 🛠️ Getting Started

Clone the entire library to your local machine:

```bash
git clone [https://github.com/KivancApaydin1907/Fluid-Mechanics-Library.git](https://github.com/KivancApaydin1907/Fluid-Mechanics-Library.git)
cd Fluid-Mechanics-Library
```
Each module operates independently. Navigate to the specific folder to compile and run the tools using g++

## 📜 Project History

These tools were originally developed during the author's undergraduate studies for Fluid Dynamics courses (2023-2024). They have been refactored, modernized, and consolidated into this library by AI assistants under the author's supervision.

## ✍️ Author

**Kıvanç Apaydın** – Aerospace Engineer  
