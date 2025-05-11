#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int greatest_of_four(int a, int b, int c, int d) {
    int nums[4] = {a, b, c, d};
    int max = a;
    for (int i = 0; i < 4; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a;
    int b;
    int c;
    int d;
    scanf("%d", &a);
    scanf("%d", &b);  
    scanf("%d", &c);
    scanf("%d", &d);
    printf("%d", greatest_of_four(a, b, c, d));   
    return 0;
}

