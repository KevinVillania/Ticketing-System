#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

Class::Class()
{

}

int Class::destination(char location){

    switch(location){

        case'Manila'||'manila':
            ticketPrice = 15;
            return 10;


        case'Quezon city'||'Quezon City':
            ticketPrice = 20;
            return 10;

    }

}
