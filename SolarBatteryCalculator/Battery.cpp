#include "Battery.h"
#include <cmath>

float Battery::AddCharge(float watts, float hours)
{
    const float usableWatts = ClampWatts(watts);
    const float usablePower = usableWatts * hours;
    float excessPower = (watts - usableWatts) * hours;
    excessPower += ApplyCharge(usablePower);
    return excessPower;
}

float Battery::AddChargeSimple(float wattHours)
{
    return ApplyCharge(wattHours);
}

float Battery::RemoveChargeSimple(float wattHours)
{
    return -ApplyCharge(-wattHours);
}

float Battery::RemoveCharge(float watts, float hours)
{
	return -AddCharge(-watts, hours);
}

float Battery::GetCurrentCharge()
{
	return CurrentCapacity;
}

Battery::Battery(float usableCapacity)
{
    UsableCapacity = usableCapacity;
    NominalCapacity = usableCapacity;
}

float Battery::ApplyCharge(float wattHours)
{
    CurrentCapacity += wattHours; // Apply Power

    float totalPotential = CurrentCapacity; // Store current value before bounds

    CurrentCapacity = fmax(0.0f, CurrentCapacity); // Lower bound is 0kwh
    CurrentCapacity = fmin(UsableCapacity, CurrentCapacity); // Upper bound is UsableCapacity value

    return totalPotential - CurrentCapacity; // Remaining power after bounds
}

float Battery::ClampWatts(float watts)
{
    const float maxPower = MaxCurrent * NominalVoltage;
    float clampedPower = fmax(-maxPower, watts);
    clampedPower = fmin(maxPower, clampedPower);
    return clampedPower;
}
