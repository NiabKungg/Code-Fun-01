// marcuscode.com/lang/cpp/files
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream myfile;
    string line, newTxt;
    int charType = 0, newLine = 0, charDigit = 0, charAlpha = 0, charSpecial = 0, charUnknow = 0;
    myfile.open("example.txt");
    while (getline(myfile, line))
    {
        newTxt += line;
        newTxt += '\n';
    }
    if (!newTxt.empty())
    {
        newTxt.pop_back(); // ลบ '\n' ตัวตัวสุดท้าย
    }
    // cout << newTxt << endl << newTxt.size();
    for (size_t i = 0; i < newTxt.size(); i++)  
    {
        char ch = newTxt[i];
        if (ch == ' ' or ch == '\n' or ch == '\0'){
            if (ch == '\n')
            {
                newLine++;
            }
            
            continue;
        }
        if (isdigit(ch))
        {
            charDigit ++;
        }
        else if (isupper(ch))
        {
            charAlpha ++;
        }
        else if (islower(ch))
        {
            charAlpha ++;
        }
        else if (ispunct(ch) || isspace(ch))
        {
            charSpecial ++;
        }
        else
        {
            charUnknow ++;
        }
    }
    if (charDigit != 0)
    {
        charType ++;
    }
    if (charAlpha != 0)
    {
        charType ++;
    }
    if (charSpecial != 0)
    {
        charType ++;
    }
    cout << "charType = " << charType << endl;
    cout << "Line = " << newLine+1 << endl;
    cout << "charDigit = " << charDigit << endl;
    cout << "charAlpha = " << charAlpha << endl;
    cout << "charSpecial = " << charSpecial << endl;
    cout << "charUnknow = " << charUnknow << endl;
    
    myfile.close();
    return 0;
}
