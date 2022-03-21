#include <iostream>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    decltype(ivec.size()) size_ivec = 0;
    vector<int>::size_type size_ivec2 = 0;
    auto size_ivec3 = ivec.size();

    for (auto &i : ivec)
        i *= i;

    for (auto i : ivec)
        cout << i << endl;

    //    for (decltype(ivec.size()) index = 0; index < ivec.size(); index++)
    //        cout << ivec[index] << endl;
    return 0;
}
