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
Real Import: 111.456     £46.8115
Real Export: 376.435     £26.3505
Real Month Bill: £20.4611
Virtual Import: 7.41029  £3.11232
Virtual Export: 268.017  £18.7612
Virtual Month Bill: £-15.6489
```
