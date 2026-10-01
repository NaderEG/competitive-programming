class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        unordered_map<int, int> hmap;
        for(int i = 0; i < items1.size(); i++) {
            hmap[items1[i][0]]+=items1[i][1];
        }
        for(int i = 0; i < items2.size(); i++) {
            hmap[items2[i][0]]+=items2[i][1];
        }
        vector<vector<int>> ret;
        for(auto& it : hmap) {
            ret.push_back({it.first, it.second});
        }
        sort(ret.begin(), ret.end(), [] (const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        return ret;
        
    }
};