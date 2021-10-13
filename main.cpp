#include <iostream>
#include <cstring>
using namespace std;
//classes declaration
class ShoppingCart;
class Customer;
class Product;
class Order;
class User;
class SystemAdmin;

//base class(use inheritance)

class Product{
  private:
    string productID;
    string productName;
    string productDescription;
    int price;
    Order *orders[1];

  public:
    Product();
    Product(string productID,string productName, string productDescription, int price);
    void addOrders(Order *r)
    {
      orders[0] = r;
    }
    void displayProduct(int i)
    {
      cout << endl <<endl;
      cout <<"===========================Product"<< i << "==============================" <<endl;
      
      cout << "Product Name\t:" << productName << endl;
      cout << "Description\t:" << productDescription << endl;
      cout << "Price\t:" << price << endl;
      cout <<"=================================================================" << endl;
    }
    ~Product(){cout << "\nDelete Product" << productID << endl;}

};
Product::Product(){}
Product::Product(string pproductID,string pproductName, string pproductDescription, int pprice)
{
  productID = pproductID;
  productName = pproductName;
  productDescription = pproductDescription;
  price = pprice;
}


class ShoppingCart
{
  private:
     string cartID;
     int quantity;
     string dateAdded;
     Product *p[3];

  public:
    ShoppingCart();
    ShoppingCart(string scartID, int squantity, string sdateAdded)
    {
      cartID = scartID;
      quantity = squantity;
      dateAdded = sdateAdded;
      
    }
    void addProduct(Product *p1, Product *p2, Product *p3)
    {
      p[0] = p1; 
      p[1] = p2;
      p[2] = p3;
    }
    void displayShopping()
    {
      for(int i = 0; i <3; i++)
      {
        p[i]->displayProduct(i);
      }
    }
    void viewCart(int x)
    {
      for(int i = x; i < 3; i++)
      {
          cout <<"===========================Shipping=============================" << endl;
          cout << "Cart ID\t:" << cartID <<  endl;
          cout << "Product ID\t:" << p[x] <<  endl;  
          cout << "Quantity\t:" << quantity <<  endl; 
          cout << "Date\t:" << dateAdded <<  endl; 
          cout <<"=================================================================" << endl;
          }

    }
    void deleteCartItem()
    {
      cartID = "";
      quantity = 0;
      dateAdded = "";
      cout << endl <<endl;
      cout <<"--------------------------Deleted Cart----------------------" << endl;
    }
    ~ShoppingCart(){ cout << "\nDelete Shopping Cart" << cartID << endl;}
    

};






class Order{
  private:
    string orderID;
    string dateCreated;
    string dateShipping;
    string orderStatus;
    string shpping;
    Product *products[2];

  public:
    Order();
    Order(string rorderID, string rdateCreated, string rdateShipping, string rorderStatus, string rshpping, Product *p);
    void displayOrders()
    {
      for(int i = 0; i < 2; i++)
      {
        products[i]->displayProduct(i);
      }
    }
    void placeOrder()
    {
      cout << endl <<endl;
      cout <<"================================Order============================" << endl;
      
      cout << "Order ID\t:" << orderID << endl;
      cout << "Order Date\t:" << dateCreated <<endl;
      cout << "Order Shipping Date\t:" << dateShipping <<endl;
      cout << "Order Status\t:" << orderStatus <<endl;
      cout << "Order Shipping Place\t:" << shpping <<endl;
      cout <<"=================================================================" << endl;
    }
    ~Order(){ cout << "\nDelete Order" << orderID << endl;}
};
Order::Order(){}
Order::Order(string rorderID, string rdateCreated, string rdateShipping, string rorderStatus, string rshpping, Product *p)
{
  orderID = rorderID;
  dateCreated = rdateCreated;
  dateShipping = rdateShipping;
  orderStatus = rorderStatus;
  shpping = rshpping;
  
  products[0] =  p;
}




class User{
  protected:
      string userID;
      string password;
      int loginStatus;

  public:
      User();
      User(string uid, string pass, int statuslog);
      bool verifyLogin()
      {
        if(password == "1")
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      ~User(){cout << "\nDelete User" << userID << endl; }

};
User::User()  {}
User::User(string uid, string pass, int statuslog)
{
  userID = uid;
  password = pass;
  loginStatus = statuslog;
}


class Customer  :public User
{
  private:
      string customerName;
      string address;
      int phone;
      string cardinfo;
      string shoppinginfo;
      Order *orders[2];
      ShoppingCart *cart[2];

  public:
      Customer()
      {
        orders[0] = new Order();
        orders[1] = new Order();

        cart[0] = new ShoppingCart();
        cart[1] = new ShoppingCart();
      }
      Customer(string cName, string caddress, int cphone, string ccardinfo, string cshopp, string rorderID, string rdateCreated, string rdateShipping, string rorderStatus, string rshpping, string scartID, int squantity, string sdateAdded, string rorderID1, string rdateCreated1, string rdateShipping1, string rorderStatus1, string rshpping1, string scartID1, int squantity1, string sdateAdded1)
      {
        customerName = cName;
        address = caddress;
        phone = cphone;
        cardinfo = ccardinfo;
        shoppinginfo = cshopp;
        orders[0] = new Order(rorderID, rdateCreated, rdateShipping, rorderStatus,rshpping,0);
        orders[1] = new Order(rorderID1, rdateCreated1, rdateShipping1, rorderStatus1,rshpping1, 0);

        cart[0] = new ShoppingCart(scartID, squantity, sdateAdded);
        cart[1] = new ShoppingCart(scartID1, squantity1, sdateAdded1);
      }
      void viewOrders()
      {
        for (int i = 0; i <= 1; i++)
        {
          orders[i]->placeOrder();
        } 
      }
      void Displaycart()
      {
          for (int i = 0; i <= 1; i++)
        {
          cart[i]->viewCart(i);
        } 
      }
      void registerDetails(){}
      void loginDetails(bool stat)
      {
        if(stat == false)
        {
          cout <<"=============================Welcome=============================" << endl;
          cout << "HI Dear\t: " << customerName << endl;
          cout <<"=================================================================" << endl;
        }
        else
        {
          cout << "please try again later! " << endl;
        }
      }
      void updateProfile();
      ~Customer()
      {
        for (int j = 0; j <= 1; j++)
          {
            delete orders[j];
            delete cart[j];
            
          }
          cout << "\n++++++++++++++++++ Deleted Cart Item +++++++++++++++++++++" << endl;   
        }

};




class SystemAdmin   :public User
{
  private:
      string adminName;
      string adminEmail;

  public:
      SystemAdmin();
      SystemAdmin(string aName, string aEmail);
      void UpdateCategory();
      ~SystemAdmin(){cout << "\nDelete SystemAdmin " << adminName << endl;}
};
SystemAdmin::SystemAdmin(){}
SystemAdmin::SystemAdmin(string aName, string aEmail)
{
  adminName = aName;
  adminEmail = aEmail;
}

int main() {
    User *u1 = new User("U102", "1", 0);
    User u4;
    bool statusLogin = u4.verifyLogin();


    Customer *c1 = new Customer("customer 1", "Galle Sri lanka", 9998, "Visa", "galle", "OR102", "2021-12-07", "2021-12-07", "Delay", "Galle", "CART01", 02, "2021-12-07","OR107", "2022-12-07", "2022-12-07", "Received", "Galle Fort", "CART02", 07, "2022-12-07");
    c1->loginDetails(statusLogin);
    

    ShoppingCart * s1 = new ShoppingCart("", 0, "");

    Product *p1 = new Product("PR001", "Shampoo", "Good to use!", 2000);
    Product *p2 = new Product("PR007", "Soap", "Good to Body!", 500);
    Product *p3 = new Product("PR077", "Conditioner", "Good to use!", 2500);

    s1->addProduct(p1, p2, p3);
    s1->displayShopping();

    delete s1;

    p1->displayProduct(0);
    p2->displayProduct(0);
    p3->displayProduct(0);
    c1->Displaycart();
    c1->viewOrders();


    SystemAdmin *a1 = new SystemAdmin("Admin01", "Admin@SLIIT.LK");
    
    
    
    
    
    //p1->displayProduct();
    //c1->viewOrders();
    //c1->Displaycart();

    

    delete c1;
    delete u1;
    delete a1;
    delete p1;


}