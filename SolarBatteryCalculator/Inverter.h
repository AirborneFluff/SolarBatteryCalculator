#pragma once
#include "Battery.h"

class Inverter
{
public:
    Inverter(Battery& battery);
    float GetBatteryChargeLevel();

    void ApplyPower(float& importPower, float& exportPower);

private:
    Battery* pBattery;

    float ChargeEfficiency = 0.94f;
    float DischargeEfficiency = 0.945f;
};
