#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int currValue = romanMap[s[i]];
        if (currValue < prevValue) {
            result -= currValue;
        } else {
            result += currValue;
        }
        prevValue = currValue;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    cout << intToRoman(1993) << endl;
    cout << romanToInt(intToRoman(1993));
    return 0;
}
