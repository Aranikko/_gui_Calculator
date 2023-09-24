#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n, k, sum = 0;
    string YN;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    n = 0;
    cout << "Like add anotrher num" << endl;
    cin >> YN;
    if (YN == "Y") {
        int temp = n;
        cin >> k;
        arr[n++] = k;
        for (int i = temp; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
    }
    
    cout << endl;

    for(int i = 0; i < k+n; i++)
        cout << arr[i] << " ";

    return 0;
}