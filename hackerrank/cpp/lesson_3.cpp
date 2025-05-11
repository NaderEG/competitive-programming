#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    for (int i = a; i <= b; i++) {
        if (i == 1) {
            printf("one");
        } else if (i == 2){
            printf("two");
        } else if (i == 3){
            printf("three");
        } else if (i == 4){
            printf("four");
        } else if (i == 5){
            printf("five");
        } else if (i == 6){
            printf("six");
        } else if (i == 7){
            printf("seven");
        } else if (i == 8){
            printf("eight");
        } else if (i == 9){
            printf("nine");
        } else {
            if (i % 2 == 0) {
                printf("even");
            } else {
                printf("odd");
            }
        }
        printf("\n");
    }
    return 0;
}