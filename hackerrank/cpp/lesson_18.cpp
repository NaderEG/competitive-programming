#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int num_elements;
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < num_elements; j++) {
        cout << v[j] << " ";
    }
    return 0;
}
