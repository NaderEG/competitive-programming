class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> history;
        pair<int, int> current = {0, 0};

        for(char coord : path) {
            if(history.count(current)) {
                return true;
            }
            history.insert(current);

            if(coord == 'N') current.second++;
            if(coord == 'E') current.first++;
            if(coord == 'S') current.second--;
            if(coord == 'W') current.first--;
        }
        return history.count(current);
    }
};