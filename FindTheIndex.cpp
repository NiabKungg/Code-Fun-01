#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{
    size_t found = haystack.find(needle);
    if (found != string::npos)
    {
        return found;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    cout << strStr("gggHellodsds", "aaaaa");
    return 0;
}
