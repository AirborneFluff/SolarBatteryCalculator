#include "Inverter.h"

Inverter::Inverter(Battery& battery)
{
    pBattery = &battery;
}

float Inverter::GetBatteryChargeLevel()
{
    return pBattery->GetCurrentCharge();
}

void Inverter::ApplyPower(float& importPower, float& exportPower)
{
    const float exportPotential = exportPower * ChargeEfficiency;
    const float importPotential = importPower * DischargeEfficiency;
    float unusedPower;
    if (exportPotential > 0)
    {
        unusedPower = pBattery->AddChargeSimple(exportPotential);
        exportPower = unusedPower / ChargeEfficiency;
    }
    if (importPotential > 0)
    {
        unusedPower = pBattery->RemoveChargeSimple(importPotential);
        importPower = unusedPower / DischargeEfficiency;
    }
}
