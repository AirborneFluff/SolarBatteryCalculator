
#include <iostream>
#include <string>
#include <fstream>

#include "Battery.h"
#include "Inverter.h"

float GetConsumptionFromLine(std::string &line);
Battery battery_48 = Battery(4800);
Inverter inverter = Inverter(battery_48);

float ImportUnitRate = 0.42f;
float ExportUnitRate = 0.07f;

int main(int argc, char* argv[])
{
    std::ifstream exportData;
    std::ifstream importData;
    exportData.open("export.csv");
    importData.open("import.csv");

    std::string e_line;
    std::string i_line;
    float i_meter = 0;
    float e_meter = 0;
    
    float i_r_meter = 0;
    float e_r_meter = 0;
    
    while (std::getline(exportData, e_line))
    {
        if (!std::getline(importData, i_line)) break;
        
        const float e_value = GetConsumptionFromLine(e_line);
        const float i_value = GetConsumptionFromLine(i_line);

        if (e_value < 0 || i_value < 0) continue;

        i_r_meter += i_value;
        e_r_meter += e_value;

        float importPower = i_value * 1000;
        float exportPower = e_value * 1000;

        inverter.ApplyPower(importPower, exportPower);
        i_meter += importPower;
        e_meter += exportPower;
        //std::cout << "Import: " << i_meter/1000 << "kWh\t" << "Export: " << e_meter/1000 << "kWh\t" << "Battery Level: " << battery_48.GetCurrentCharge()/1000 << "kWh" << std::endl;
    }

    float importVal = i_r_meter * ImportUnitRate;
    float exportVal = e_r_meter * ExportUnitRate;
    float virtualImportVal = i_meter/1000 * ImportUnitRate;
    float virtualExportVal = e_meter/1000 * ExportUnitRate;

    std::cout << inverter.GetBatteryChargeLevel() << std::endl;
    std::cout << "Real Import: " << i_r_meter << "\t \x9C" << importVal << std::endl;
    std::cout << "Real Export: " << e_r_meter << "\t \x9C" << exportVal << std::endl;
    std::cout << "Real Month Bill: \x9C" << importVal - exportVal << std::endl;
    
    std::cout << "Virtual Import: " << i_meter/1000 << "\t \x9C" << virtualImportVal << std::endl;
    std::cout << "Virtual Export: " << e_meter/1000 << "\t \x9C" << virtualExportVal << std::endl;
    std::cout << "Virtual Month Bill: \x9C" << virtualImportVal - virtualExportVal << std::endl;
    return 0;
}

float GetConsumptionFromLine(std::string &line)
{
    const size_t pos = line.find(',');
    const std::string data = line.substr(0, pos);
    float val = -1;

    try
    {
        val = std::stof(data);
    }
    catch (const std::exception&)
    {
    }
    
    return val;
}