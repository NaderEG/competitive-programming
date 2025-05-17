class Solution {
public:
    bool noCycles(vector<vector<int>> graph, int vertex, set<int> path) {
        if(path.count(vertex)) {
            return false;
        }
        bool result = true;
        path.insert(vertex);
        for(int neighbour : graph[vertex]) {
            result = result && noCycles(graph, neighbour, path);
        }
        return result;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(vector<int> edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        bool result = true;
        for(int i = 0; i < numCourses; i++) {
            result = result && noCycles(graph, i, set<int>());
        }
        return result;
        

    }
};
