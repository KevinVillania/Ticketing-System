/*
================================================
BUS TICKETING SYSTEM
BY: Kevin Holden Villania
written in C++, with input validation and fare
depends on distance of destination
================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//Make a print function iterator, and add function iterator
//Add computation of fare matrix and student, senior citizen discount

//included lists of destination, input validation, ind. ticket cost

double discount, discountedPrice;
int ticketPrice, totalPrice, location, numPeople, age;
vector <int> groupAge;

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

    cout << "Enter age of each person:" << endl;

    //Iterator to input age of people depending on the number of participant
    for(int i=1; i<=numPeople; ++i){

        while(!(cin>>age)|| (age < 1 || age > 100)){
            cout << "Error input" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }

        groupAge.push_back(age);
    }

    //trial for shorter code for getting least age value
    //same code function
    sort(groupAge.begin(), groupAge.end());
    //int leastAge = *min_element(groupAge.begin(),groupAge.end());

    //Prints sorted list
    cout << "Sorted age list is [ ";
    for(int i=0; i<=groupAge.size()-1; ++i){

        cout << groupAge[i] << " ";
    }

    cout << "] \n";


    //int numberOfPeople = groupAge.size();
    cout << "Number of people "<< numPeople << endl;

    cout << endl;

    if(numPeople >= 5){

        //execute discount computation, least age basis for discount percentage
        cout << "You are eligible for discounted price!" << endl << endl;

        //Gets the age of the youngest person to be used as a discount percentage.
        discount = 1.0-((groupAge[0]+.0)/100);
        //cout << discount << endl; just a checker

        discountedPrice = (numPeople*destination_map[location])*discount;

        cout << "Individual ticket cost: Php " << discountedPrice/numPeople << endl;
        cout << "Total discounted price is equal to " << discountedPrice << " pesos" << endl;

    }

    else{

        totalPrice = numPeople*destination_map[location];
        cout << "You need to be group of five (5) in order to avail the discount" << endl << endl;
        cout << "From: Main Terminal" << endl;
        cout << "To: " << location_map[destination_map[location]] << endl;
        cout << "Individual ticket cost: Php " << totalPrice/numPeople << endl;
        cout << "Standard pricing applies: " << numPeople*destination_map[location] << " pesos" << endl;
    }

    cout << endl;
    cout << "==============================================" << endl;
    cout << "THANK YOU FOR RIDING WITH SOLID NORTH BUS CORP" << endl;
}


