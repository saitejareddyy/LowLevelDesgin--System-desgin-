#include <iostream>
using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

/*
1. This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

2. In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or steering wheel). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

3. Therefore, to denote a real world car in programming we created 2 classes.
One to denote all the user-interface like pedals, buttons, steering wheels etc ('Car' class).And,
Another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
*/

class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m){
        this -> brand = b;
        this -> model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; 
    }

    void startEngine(){
        isEngineOn = true;
        cout<< brand <<" " << model << " : Engine starts with a roar!"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<< brand <<" " << model << " : Engine is off! Cannot Shift Gear"<<endl;
        }
        currentGear = gear;
        cout<< brand <<" " << model << " : Shifted to Gear"<<currentGear<<endl;
    }

    void accelerate() {
        if(!isEngineOn){
            cout<< brand <<" " << model << " : Engine is off! Cannot accelerate"<<endl;
        }
        currentSpeed += 20;
        cout<< brand <<" " << model << " : Accelerating to "<<currentSpeed << "km/h"<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<< brand <<" " << model << " : Breaking! Speed is now "<<currentSpeed << "km/h"<<endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout<<brand<<" "<<model<<" "<<": Engine turned off. "<<endl;
    }

};

int main(){

    Car* myCar = new SportsCar("Dodge", "Charger 1968");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->startEngine();


    return 0;
}