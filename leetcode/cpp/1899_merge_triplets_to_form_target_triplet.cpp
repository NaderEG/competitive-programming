class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> result = {false, false, false};
        for(vector<int> triplet : triplets) {
            if(triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                result[0] = true;
            }
            if(triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2]) {
                result[1] = true;
            }
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2]) {
                result[2] = true;
            }
        }
        return result[0] && result[1] && result[2];
    }
};
