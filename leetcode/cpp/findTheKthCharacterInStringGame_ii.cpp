class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int offset = 0;
        int i = 0;
        for(int i = operations.size() - 1; i >= 0; i--) {
            if(k > pow(2, i)) {
                if(operations[i] == 1) {
                    offset++;
                    
                }
                k = k - pow(2,i);
            }
            
        }
        return ('a' + offset - 97) % 26 + 97;
    }
};