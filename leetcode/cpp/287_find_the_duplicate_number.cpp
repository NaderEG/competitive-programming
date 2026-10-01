class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> index;
        for (int i = 0; i < nums.size(); i++) {
            index.push_back(i);
        }
        int bunny = 0;
        int turtle = 0;
        for (int j : index) {
            
            turtle = nums[index[turtle]];
            bunny = nums[index[bunny]];
            bunny = nums[index[bunny]];
            if (index[bunny] == index[turtle]) {
                int sloth = 0;
                while(index[bunny] != index[sloth]) {
                    bunny = nums[index[bunny]];
                    sloth = nums[index[sloth]];
                }
                return index[bunny];
                
            }
            
        }
        
    }
};
