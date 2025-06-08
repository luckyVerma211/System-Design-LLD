#include<iostream>
#include<string>
using namespace std;

class SportsCar{
  private:
  //Characteristics
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

  public:
    //Constrcutor
    SportsCar(string b,string a){
      this->brand=b;
      this->model=a;
      isEngineOn=false;
      currentSpeed=0;
      currentGear=0;   //neutral
      tyre="MRF";
    }

    //getters and setters
    int getCurrentSpeed(){
      return this->currentSpeed;
    }
    string getTyre(){
      return this->tyre;
    }
    void setTyre(string tyre){
      //apply validations
      this->tyre=tyre;
    }

    //Beahviours
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
  SportsCar* myCar=new SportsCar("Ford","Mustang");

  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();

  cout<<myCar->getCurrentSpeed();

  delete myCar;
  return 0;
}