class Solution {
public:
    bool dfs(vector<vector<int>> graph, int parent, int child, set<int>& visited) {
        visited.insert(child);
        bool result = true;
        for(int neighbour : graph[child]) {
            if(neighbour == parent) {
                continue;
            }
            if(visited.count(neighbour)) {
                result = false;
            }
            else {
                result = result && dfs(graph, child, neighbour, visited);
            }
        }
        return result;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 
        set<int> visited;

        return dfs(graph, -1, 0, visited) && visited.size() == n;

    }
};
