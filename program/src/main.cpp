#include <iostream>
#include "Hotel.h"

using namespace std;

int main() {
    Hotel hotel("Grand Hotel", 5);
    cout << "Welcom in " << hotel.GetName() << " (";
    for(int i = 0; i < hotel.GetStarsAmount(); i++)
        cout << "*";
    cout << ")" << endl;
    
    cout << endl;
    return 0;
}