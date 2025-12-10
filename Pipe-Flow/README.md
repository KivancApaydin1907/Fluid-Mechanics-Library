# 🚰 Hydraulic Pipe Flow Calculator

![Language](https://img.shields.io/badge/language-C++-blue.svg) ![Method](https://img.shields.io/badge/method-Colebrook--White-green.svg) ![Status](https://img.shields.io/badge/status-Refactored-purple.svg)

A C++ engineering tool designed to calculate head loss, pressure drop, and pumping power requirements in circular pipes. It eliminates manual Moody Chart readings by automating the solution of the implicit **Colebrook-White equation**.

## 📜 Project History

> *This tool was originally designed by the author in 2023 for a Fluid Dynamics course. It has been refactored and modernized by AI assistants, under the author's supervision, to meet professional open-source standards for public release.*

## 🚀 Features

* **Automatic Regime Detection:** Seamlessly handles Laminar ($Re < 2300$) and Turbulent flows.
* **Iterative Solver:** Implements the **Bisection Method** to solve the non-linear friction factor equations with high precision.
* **Safety First:** Internal calculations are performed strictly in **SI Units** (Pascals, Watts) to prevent engineering errors.

## 🛠️ Build & Run

### Prerequisites
* G++ Compiler

### Usage
```bash
# Compile
g++ pipe_flow.cpp -o PipeFlow

# Run
./PipeFlow
```

## ✍️ Author

**Kıvanç Apaydın** – Aerospace Engineer  
