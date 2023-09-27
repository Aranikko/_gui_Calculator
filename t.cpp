#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> arr;

    string s;

    while (true) {
        cin >> s;

        arr.push_back(s);

        if (s == "=") {
            break;
        }
    }

    // Display the elements in the vector before removal
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Remove the second element from the vector
    if (arr.size() >= 2) {
        arr.erase(arr.begin() + 1);
    }

    // Display the modified vector after removal
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
