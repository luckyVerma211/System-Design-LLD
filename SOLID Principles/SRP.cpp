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
};

class ShoppingCartPrinter{
  private:
    ShoppingCart *cart;
  public:
    ShoppingCartPrinter(ShoppingCart *cart){
      this->cart=cart;
    }
    //Printing the Invoice
    void printInvoice(){
      cout<<"Shopping Cart Invoice:\n";
      for(auto p: cart->getProducts()){
        cout<<p->name<<" - $"<<p->price<<endl;
      }
      cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

class ShoppingCartStorage{
  private:
    ShoppingCart *cart;
  public:
    ShoppingCartStorage(ShoppingCart* cart){
      this->cart=cart;
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

  ShoppingCartPrinter *printer= new ShoppingCartPrinter(cart);
  printer->printInvoice();

  ShoppingCartStorage *db=new ShoppingCartStorage(cart);
  db->saveToDataBase();
  
  return 0;
}
