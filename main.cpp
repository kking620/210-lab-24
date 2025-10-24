#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    list<Goat> trip;
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    
    while(true){
        int choice = main_menu();

        if (choice < 1 || choice > 4)
        cout << "Invalid input";

        if(choice == 1)
            add_goat(trip, names, colors);
        if(choice == 2)
            delete_goat(trip);
        if(choice == 3)
            display_trip(trip);
        if(choice == 4)
            break;

            cout << endl;
    }

    return 0;
}

int main_menu() {
    int c;
    
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice -->";
    cin >> c;
        
    return c;
}

int select_goat(list<Goat> trip) {
    int c;
    cout << "Enter the number of the goat you wish to choose: ";
    cin >> c;

    return c;
}

void display_trip(list<Goat> trip){
    cout << endl;
    
    if (trip.empty()) {
        cout << "No goats on this trip.\n";
        return;
    }
    cout << "Goats On Current Trip:\n";
    int i = 1;
    for (auto &goat : trip){
        cout << "[" << i++ << "] ";
        cout << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")";
        cout << endl;
    }
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % MAX_AGE + 1;
    trip.push_back(Goat(name, age, color));
}

void delete_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats on this trip.\n";
        return;
    }

    display_trip(trip);
    int c = select_goat(trip);

    if (c < 1 || c > trip.size()) {
        cout << "Invalid goat selection.\n";
        return;
    }
    else if (c >= 1 && c <= trip.size()){
        auto it = trip.begin();
        advance(it, c-1);
        trip.erase(it);
    }
}

