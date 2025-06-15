class Solution {
public:
    int stringDifference(string string1, string string2) {
        int res = 0;
        for(int i = 0; i < string1.length(); i ++) {
            if(string1[i] != string2[i]) {
                res++;
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> graph;
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = 0; j < wordList.size(); j++) {
                if(stringDifference(wordList[i], wordList[j]) == 1) {
                    graph[wordList[i]].push_back(wordList[j]);
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> distances;
        set<string> visited;
        visited.insert(beginWord);
        distances[beginWord] =1;
        while(!q.empty()) {
            string current = q.front();
            q.pop();
            for(string word : graph[current]) {
                if(visited.count(word) == 0) {
                    distances[word] = distances[current] +1;
                    q.push(word);
                    visited.insert(word);
                }
            }
        }
        return distances[endWord];
    }
};
