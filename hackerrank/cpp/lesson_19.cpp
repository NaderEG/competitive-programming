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
    int pos;
    cin >> pos;
    v.erase(v.begin()+pos-1);
    
    int start_pos, end_pos;
    cin >> start_pos >> end_pos;
    v.erase(v.begin()+start_pos-1, v.begin()+end_pos-1);
    cout << v.size() << "\n";
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
    return 0;
}
