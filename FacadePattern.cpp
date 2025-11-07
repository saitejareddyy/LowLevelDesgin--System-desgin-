#include <iostream>
using namespace std;

class PowerSupply {
public:
    void providerPower(){
        cout<<"Power Supply: Providing Power..."<<endl;
    }
};

class CoolingSystem {
public:
    void startFans(){
        cout<<"Cooling System: Fans Started..."<<endl;
    }
};

class CPU {
public:
    void initialize(){
        cout<<"CPU: initialization started..."<<endl;
    }
};

class Memory {
public:
    void selfTest(){
        cout<<"Memory: self test passed..."<<endl;
    }
};

class HardDrive {
public:
    void spinUp(){
        cout<<"Hard Drive: Spinning up..."<<endl;
    }
};

class BIOS {
public:
    void boot(CPU &cpu, Memory& memory){
        cout<<"BIOS: Booting CPU and Memory checks..."<<endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load(){
        cout<<"Operating System: Loading into memory ..."<<endl;
        
    }
};


//Facade
class ComputerFacade {
private:
    PowerSupply powerSupply;
    CoolingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os; 

public: 
    void startComputer() {
        cout<<"------- Starting Computer -------"<<endl;
        powerSupply.providerPower();
        coolingSystem.startFans();
        bios.boot(cpu, memory);
        hardDrive.spinUp();
        os.load();
    }
};

//Client

int main(){
    ComputerFacade computer;
    computer.startComputer();
    return 0;
}