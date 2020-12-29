/*==========================================================
BUS TICKETING SYSTEM
BY: Kevin Holden Villania
Written in C++

Bus ticketing system with input validation and fare
depends on distance of destination, grants 20% discount
for student and senior citizen.

Implemented using for, while loops for iteration
maps and vectors for dynamic array and storage.

First project in C++ 12/29/2020
FIRST BRANCH
=============================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

double discountedPrice, totalPrice = 0;
int location, numPeople, age;
string name;
char twentyDiscount;
vector<int> groupAge;
vector<double> fare;
vector<string> name1;

int main()
{
    //map of fare matrix
    map<int, int> destination_map;
    destination_map[1] = 15;
    destination_map[2] = 20;
    destination_map[3] = 25;
    destination_map[4] = 10;

    //map of destination
    map<int, string> location_map;
    location_map[15] = "Manila";
    location_map[20] = "Quezon City";
    location_map[25] = "Marikina";
    location_map[10] = "Minimum Distance";


    cout << "WELCOME TO SOLID NORTH BUS STATION" << endl;
    cout << "_________________________________" << endl << endl;

    string destination[]{"Manila","Quezon City","Marikina","Standard Fare"};
    cout << "Select destination" << endl;

    //prints destination array
    for(int i=0; i<=3; ++i){
        cout << i+1 << " =" << " Php " << destination_map[i+1] << " ===== " << destination[i] << endl;
    }

    // Checks if input is in the range of 1-4
    while(!(cin >> location) || (location < 1 || location > 4)){

        cout << "Number not in range: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter number of people: ";
    //Input validation, numPeople should be integer
    while(!(cin >> numPeople)|| (numPeople < 1 || numPeople > 20)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, number not in range" << endl << "Enter a number: ";
    }
    cout << endl;

    //Iterates depending on number of passenger
    for(int i=1; i <= numPeople; ++i){

        cout << "Passenger " << i << endl;

        //Gets passenger name and push it back to vector 'name1'
        cout << "Enter name of passenger: ";
        cin.ignore(); //clears previous cin
        getline(cin, name);
        name1.push_back(name);


        //Gets passenger age and push it back to vector 'groupAge'
        //Input validation if age is within range of 1-99
        cout << "Age: ";
        while(!(cin>>age)||(age < 1 || age > 99)){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter age: ";
        }
        groupAge.push_back(age);


        //Asks user if discount is applicable for the passenger Y for Yes and N for No
        //Input validation if user inputs Y or N
        cout << "With discount? Y/N: ";
        while(!(cin>>twentyDiscount)||(twentyDiscount != 'Y' && twentyDiscount!='N')){

            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Y/N? ";
        }
        if (twentyDiscount == 'Y'){
            discountedPrice = destination_map[location] * 0.8;
            fare.push_back(discountedPrice);
        }
        else{

            discountedPrice = destination_map[location];
            fare.push_back(discountedPrice);
        }
        cout << endl;
    }

    //gets total price of tickets
    for(int i=1; i<= fare.size(); ++i){
        totalPrice += fare[i-1];
    }

    //PRINTS PASSENGER TICKET DETAILS
    cout << "==============================================\n";
    cout << "                Ticket details" << endl;
    cout << "==============================================\n\n";
    cout << "From: Main Terminal" << endl;
    cout << "To: " << location_map[destination_map[location]] << endl; //gets destination by referencing on destination hash map
    cout << "Total ticket price: " << totalPrice << " pesos\n";

    //Iterates and prints each passenger detail
    //prints each element in vector 'name1' and 'groupAge'
    for(int i=1; i <= numPeople; ++i){

        cout << "\nPassenger " << i << endl;
        cout << "Name: "<< name1[i-1] << "\n";
        cout << "Age: " << groupAge[i-1] << "\n";
        cout << "Ticket Price: " << fare[i-1] << " pesos" << "\n";
    }
    cout << endl;
    cout << "==============================================" << endl;
    cout << "THANK YOU FOR RIDING WITH SOLID NORTH BUS CORP" << endl;
}
