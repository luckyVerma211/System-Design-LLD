#include<iostream>
#include<string>
using namespace std;

class Car{
  public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}
};

class SportsCar : public Car{
  public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b,string a){
      this->brand=b;
      this->model=a;
      isEngineOn=false;
      currentSpeed=0;
      currentGear=0;   //neutral
    }

    void startEngine(){
      isEngineOn=true;
      cout<<brand<<" "<<model<<" : Engine starts with a roar!"<<endl;
    }
    void shiftGear(int gear){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" "<<" : Engine is off! Cannot Shift Gear!"<<endl;
      }
      currentGear=gear;
      cout<<brand<<" "<<model<<" : Shiftedto gear "<<currentGear<<"!"<<endl;
    }
    void accelerate(){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate!"<<endl;
        return;
      }
      currentSpeed+=20;
      cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/hr"<<endl;
    }
    void brake(){
      currentSpeed-=20;
      if(currentSpeed<0) currentSpeed=0;
      cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<"km/hr"<<endl;
    }
    void stopEngine(){
      isEngineOn=false;
      currentGear=0;
      currentSpeed=0;
      cout<<brand<<" "<<model<<" :Engine turned off!"<<endl;
    }
};

int main(){
  Car* myCar=new SportsCar("Ford","Mustang");

  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();

  delete myCar;
  return 0;
}
