#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};
    
    // Remove the last element
    myVector.pop_back();
    
    // Display the modified vector
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
