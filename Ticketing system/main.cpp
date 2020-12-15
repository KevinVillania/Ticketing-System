#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//Make a print function iterator, and add function iterator
//included lists of destination
//PROBLEM: CODE GETTING MESSY AND LONG


double discount, discountedPrice;
int numPeople, age;
int location;
int ticketPrice;
vector <int> groupAge;

int main()
{

    map<int, int> destination_map;

    destination_map[1] = 15;
    destination_map[2] = 20;
    destination_map[3] = 25;
    destination_map[4] = 10;


    cout << "WELCOME TO MALUPET BUS STATION" << endl;
    cout << "_________________________________" << endl << endl;

    string destination[4] = {"Manila","Quezon City","Marikina","Standard Fare"};
    cout << "Select destination" << endl;
    for(int i=0; i<=3; ++i){

        cout << i+1 << " ===== " << destination[i] << endl;
    }
    cin >> location;

    //cout << destination_map[location];

    cout << "Enter number of people: ";
    cin >> numPeople;

    cout << "Enter age of each person: " << endl;

    //Iterator to input age of people depending on the number of participant
    for(int i=1; i<=numPeople; ++i){

        cin >> age;
        groupAge.push_back(age);
    }

    //trial for shorter code for getting least age value
    //same code function
    sort(groupAge.begin(), groupAge.end());
    //int leastAge = *min_element(groupAge.begin(),groupAge.end());

    //Prints sorted list
    cout << "Sorted age list is ";
    for(int i=0; i<=groupAge.size()-1; ++i){

        cout << groupAge[i] << " ";
    }

    cout << "\n";


    //int numberOfPeople = groupAge.size();
    cout << "Number of people "<< numPeople << endl;

    if(numPeople >= 5){

        //execute discount computation, least age basis for discount percentage
        cout << "You are eligible for discounted price!" << endl << endl;

        //Gets the age of the youngest person to be used as a discount percentage.
        discount = 1.0-((groupAge[0]+.0)/100);
        //cout << discount << endl; just a checker


        discountedPrice = (numPeople*destination_map[location])*discount;

        cout << "Total discounted price is equal to " << setprecision(5) << discountedPrice << " dollars" << endl;

    }

    else{
        cout << "You need to be group of five (5) in order to avail the discount" << endl << endl;

        cout << "Standard pricing applies: " << numPeople*destination_map[location] << " dollars" << endl;
    }
}


