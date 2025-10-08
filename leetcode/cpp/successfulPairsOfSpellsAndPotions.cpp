class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(int i = 0; i < spells.size(); i++) {
            long long target = (success + spells[i]-1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), target);
            int pos = it-potions.begin();
            int num = potions.size() - pos;
            res.push_back(num);
        }
        return res;
    }
};