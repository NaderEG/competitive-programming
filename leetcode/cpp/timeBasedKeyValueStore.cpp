using std::unordered_map;
using std::pair;
class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> time_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(time_map.find(key) == time_map.end()) {
            return "";
        }
        int left = 0;
        int right = time_map[key].size()-1;
        int mid;
        string result = "";
        while(left <=right) {
            int mid = (left + right) / 2;
            if (time_map[key][mid].second <= timestamp) {
                result = time_map[key][mid].first;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return result;
    }
};
