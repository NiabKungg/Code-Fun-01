#include <iostream>
#include <vector>
using namespace std;



double det_3_3(vector<vector<double>>& A)
{
    /*
        [00, 01, 02] 00 01
        [10, 11, 12] 10 11
        [20, 21, 22] 20 21
    */
    double a = ( A[0][0] * A[1][1] * A[2][2] ) + ( A[0][1] * A[1][2] * A[2][0] ) + ( A[0][2] * A[1][0] * A[2][1] );
    double b = ( A[2][0] * A[1][1] * A[0][2] * -1 ) + ( A[2][1] * A[1][2] * A[0][0] * -1 ) + ( A[2][2] * A[1][0] * A[0][1] * -1 );
    return a + b;
}

double det_n_3_3(vector<vector<double>>& A, int n, vector<vector<double>>& B)
{
    double a, b;
    /*
        [00, 01, 02] 00 01
        [10, 11, 12] 10 11
        [20, 21, 22] 20 21
    */
    switch(n){
        case 1:
            a = ( B[0][0] * A[1][1] * A[2][2] ) + ( A[0][1] * A[1][2] * B[2][0] ) + ( A[0][2] * B[1][0] * A[2][1] );
            b = ( B[2][0] * A[1][1] * A[0][2] * -1 ) + ( A[2][1] * A[1][2] * B[0][0] * -1 ) + ( A[2][2] * B[1][0] * A[0][1] * -1 );
            break;
        case 2:
            a = ( A[0][0] * B[1][0] * A[2][2] ) + ( B[0][0] * A[1][2] * A[2][0] ) + ( A[0][2] * A[1][0] * B[2][0] );
            b = ( A[2][0] * B[1][0] * A[0][2] * -1 ) + ( B[2][0] * A[1][2] * A[0][0] * -1 ) + ( A[2][2] * A[1][0] * B[0][0] * -1 );
            break;
        case 3:
            a = ( A[0][0] * A[1][1] * B[2][0] ) + ( A[0][1] * B[1][0] * A[2][0] ) + ( B[0][0] * A[1][0] * A[2][1] );
            b = ( A[2][0] * A[1][1] * B[0][0] * -1 ) + ( A[2][1] * B[1][0] * A[0][0] * -1 ) + ( B[2][0] * A[1][0] * A[0][1] * -1 );
            break;
    }
    return a + b;
}

int main(int argc, char const *argv[])
{
    cout << " a1x + b1y + c1z = m1\n a2x + b2y + c2z = m2\n a3x + b3y + c3z = m3\n\n";
    double a1, a2, a3, b1, b2, b3, c1, c2, c3, m1, m2, m3;
    cout << " a1 : "; cin >> a1;
    cout << " b1 : "; cin >> b1;
    cout << " c1 : "; cin >> c1;
    cout << " m1 : "; cin >> m1;
    cout << " a2 : "; cin >> a2;
    cout << " b2 : "; cin >> b2;
    cout << " c2 : "; cin >> c2;
    cout << " m2 : "; cin >> m2;
    cout << " a3 : "; cin >> a3;
    cout << " b3 : "; cin >> b3;
    cout << " c3 : "; cin >> c3;
    cout << " m3 : "; cin >> m3;
    //    x = detA1 / detA || y = detA2 / detA || z = detA3 / detA
    vector<vector<double>> A = { { a1, b1, c1 }, { a2, b2, c2 }, { a3, b3, c3 } };
    vector<vector<double>> B = { { m1 }, { m2 }, { m3 } };
    //vector<vector<double>> A = { { 1, 2, 1 }, { 3, 1, -2 }, { 2, -3, -3 } };
    //vector<vector<double>> B = { { 0 }, { 5 }, { 9 } };
    cout << "\n\n ( " << det_n_3_3(A, 1, B)/ det_3_3(A) << ", " << det_n_3_3(A, 2, B)/ det_3_3(A) << ", " << det_n_3_3(A, 3, B)/ det_3_3(A) << " )";
    return 0;
}

