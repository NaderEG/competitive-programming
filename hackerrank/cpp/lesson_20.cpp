#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num_elems;
    cin >> num_elems;
    vector<int> v;
    for (int i = 0; i < num_elems; i++) {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }
    int num_queries;
    cin >> num_queries;
    
    for (int j = 0; j < num_queries; j++) {
        int num;
        cin >> num;
        vector<int>::iterator low; 
        low = lower_bound(v.begin(), v.end(), num);
        if (v[(low - v.begin())] == num) {
            cout << "Yes " << (low - v.begin())+1 << "\n";
        } else {
            cout << "No " << (low - v.begin())+1 << "\n";
        }
    }
    return 0;
}
