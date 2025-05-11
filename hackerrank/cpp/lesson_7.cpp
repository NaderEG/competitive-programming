#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num_qs;
    int size;
    scanf("%d", &size);
    scanf("%d", &num_qs);
    std::vector<int> arr[size];
    for (int i = 0; i < size; i++) {
        int vec_size;
        scanf("%d", &vec_size);
        for (int j = 0; j < vec_size; j++) {
            int num;
            scanf("%d", &num);
            arr[i].push_back(num);
        }
    }
    for (int j = 0; j < num_qs; j++) {
        int a;
        int b;
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d", arr[a][b]);
        printf("\n");
    }
    return 0;
}