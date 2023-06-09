# SolarBatteryCalculator
Using your smart meter data from Octopus Energy, you can check to see how much you would benefit from having battery storage installed.

## How to use
**I have not provided any UI or means to input parameters after compilation**

1. Open 'SolarBatteryCalculator.cpp' and modify line 10 as below
```
Battery battery_48 = Battery(2400); // 2.4kWh Battery
Battery battery_48 = Battery(4800); // 4.8kWh Battery
Battery battery_48 = Battery(7200); // 7.2kWh Battery
```
2. Set your Import Unit Rate and Export Unit Rate on lines 13 & 14
```
float ImportUnitRate = 0.31f; // 31p
float ExportUnitRate = 0.15f; // 15p
```
3. Replace the "import.csv" and "export.csv" contained within the "SolarBatteryCalculator" directory with your own consumption values which you can get directly from the Octopus 'Explore my usage' section.

    Make sure when downloading your smart meter data that the 'Start Date' of both your import and export are the same. As well, make sure that they are both the same update period (e.g half-hourly)

4. Finally, compile and run the project and you will see in the console a summary of the resuls
```
Real Import: 111.456kWh  £46.8115
Real Export: 376.435kWh  £26.3505
Real Bill: £20.4611
Virtual Import: 7.41029kWh       £3.11232
Virtual Export: 268.017kWh       £18.7612
Virtual Bill: £-15.6489
```

## What else?
You can also modify the parameters of the inverter within 'Inverter.h'. The **Charge Efficieny** and **Discharge Efficiency** are taken into account when running the calculation

### What to do next
- Add date checking to make sure the import and export data begins at the same date
- Add a Maximum Charge/Discharge rate for the batteries (e.g 3.2KW). This would only be useful for more precise readings (every 5 mins) to get a close-enough approximation of actual wattage at that time
- Build a UI with parameter input and data file selection fields
