// Problem 3

#include <iostream>
#include <vector>

using namespace std;

//หาค่า  Determinant ของ Matrix
double det_A(vector<vector<double>>& A)
{
    //   A
    //[00, 01]
    //[10, 11]
    return A[0][0] * A[1][1] + A[1][0] * A[0][1] * -1;
}

//หาค่า  Determinant ของ Matrix ทีมีการนำ B มาแทนที่สมาชิคใน A
double det_A_n(vector<vector<double>>& A,vector<vector<double>>& B, int n)
{
    //   A      B
    //[00, 01] [00]
    //[10, 11] [01]
    if (n == 1)
    {
        return B[0][0] * A[1][1] + B[1][0] * A[0][1] * -1;
    }
    else if (n == 2)
    {
        return A[0][0] * B[1][0] + A[1][0] * B[0][0] * -1;
    }
    
}

int main(int argc, char const *argv[])
{
    double a, b, c, d, m, n;
    cout << "ax + by = m\ncx + dy  = n\n";
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "m = "; cin >> m;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;
    cout << "n = "; cin >> n;

    vector<vector<double>> A = { { a, b }, { c, d } }; //Matrix 2x2
    vector<vector<double>> B = { { m }, { n } }; // Matrix 1x2

    // หาคำตอบตามสูตร 
    // x = detA1 / detA
    // y = detA2 / detA
    cout << "\n(" << det_A_n(A, B, 1) / det_A(A) << ", " << det_A_n(A, B, 2) / det_A(A) << ")\n";
    return 0;
}