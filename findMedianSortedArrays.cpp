#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> combined;

    combined.reserve(nums1.size() + nums2.size());
    combined.insert(combined.end(), nums1.begin(), nums1.end());
    combined.insert(combined.end(), nums2.begin(), nums2.end());

    sort(combined.begin(), combined.end());

    int mid = combined.size() / 2;

    if (combined.size() % 2 == 0)
    {
        return static_cast<double>(combined[mid - 1] + combined[mid]) / 2.0;
    }
    else
    {
        return static_cast<double>(combined[mid]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}
