#include <charconv>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    string s_num1 = "-920,4454", s_num2 = "3.654354";

    double num1 = stod(s_num1), num2 = stod(s_num2);

    cout << num1 + num2 << endl;

    return 0;
}