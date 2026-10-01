class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));

        for(vector<int> pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                indegree[graph[i][j]]++;
            }
        }
        set<int> s;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                s.insert(i);
            }
        }
        vector<int> res;
        while(!s.empty()) {
            auto it = s.begin();
            int n = *it;
            s.erase(it);
            res.push_back(n);
            vector<int> edges = graph[n];
            for(int i = 0; i < edges.size(); i++) {
                int m = edges[i];
                graph[n].erase(graph[n].begin()+i);
                indegree[m]--;
                if(indegree[m] == 0) {
                    s.insert(m);
                }

            }


        }

        for(vector<int> edges : graph) {
            if(edges.size() > 0) {
                return {};
            }
        }

        return res;

    }
};
