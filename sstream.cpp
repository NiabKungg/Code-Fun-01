#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "Niab 10 5 3.14";
    istringstream iss(str);
    string name;
    int num1, num2;
    float pi;
    iss >> name >> num1 >> num2 >> pi;
    cout << name << num1 + num2 << pi;
    return 0;
}
