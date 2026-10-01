class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), 1);

        unordered_map<int, int> lastRainedInLake;
        set<int> dryDays;
        for(int i = 0; i < rains.size(); i++) {
            if(rains[i] > 0) {
                res[i] = -1;
                if(lastRainedInLake.count(rains[i])) {
                    auto it = dryDays.lower_bound(lastRainedInLake[rains[i]]);
                    if(it == dryDays.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    dryDays.erase(it);
                }
                lastRainedInLake[rains[i]] = i;
            } else {
                dryDays.insert(i);
            }
            

        }
        return res;
    }
};