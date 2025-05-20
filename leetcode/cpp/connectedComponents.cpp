class Solution {
public:
    bool dfs(vector<vector<int>> graph, int current, set<int>& visited) {
        visited.insert(current);
        bool result = true;
        for(int neighbour : graph[current]) {
            if(visited.count(neighbour)) {
                continue;
            }
            else {
                dfs(graph, neighbour, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 
        set<int> visited;

        int connected = 0;
        for(int i = 0; i < n; i++) {
            if(!visited.count(i)) {
                dfs(graph, i, visited);
                connected++;
            }
        }
        return connected;
        
    }
};
