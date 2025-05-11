#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    
    for(int j = size -1; j >= 0; j--) {
        printf("%d", arr[j]);
        printf(" ");
    }
    return 0;
}
