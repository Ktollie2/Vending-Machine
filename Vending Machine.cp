//
//  main.cpp
//  Vending Machine
//
//  Created by Kevin Tolliver on 9/15/17.
//  Copyright © 2017 Kevin Tolliver. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Soda {
    string name;
    float cost;
    int number;
};

float totalamount = 0;

void Vendingmachine(Soda *x);
void DisplayChoices(Soda *x);


int main() {
    string answer;
    
    // Initializes the array of the information for each drink including name, price, and amount of sodas
    
    Soda drinks[5] = {"Cola      ",.75, 20, "Root Beer ", .75, 20, "Lemon-Lime", .75, 20, "Grape Soda", .80, 20, "Cream Soda", .80, 20};
    
    // Assigning the array to pointer x
    
    Soda * x;
    x = drinks;
    
   
    /* In this do while loop the choices are displayed then the user is given the option of what drink they want and the option to insert money for the drink. If they don't enter enough money they are given the choice to enter money again. If they enter enough they are given the drink. If they enter more than enough they are given change */
    
    do{
    cout << setprecision(2) << fixed << showpoint;
    DisplayChoices(x);
    Vendingmachine(x);
    
   // If the user wants another drink they can enter Y/y if not they can enter anything else
        
    cout << "Would you like to purchase another drink Y/N? " << endl;
    cin >> answer;
    
    } while(answer == "Y'" || answer == "y");

    
    // The total earnings after the user quits the loop are displayed here
    
    
    cout << "Machine's total earnings $" << totalamount << endl;
   
    
    return 0;
}

void DisplayChoices(Soda *x){
    
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << x[i].name << " $" << x[i].cost << endl;
    }
    
}


void Vendingmachine(Soda *x){
    int choice;
    float amount;
    double change;
    cout << "Please select the drink of your choice: " << endl;
    cin >> choice;
    
    
    switch (choice) {
        case (1):
        
            if(x[choice - 1].number == 0){
                cout << "There are no more of these" << endl;
                break;
            }
            
            do{
            cout << "Please enter the amount of money that you would like to pay: " << endl;
            cin >> amount;
                
            } while(amount < 0 || amount > 1);
            
           
            
            break;
        case (2):
            if(x[choice - 1].number == 0){
                cout << "There are no more of these" << endl;
                break;
            }
            
            
            do{
                cout << "Please enter the amount of money that you would like to pay: " << endl;
                cin >> amount;
            } while (amount < 0 || amount > 1);
            
    
            break;
            
        
        case (3):
            
            
            if(x[choice - 1].number == 0){
                cout << "There are no more of these" << endl;
                break;
            }
            
            do{
                cout << "Please enter the amount of money that you would like to pay: " << endl;
                cin >> amount;
            } while (amount < 0 || amount > 1);
            
       
            break;
        case (4):
            do{
                if(x[choice - 1].number == 0){
                    cout << "There are no more of these" << endl;
                    break;
                }
                
                cout << "Please enter the amount of money that you would like to pay: " << endl;
                cin >> amount;
            } while (amount < 0 || amount > 1);
            
        
            break;
        case (5):
            if(x[choice - 1].number == 0){
                cout << "There are no more of these" << endl;
                break;
            }
            do{
                
                cout << "Please enter the amount of money that you would like to pay: " << endl;
                cin >> amount;
            } while (amount < 0 || amount > 1);
            
           
            break;
            
        default:
            break;
    }
    
   
    if(amount > x[choice - 1].cost){
        change = amount - x[choice - 1].cost;
        cout << "Here is your change "<< change << endl;
        x[choice - 1].number = x[choice - 1].number - 1;
        totalamount = totalamount + x[choice - 1].cost;
        
    }
    
    else if(amount > x[choice - 1].cost){
        cout << "You need to enter " << x[choice - 1].cost - amount << " more cents" << endl;
    }
    
    else if(amount == x[choice - 1].cost){
        cout << "No change" << endl;
        x[choice - 1].number = x[choice - 1].number - 1;
        totalamount = totalamount + x[choice - 1].cost;
    }
}

