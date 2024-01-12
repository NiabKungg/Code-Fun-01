// Problem 1

#include <iostream>
#include <vector>

using namespace std;

//ฟังก์ชั่นสร้างลำดับจำนวน x1, x2, ... xm
void generateSequences(int n, int m, vector<vector<int>>& sequences, vector<int>& current_sequence, int index) {
    if (index == n) {
        sequences.push_back(current_sequence);
        return;
    }

    for (int x = 1; x <= m; ++x) {
        current_sequence[index] = x;
        generateSequences(n, m, sequences, current_sequence, index + 1);
    }
}

//ฟังก์ชั่นเช็คเงื่อนไขตามโจทย์
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

    vector<vector<int>> sequences; // vector<vector<int>> ก็คือ array 2d แค่เอาไปใช้ในฟังก์ชั่นง่ายกว่า
    vector<int> current_sequence(n); // vector<int> คือ array มิติเดียว

    //สร้างลำดับแล้วใส่ค่าเข้าไปตัวแปร sequences
    generateSequences(n, m, sequences, current_sequence, 0);

    for (size_t i = 0; i < sequences.size(); i++)
    {
        // เช็ค แล้ว นับ +1
        if (check(sequences[i], d, r))
        {
            count ++;
        }
        
    }
    //แสดงผล
    cout << count;
    return 0;
}