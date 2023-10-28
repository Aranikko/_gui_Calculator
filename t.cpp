#include <charconv>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    string num1 = "1";
    string num2 = "1";

    float numFloat = static_cast<float>(stod(num1)) / static_cast<float>(stoi(num2));

    cout << to_char(numFloat) << endl;

    return 0;
}