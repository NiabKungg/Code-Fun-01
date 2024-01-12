#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> plusMatrix(vector<vector<int>>& A, vector<vector<int>>& B)
{
    vector<vector<int>> result(A.size(), vector<int>(A[0].size(), 0));
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[0].size(); j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

double detMatrix(vector<vector<double>>& matrix)
{
    return matrix[0][0] * matrix[1][1] + (matrix[0][1] * matrix[1][0]) * -1;
}

vector<vector<double>> inverseMatrix(vector<vector<double>>& matrix)
{
    double detA = 1.0/detMatrix(matrix);
    vector<vector<double>> result = { { detA * matrix[1][1], detA * matrix[0][1] * -1 }, { detA * matrix[1][0] * -1, detA * matrix[0][0] } };
    return result;
}

vector<vector<double>> multiplyMatrix(vector<vector<double>>& matrix1, vector<vector<double>>& matrix2)
{
    int rowM1 = matrix1.size(),
        columnM1 = matrix1[0].size(),
        columnM2 = matrix2[0].size();
    vector<vector<double>> result(rowM1, vector<double>(columnM2));
    for (int i = 0; i < rowM1; i++)
    {
        for (int j = 0; j < columnM2; j++)
        {
            for (int k = 0; k < columnM1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
    
}

/*
    ax + by = m \n
    cx + dy  = n   
*/

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

    vector<vector<double>> A = { { a, b }, { c, d } };
    vector<vector<double>> B = { { m }, { n } };
    vector<vector<double>> A_inverse = inverseMatrix(A);
    vector<vector<double>> result = multiplyMatrix(A_inverse, B);
    cout << "\n(" << result[0][0] << ", " << result[1][0] << ")\n";
    return 0;
}