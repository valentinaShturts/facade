#include <iostream>
#include <string>
#include <random>

using namespace std;


class PowerSupply 
{
public:
    void SupplyPower() { cout << "Power Supply: providing power.\n"; }
    void PowerToGPU() { cout << "Power Supply: providing power to the GPU.\n"; }
    void PowerToRAM() { cout << "Power Supply: providing power to the RAM.\n"; }
    void PowerToDiskDrive() { cout << "Power Supply: providing power to the optical disk drive.\n"; }
    void PowerToHDD() { cout << "Power Supply: providing power to the hard drive.\n"; }
    void CutPowerToGPU() { cout << "Power Supply: cutting power to the GPU.\n"; }
    void CutPowerToRAM() { cout << "Power Supply: cutting power to the RAM.\n"; }
    void CutPowerToDiskDrive() { cout << "Power Supply: cutting power to the optical disk drive.\n"; }
    void CutPowerToHDD() { cout << "Power Supply: cutting power to the hard drive.\n"; }
    void Shutdown() { cout << "Power Supply: shutdown.\n"; }
};

class Sensors 
{
public:
    void CheckVoltage() { cout << "Sensors: checking voltage.\n"; }
    void CheckPowerTemp() { cout << "Sensors: checking temperature in the power supply.\n"; }
    void CheckGPUTemp() { cout << "Sensors: checking temperature in the GPU.\n"; }
    void CheckRAMTemp() { cout << "Sensors: checking temperature in the RAM.\n"; }
    void CheckAllTemps() { cout << "Sensors: checking temperatures of all systems.\n"; }
};

class GPU 
{
public:
    void Start() { cout << "GPU: startup.\n"; }
    void CheckMonitorConnection() { cout << "GPU: checking monitor connection.\n"; }
    void DisplayRAMInfo() { cout << "GPU: displaying RAM information.\n"; }
    void DisplayDiskDriveInfo() { cout << "GPU: displaying optical disk drive information.\n"; }
    void DisplayHDDInfo() { cout << "GPU: displaying hard drive information.\n"; }
    void FarewellMessage() { cout << "GPU: farewell message.\n"; }
};

class RAM 
{
public:
    void StartDevices() { cout << "RAM: starting devices.\n"; }
    void AnalyzeMemory() { cout << "RAM: analyzing memory.\n"; }
    void ClearMemory() { cout << "RAM: clearing memory.\n"; }
};

class DiskDrive 
{
public:
    void Start() { cout << "Optical Disk Drive: startup.\n"; }
    void CheckDisk() { cout << "Optical Disk Drive: checking for disk.\n"; }
    void Reset() { cout << "Optical Disk Drive: resetting to initial position.\n"; }
};

class HDD 
{
public:
    void Start() { cout << "Hard Drive: startup.\n"; }
    void CheckBootSector() { cout << "Hard Drive: checking boot sector.\n"; }
    void Stop() { cout << "Hard Drive: stopping device.\n"; }
};

class Facade 
{
private:
    PowerSupply ps;
    Sensors sensors;
    GPU gpu;
    RAM ram;
    DiskDrive drive;
    HDD hdd;

public:
    void BeginWork() 
    {
        ps.SupplyPower();
        sensors.CheckVoltage();
        sensors.CheckPowerTemp();
        sensors.CheckGPUTemp();
        ps.PowerToGPU();
        gpu.Start();
        gpu.CheckMonitorConnection();
        sensors.CheckRAMTemp();
        ps.PowerToRAM();
        ram.StartDevices();
        ram.AnalyzeMemory();
        gpu.DisplayRAMInfo();
        ps.PowerToDiskDrive();
        drive.Start();
        drive.CheckDisk();
        gpu.DisplayDiskDriveInfo();
        ps.PowerToHDD();
        hdd.Start();
        hdd.CheckBootSector();
        gpu.DisplayHDDInfo();
        sensors.CheckAllTemps();
    }

    void Shutdown() 
    {
        hdd.Stop();
        ram.ClearMemory();
        ram.AnalyzeMemory();
        gpu.FarewellMessage();
        drive.Reset();
        ps.CutPowerToGPU();
        ps.CutPowerToRAM();
        ps.CutPowerToDiskDrive();
        ps.CutPowerToHDD();
        sensors.CheckVoltage();
        ps.Shutdown();
    }
};

int main() 
{
    Facade computer;

    cout << "Computer booting up:\n";
    computer.BeginWork();

    cout << "\nComputer shutting down:\n";
    computer.Shutdown();

    return 0;
}
