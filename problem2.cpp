// Problem 2

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

//ฟังก์ชั่นนับคำซ้ำ ChatGPT ตึงๆ
//คือการหาคำซ้ำจากประโชค
void countDuplicateWords(const string& sentence) {
    unordered_map<string, int> wordCount;
    
    istringstream iss(sentence);
    string word;
    
    while (iss >> word) {
        // Remove any punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        
        // Convert to lowercase for case-insensitive comparison
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        // Update word count
        wordCount[word]++;
    }
    
    bool foundDuplicates = false;
    
    // Check for duplicate words
    for (const auto& pair : wordCount) {
        if (pair.second > 1) {
            foundDuplicates = true;
            cout << "Word '" << pair.first << "' appears " << pair.second - 1 << " times." << endl;
        }
    }
    
    if (!foundDuplicates) {
        cout << "No duplicate words found." << endl;
    }
}

int main(int argc, char const *argv[])
{
    int digit = 0, alpha = 0, special = 0, line_c = 0, can_t_identify = 0;

    // ตัวแปรนับน่ามีรูปแบบตัวอีกษรกี่ตัวแล้ว
    bool type[3] = { false, false, false };

    //กล่าวถึงไฟล์ .txt
    ifstream myfile;
    string line, newStr;
    myfile.open ("example.txt");

    //เก็บทุกตัวไว้ในตัวแปร string
    while (getline(myfile, line))
    {
        newStr += line + '\n';
    }
    
    //มากมีข้อความ ลบ '\n' ตัวสุดท้ายออก
    //ถ้าไม่มี จบโปรแกรม
    if (!newStr.empty()) {
        line_c ++;
        newStr.pop_back();
    }else{
        cout << "message not found";
        return 0;
    }

    //เช็คทีละตัวอักษร
    for (size_t i = 0; i < newStr.size(); i++)
    {
        if (newStr[i] == ' ' || newStr[i] == '\n' || newStr[i] == '\0')
        {
            if (newStr[i] == '\n')
            {
                line_c ++;
            }
            continue;
        }
        if (isdigit(newStr[i]))
        {
            type[0] = true;
            digit ++;
        }
        else if (isalpha(newStr[i]))
        {
            type[1] = true;
            alpha ++;
        }
        else if (ispunct(newStr[i]))
        {
            type[2] = true;
            special ++;
        }
        else
        {
            can_t_identify ++;
        }
    }

    //นับ type
    int type_c = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if(type[i])
        {
            type_c ++;
        }
    }
    
    // แสดงผล
    cout << "Number of Data type : " << type_c << endl;
    cout << "Number of line : " << line_c << endl;
    cout << "Alphabet : " << alpha << endl;
    cout << "Number : " << digit << endl;
    cout << "Special characters : " << special << endl << endl;
    countDuplicateWords(newStr);

    //ปิดไฟล์ .txt ที่เปิด
    myfile.close();
    return 0;
}
