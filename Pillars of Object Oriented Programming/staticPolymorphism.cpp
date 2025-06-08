#include<iostream>
#include<string>

using namespace std;

class MannualCar{
  private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
  public:
    MannualCar(string b,string a){
      this->brand=b;
      this->model=a;
      this->isEngineOn=false;
      this->currentSpeed=0;
      this->currentGear=0;
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

    void shiftGear(int gear){
      currentGear=gear;
      cout<<brand<<" "<<model<<" :Shifted to Gear "<<currentGear<<endl;
    }

    //Overloading Accelerate - Static Polymorphism
    void accelerate(){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" :Cannot accelerate, Engine is off!!"<<endl;
        return;
      }
      currentSpeed+=20;
      cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/hr"<<endl;
    }
    void accelerate(int speed){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" :Cannot accelerate, Engine is off!!"<<endl;
        return;
      }
      currentSpeed+=speed;
      cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/hr"<<endl;
    }

    void brake(){
      currentSpeed-=20;
      if(currentSpeed<0)
        currentSpeed=0;
      cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<"km/hr"<<endl;
    }
};



int main(){
  MannualCar* myMannualCar=new MannualCar("Suzuki","WagonR");
  myMannualCar->startEngine();
  myMannualCar->accelerate();
  myMannualCar->accelerate(40);
  myMannualCar->brake();
  myMannualCar->stopEngine();
  
  delete myMannualCar;

  return 0;
}