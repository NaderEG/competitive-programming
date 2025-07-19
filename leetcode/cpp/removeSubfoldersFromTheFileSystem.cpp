class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        res.push_back(folder[0]);

        for(int i = 1; i < folder.size(); i++) {
            string curr_path = res.back();
            if(folder[i].rfind(curr_path+"/", 0)) {
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};