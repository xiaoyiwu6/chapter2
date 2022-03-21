#include <iostream>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto beg = ivec.begin(), end = ivec.end();
    auto mid = ivec.begin() + (end - beg) / 2;
    int sought;
    cin>>sought;
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    cout << *mid << endl;

    return 0;
}
