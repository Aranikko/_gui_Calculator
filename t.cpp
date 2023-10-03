#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

    vector<int> v;

    v.push_back(1);

    cout << v[0] << " " << v.size() << endl;

    return 0;

}