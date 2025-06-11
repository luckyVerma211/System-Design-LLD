#include<iostream>
#include<vector>
using namespace std;

class Product{
  public:
    string name;
    double price;

    Product(string name, double price){
      this->name=name;
      this->price=price;
    }
};

//Violating SRP Principle by different task perfomed by a single Class
class ShoppingCart{
  private:
    vector<Product*> products;

  public:
    void addProduct(Product *p){
      products.push_back(p);
    }
    const vector<Product*> & getProducts(){
      return products;
    }

    //Calculating the total price
    double calculateTotal(){
       double total=0;
       for(auto p: products){
        total+=p->price;
       }
       return total;
    }

    //Printing the Invoice
    void printInvoice(){
      cout<<"Shopping Cart Invoice:\n";
      for(auto p: products){
        cout<<p->name<<" - $"<<p->price<<endl;
      }
      cout<<"Total: $"<<calculateTotal()<<endl;
    }

    //Saving  data to DataBase
    void saveToDataBase(){
      cout<<"Saving shopping cart to Database..."<<endl;
    }
};

int main(){
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Laptop",1500));
  cart->addProduct(new Product("Mouse",50));

  cart->printInvoice();
  cart->saveToDataBase();
  return 0;
}