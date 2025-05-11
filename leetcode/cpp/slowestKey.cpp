class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxTime = releaseTimes[0];
        int maxKey = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            if(releaseTimes[i] - releaseTimes[i-1] >= maxTime) {
                if(releaseTimes[i] - releaseTimes[i-1] == maxTime) {
                    maxKey = keysPressed[i] > maxKey ? keysPressed[i] : maxKey;
                } else {
                    maxKey = keysPressed[i];
                    maxTime = releaseTimes[i] - releaseTimes[i-1];
                }
            }
        }
        return maxKey;
    }
};