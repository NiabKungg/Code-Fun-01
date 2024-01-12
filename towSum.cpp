#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // nums = [2,7,11,15], target = 9
    vector<int> nuns = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nuns, target);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
