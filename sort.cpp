#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<double> nums = {3, 4, 2, 1};
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
