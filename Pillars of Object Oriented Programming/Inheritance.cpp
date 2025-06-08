#include<iostream>
#include<string>

using namespace std;
class Car{
  protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

  public:
    Car(string b,string a){
      this->brand=b;
      this->model=a;
      isEngineOn=false;
      currentSpeed=0;
    }

    void startEngine(){
      isEngineOn=true;
      cout<<brand<<" "<<model<<" : Engine Started!!"<<endl;
    }
    void stopEngine(){
      isEngineOn=false;
      currentSpeed=0;
      cout<<brand<<" "<<model<<" :Engine turned off!!"<<endl;
    }
    void accelerate(){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" : Cannot accelerate! Engine is off!!"<<endl;
        return;
      }
      currentSpeed+=20;
      cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/hr"<<endl;
    }
    void brake(){
      currentSpeed-=20;
      if(currentSpeed<0)
        currentSpeed=0;
      cout<<brand<<" "<<model<<" :Braking! Speed is now "<<currentSpeed<<"km/hr"<<endl;
    }
    virtual ~Car(){}
};

class MannualCar : public Car{
  private:
    int currentGear;
  public:
    MannualCar(string b, string m):Car(b,m){
      currentGear=0;
    }
    void shiftGear(int gear){
      currentGear=gear;
      cout<<brand<<" "<<model<<" :Shifted to Gear "<<currentGear<<endl;
    }
};

class ElectricCar : public Car{
  private:
    int batteryLevel;
  public:
    ElectricCar(string b,string m):Car(b,m){
      batteryLevel=100;
    }
    void chargeBattery(){
      batteryLevel=100;
      cout<<brand<<" "<<model<<" : Battery fully Charged!!"<<endl;
    }
};

int main(){
  MannualCar* myMannualCar=new MannualCar("Suzuki","WagonR");
  myMannualCar->startEngine();
  myMannualCar->shiftGear(1);
  myMannualCar->accelerate();
  myMannualCar->brake();
  myMannualCar->stopEngine();
  delete myMannualCar;

  cout<<endl<<"-----------------------------"<<endl;

  ElectricCar *myElectriCar=new ElectricCar("Tesla","Model S");
  myElectriCar->chargeBattery();
  myElectriCar->startEngine();
  myElectriCar->accelerate();
  myElectriCar->brake();
  myElectriCar->stopEngine();
  delete myElectriCar;
  
  return 0;
}