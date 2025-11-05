class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i < n+1; i++) {
            parent[i] = i;
        }
        for(auto edge : edges) {
            int v1 = edge[0];
            int v2 = edge[1];
            int p1 = find(parent, v1);
            int p2 = find(parent, v2);
            if(p1 == p2) {
                return edge;
            }
            parent[p1] = p2;
            
        }
        return {};
    }

    int find(vector<int>& parents, int v1) {
        if(v1 != parents[v1]) {
            parents[v1] = find(parents, parents[v1]);
        }
        return parents[v1];
    }


};
