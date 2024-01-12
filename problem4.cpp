// Problem 4

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    //เก็บค่าไว้ในตัวแปร vector<vector<double>> ก็คือ Array2d นั่นเหละ
    vector<vector<double>> nums(n, vector<double>(2));
    for (size_t i = 0; i < nums.size(); i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }
    cout << endl;

    //คำนวณ ระยะห่างตามสูตร
    vector<double> distance;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i+1; j < nums.size(); j++)
        {
            distance.push_back(pow(nums[i][0] - nums[j][0], 2) + pow(nums[i][1] - nums[j][1], 2));
        }
    }

    // จัดเรียงจากน้อยไปมาก
    sort(distance.begin(), distance.end());

    // แสดงผลตัวแรก (คือตัวน้อยสุด)
    cout << distance[0];

    return 0;
}
