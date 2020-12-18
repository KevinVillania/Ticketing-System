/*
================================================
BUS TICKETING SYSTEM
BY: Kevin Holden Villania
written in C++, with input validation and fare
depends on distance of destination
FIRST BRANCH
================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

//Make a print function iterator, and add function iterator
//Add computation of fare matrix and student, senior citizen discount
//BUGS: UNABLE TO PUSH BACK ON VECTOR NAME, FARE,

//included lists of destination, input validation, ind. ticket cost

double discountedPrice;
int totalPrice, location, numPeople, age;
string name;
char twentyDiscount;

vector<int> groupAge;
vector<double> fare;
vector<string> name1;

int userInput();

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

    //cout << destination_map[location]; fare checker
    //prints destination array
    for(int i=0; i<=3; ++i){
        cout << i+1 << " =" << " Php " << destination_map[i+1] << " ===== " << destination[i] << endl;
    }

    // Checks if input is in the range of 1-4
    //cin >> location;
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

    //Iterator to input age of people depending on the number of participant
    for(int i=0; i<=numPeople; ++i){
        userInput();
    }

    cout << "Passenger details" << endl;
    cout << "From: Main Terminal" << endl;
    cout << "To: " << location_map[destination_map[location]] << endl;


    cout << "Total ticket price: " << totalPrice << "pesos\n";
    cout << endl;
    cout << "==============================================" << endl;
    cout << "THANK YOU FOR RIDING WITH SOLID NORTH BUS CORP" << endl;
}

int userInput(){

    double discountedPrice;
    int totalPrice, location, numPeople, age;
    char twentyDiscount;
    string name;

    vector<int> groupAge;
    vector<double> fare;
    vector<string> name1;

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


    cout << "Enter name of passenger: ";
    getline(cin, name);

    name1.push_back(name);



    cout << "Enter age: ";
    while(!(cin>>age)||(age < 1 || age > 99)){

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter age: ";
    }
    groupAge.push_back(age);

    cout << "With discount? Y/N" << endl;
    while(!(cin>>twentyDiscount)||(twentyDiscount != 'Y' && twentyDiscount!='N')){

        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Y/N? ";
    }
    if (twentyDiscount == 'Y'){
        discountedPrice= 5;
        fare.push_back(discountedPrice);
    }
    else{

        discountedPrice = 1;
        fare.push_back(discountedPrice);
    }


}


