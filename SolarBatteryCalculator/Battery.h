#pragma once

class Battery
{
public:
    float AddCharge(float watts, float hours);
    float AddChargeSimple(float wattHours);
    float RemoveChargeSimple(float wattHours);
    float RemoveCharge(float watts, float hours);
    float GetCurrentCharge();
    Battery(float usableCapacity);


private:
    float NominalCapacity;
    float UsableCapacity;
    float CurrentCapacity = 0;
    float NominalVoltage = 48;
    float MaxCurrent = 25;

    float ApplyCharge(float wattHours);
    float ClampWatts(float watts);
};
