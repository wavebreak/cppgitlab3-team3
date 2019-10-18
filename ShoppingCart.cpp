#include <iostream>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.pushback(item);
}

void ShoppingCart::RemoveItem(string itemName)
{  
    for (unsigned int i = 0; i < cartItems.size(); ++i) 
    {
        if (itemName.compare(cartItems.at(i).GetName()) == 0)
          {
            cartItems.erase(cartItems.begin() + i);
            return;
          }
     }
    cout << "Item not found in cart. Nothing removed.\n";
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {

    for (int i = 0; i < cartItems.size(); i++) {

        if (cartItems.at(i).GetName() == item.GetName()) {

            cartItems.at(i).SetQuantity(item.GetQuantity());
        }
        else {
           cout << "Item not found in cart. Nothing modified.";
        }
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int numItems  = 0;
    for(int i = 0; i< cartItems.size(); i++) {
        numItems += cartItems.at(i).GetQuantity();
    }
    return numItems;
}


double ShoppingCart::GetCostOfCart() {
 double totalCost = 0.0;
    for (int i = 0; i < cartItems.size(); ++i) {
        totalCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return totalCost;

    }

void ShoppingCart::PrintTotal() {
    unsigned i;
    int totalCost;

    totalCost = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    totalCost = GetCostOfCart();

    cout << endl << "Total: $" << totalCost << endl;
}

void ShoppingCart::PrintDescriptions() {
    unsigned i;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    if(cartItems.size() > 0) {
        for(i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
    }

    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
}
