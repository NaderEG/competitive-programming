#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string, int> m;
    int num_queries;
    cin >> num_queries;
    for (int i = 0; i < num_queries; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            string student;
            int grade;
            cin >> student >> grade;
            map<string,int>::iterator itr=m.find(student);
            if (itr == m.end()) {
                m.insert(make_pair(student, grade));
            } else {
                m[student] = m[student] + grade;
            }
            
        } else if (query == 2) {
            string student;
            cin >> student;
            m.erase(student);
        } else {
            string student;
            cin >> student;
            map<string,int>::iterator itr=m.find(student);
            if (itr != m.end()) {
                cout << m[student] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
