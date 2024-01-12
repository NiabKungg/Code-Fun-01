#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

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
            cout << "Word '" << pair.first << "' appears " << pair.second << " times." << endl;
        }
    }
    
    if (!foundDuplicates) {
        cout << "No duplicate words found." << endl;
    }
}

int main() {
    string inputSentence;
    cout << "Enter an English sentence: ";
    getline(cin, inputSentence);
    
    countDuplicateWords(inputSentence);
    
    return 0;
}
