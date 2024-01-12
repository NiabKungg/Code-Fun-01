#include <iostream>
using namespace std;

// subtraction-based gcd algorithm
int gcd(int a, int b)
{
    while (a != b)
    {
        //cout << "a = " << a << ", b = " << b << endl;
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int lcm(int n, int m)
{
    int n1 = n, m1 = m;
    while (m1 != n1)
    {
        if (m1 > n1)
            n1 += n;
        else
            m1 += m;
    }
    return m1;
}

int main()
{
    cout << "gcd is " << gcd(7, 4) << " lcm is " << lcm(7, 4) << endl;
    return 0;
}