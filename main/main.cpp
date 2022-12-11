#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
void sortKeys(int keyArr[], string nameArr[], int n) { // uses insertion sort
    string keyName;
    int key;
    for (int i = 1; i < n; i++) {
        keyName = nameArr[i];
        key = keyArr[i];
        int j = i - 1;
        while (j >= 0 && nameArr[keyArr[j]] > keyName) {
            keyArr[j + 1] = keyArr[j];
            j = j - 1;
        }
        keyArr[j + 1] = key;
    }
}
string getName() {
    string name;
    cout << "Name: ";
    getline(cin >> ws, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    return name;
}
int getAge() {
    int age;
    while (1) {
        cout << "Age: ";
        cin >> age;
        if (!cin) {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            cout << "Invalid response, try again...\n";
            continue;
        }
        if (age < 0) {
            cout << "Age can't be negative, try again...\n";
            continue;
        }
        return age;
    }
}
string getCondition() {
    string condition;
    while (1) {
        cout << "Condition (A, D, I or M): ";
        getline(cin >> ws, condition);
        if (condition == "a" || condition == "A") {
            return "ALIVE";
        }
        if (condition == "d" || condition == "D") {
            return "DECEASED";
        }
        if (condition == "i" || condition == "I") {
            return "INJURED";
        }
        if (condition == "m" || condition == "M") {
            return "MISSING";
        }
        cout << "Invalid response, try again...\n";
    }
}
char getMore() {
    string more;
    while (1) {
        cout << "More Entry (Y/N)? ";
        getline(cin >> ws, more);
        if (more == "y" || more == "Y") {
            return 1;
        }
        if (more == "n" || more == "N") {
            return 0;
        }
        cout << "Invalid response, try again...\n";
    }
}
int getEstimatedNumber() {
    int estimatedResidents;
    while (1) {
        int estimatedResidents;
        cout << "Estimated number of residents: ";
        cin >> estimatedResidents;
        if (!cin) {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            cout << "Invalid response, try again...\n";
            continue;
        }
        if (estimatedResidents < 1) {
            cout << "Number can't be negative or 0, try again...\n";
            continue;
        }
        return estimatedResidents;
    }
}
string getBName() {
    string barangayName;
    cout << "Name of barangay: ";
    getline(cin >> ws, barangayName);
    return barangayName;
}
int main() {
    string barangayName = getBName();
    int estimatedResidents = getEstimatedNumber();
    cout << "\n";

    string name[estimatedResidents];
    int age[estimatedResidents];
    string condition[estimatedResidents];
    int sort[estimatedResidents];

    for (int i = 0; i < estimatedResidents; i++) {
        sort[i] = -1;
    }

    int totalVictims = 0;
    int totalAlive = 0;
    int totalDeceased = 0;
    int totalInjured = 0;
    int totalMissing = 0;
    for (int i = 0; i < estimatedResidents; i++) {
        name[i] = getName();
        age[i] = getAge();
        condition[i] = getCondition();
        sort[i] = i;
        totalVictims++;
        if (condition[i] == "ALIVE") {
            totalAlive++;
        }
        if (condition[i] == "DECEASED") {
            totalDeceased++;
        }
        if (condition[i] == "INJURED") {
            totalInjured++;
        }
        if (condition[i] == "MISSING") {
            totalMissing++;
        }
        cout << "\n";
        if (!getMore()) {
            cout << "\n";
            break;
        }
        cout << "\n";
    }

    // sort keys of the data
    sortKeys(sort, name, totalVictims);

    // display sorted list
    cout << left << setw(20) << "NAME" << setw(10) << "AGE" << setw(10) << "CONDITION" << endl;
    for (int i = 0; i < totalVictims; i++) {
        cout << left << setw(20) << name[sort[i]] << setw(10) << age[sort[i]] << setw(10) << condition[sort[i]] << endl;
    }
    cout << endl;

    // display summary
    cout << "Total # of victims: " << totalVictims << endl;
    cout << right << setw(15) << "Alive: " << setprecision(2) << fixed << ((totalAlive * 100.0) / (totalVictims * 1.0)) << "%" << endl;
    cout << right << setw(15) << "Deceased: " << setprecision(2) << fixed << ((totalDeceased * 100.0) / (totalVictims * 1.0)) << "%" << endl;
    cout << right << setw(15) << "Injured: " << setprecision(2) << fixed << ((totalInjured * 100.0) / (totalVictims * 1.0)) << "%" << endl;
    cout << right << setw(15) << "Missing: " << setprecision(2) << fixed << ((totalMissing * 100.0) / (totalVictims * 1.0)) << "%" << endl;


    return 0;
}
