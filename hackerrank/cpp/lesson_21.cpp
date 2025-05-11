#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int num_queries;
    cin >> num_queries;
    set<int> s;
    for (int i = 0; i < num_queries; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (query == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else {
            int x;
            cin >> x;
            set<int>::iterator itr=s.find(x);
            if (itr == s.end()) {
                cout << "No" << "\n";
            } else {
                cout << "Yes" << "\n";
            }
        }
    }
    return 0;
}



