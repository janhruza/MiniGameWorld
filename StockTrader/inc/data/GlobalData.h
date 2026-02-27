/*
* GlobalData.h
* Representing various global data used in this app.
*/

#pragma once
#include "../Values.h"

/// <summary>
/// Representing the stock names.
/// </summary>
static const char* g_stockNames[MAX_STOCK_SIZE] =
{
    "AeroStar Dynamics", "Nexus Technologies", "Global Finance", "EcoEnergy Corp", "Titan Manufacturing", "Quantum Computing", "Vertex Pharma", "Sunrise Retail",
    "Horizon Media", "Pinnacle Heavy Ind.", "Silverline Transport", "BlueOcean Shipping", "Nova Space Systems", "CyberNet Security", "Apex Consumer", "Stellar Robotics",
    "Vanguard Biotech", "Fusion Power", "Omega Networks", "Equinox Trading", "Summit Real Estate", "Pioneer Auto", "Infinity Software", "Triton Minerals",
    "Atlas Logistics", "Vortex Aerospace", "Zenith Health", "Radiant Photonics", "Aurora AgriFoods", "Catalyst Chemicals", "Oasis Hospitality", "Pulse Electronics"
};

/// <summary>
/// Representing the stock short code values (Tickers).
/// </summary>
static const char* g_stockCodes[MAX_STOCK_SIZE] =
{
    "AERO", "NEXU", "GLFI", "ECOE", "TITN", "QCOM", "VRTX", "SUNR",
    "HMED", "PINN", "SLVR", "BOSH", "NOVA", "CYBR", "APEX", "STLR",
    "VNGB", "FUSN", "OMGA", "EQNX", "SUMT", "PAUT", "INFS", "TRIT",
    "ATLS", "VRTX", "ZNTH", "RADP", "AGRI", "CTLS", "OASH", "PULS"
};

/// <summary>
/// Representing the stock unit values.
/// </summary>
static double g_stockValues[MAX_STOCK_SIZE] =
{
    12.50, 145.80, 89.25,  42.10,  67.90,  310.45, 120.00, 15.30,
    8.40,  54.20,  22.15,  31.80,  210.60, 88.90,  45.75,  134.20,
    19.99, 5.50,   76.40,  112.30, 48.50,  25.60,  430.10, 1.25,
    38.90, 165.70, 95.20,  27.45,  14.80,  62.10,  18.50,  55.60
};

/// <summary>
/// Maximum percentage change (volatility) per update for each stock.
/// Index matches g_stockNames and g_stockValues.
/// </summary>
constexpr double g_stockVolatilities[MAX_STOCK_SIZE] =
{
    0.045, 0.035, 0.015, 0.050, 0.025, 0.070, 0.060, 0.030, // Aero to Sunrise
    0.040, 0.020, 0.030, 0.035, 0.080, 0.055, 0.020, 0.065, // Horizon to Stellar
    0.075, 0.120, 0.040, 0.025, 0.030, 0.035, 0.045, 0.150, // Vanguard to Triton
    0.025, 0.050, 0.040, 0.060, 0.035, 0.040, 0.030, 0.045  // Atlas to Pulse
};