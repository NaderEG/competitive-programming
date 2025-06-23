class Solution {
public:
    long long coloredCells(int n) {
        return (n-1)*0.5*(n)*4+1;
    }
};