#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    vector<char> seats(9, '-');

    istringstream iss(input);
    char action;
    while (iss >> action) {
        if (action >= '0' && action <= '9') {
            int seat = action - '0';
            seats[seat - 1] = '1';
        } else if (action == '-') {
            iss >> action;
            int seat = action - '0';
            seats[seat - 1] = '-';
        }
    }

    
    for (char seatStatus : seats) {
        cout << seatStatus << " ";
    }

    return 0;
}
