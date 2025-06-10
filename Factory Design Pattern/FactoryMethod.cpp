#include<iostream>
using namespace std;

class Burger{
  public:
    virtual void prepare()=0; //Pure virtual function
    virtual ~Burger(){}    //Virtual Destructor
};

class BasicBurger:public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Basic Burger with bun, patty and ketchup..."<<endl;
    }
};

class StandardBurger: public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Standard Burger with bun, paaty,cheese and lettuce..."<<endl;
    }
};

class PremiumBurger: public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce..."<<endl;
    }
};

class BasicWheatBurger:public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Basic Wheat Burger with bun, patty and ketchup..."<<endl;
    }
};

class StandardWheatBurger: public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Standard Wheat Burger with bun, paaty,cheese and lettuce..."<<endl;
    }
};

class PremiumWheatBurger: public Burger{
  public:
    void prepare() override{
      cout<<"Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce..."<<endl;
    }
};


//Factory and its Concretions
class BurgerFactory{
  public:
    virtual Burger *createBurger(string &type)=0;
};

class SinghBurger: public BurgerFactory{
  public:
    Burger *createBurger(string &type){
      if(type=="basic")
        return new BasicBurger();
      if(type=="standard")
        return new StandardBurger();
      if(type=="premium")
        return new PremiumBurger();
      else{
        cout<<"Invalid Burger type...."<<endl;
        return nullptr;
      }
    }
};
class KingBurger: public BurgerFactory{
  public:
    Burger *createBurger(string &type){
      if(type=="basic")
        return new BasicWheatBurger();
      if(type=="standard")
        return new StandardWheatBurger();
      if(type=="premium")
        return new PremiumWheatBurger();
      else{
        cout<<"Invalid Burger type...."<<endl;
        return nullptr;
      }
    }
};
int main(){
  string type="standard";
  BurgerFactory *myFactory=new KingBurger();
  Burger *burger=myFactory->createBurger(type);
  burger->prepare();

  return 0;
}