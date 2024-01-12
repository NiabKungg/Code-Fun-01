#include <iostream>
#include <vector>

using namespace std;

void generateSequences(int n, int m, vector<vector<int>>& sequences, vector<int>& current_sequence, int index) {
    if (index == n) {
        sequences.push_back(current_sequence);
        return;
    }

    for (int x = 0; x <= m; ++x) {
        current_sequence[index] = x;
        generateSequences(n, m, sequences, current_sequence, index + 1);
    }
}

bool check(vector<int>& A, int d, int r)
{
    int plus = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        plus += A[i];
    }
    return (plus % d) == r ? true : false;
}

int main() {
    int n, m, d, r, count = 0;
    cin >> n >> m >> d >> r;

    vector<vector<int>> sequences;
    vector<int> current_sequence(n);

    generateSequences(n, m, sequences, current_sequence, 0);

    /*for (size_t i = 0; i < sequences.size(); i++)
    {
        if (check(sequences[i], d, r))
        {
            count ++;
        }
        
    }*/
    for (size_t i = 0; i < sequences.size(); i++)
    {
        for (size_t j = 0; j < sequences[0].size(); j++)
        {
            cout << sequences[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}