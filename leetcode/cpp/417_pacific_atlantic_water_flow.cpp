// really ugly solution but I will come back to this and make it better eventually

class Solution {
public:
    bool valid_step(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(m == n && n == 1) {
            return {{0, 0}};
        }

        queue<int> pq;
        set<int> pv;
        pq.push(0);

        for(int i = 1; i < n; i++) {
            pq.push(i*m);
            pv.insert(i*m);
        }
        for(int i = 1; i < m; i++) {
            pq.push(i);
            pv.insert(i);
        }

        queue<int> aq;
        set<int> av;
        aq.push(m*n-1);

        for(int i = 0; i < n-1; i++) {
            aq.push(i*m+m-1);
            av.insert(i*m+m-1);
        }
        for(int i = 0; i < m-1; i++) {
            aq.push((n-1)*m+i);
            av.insert((n-1)*m+i);
        }

        while(!pq.empty()) {
            int tile = pq.front();
            pq.pop();
            pv.insert(tile);

            int j = tile % m;
            int i = tile / m;

            if(valid_step(heights, i+1, j) && heights[i+1][j] >= heights[i][j]) {
                if(pv.count((i+1)*m + j) == 0) {
                    pq.push((i+1)*m + j);
                    pv.insert((i+1)*m + j);
                }
            }
            if(valid_step(heights, i-1, j) && heights[i-1][j] >= heights[i][j]) {
                if(pv.count((i-1)*m + j) == 0) {
                    pq.push((i-1)*m + j);
                    pv.insert((i-1)*m + j);
                }
            }
            if(valid_step(heights, i, j+1) && heights[i][j+1] >= heights[i][j]) {
                if(pv.count(i*m + j+1) == 0) {
                    pq.push(i*m + j+1);
                    pv.insert(i*m + j+1);
                }
            }
            if(valid_step(heights, i, j-1) && heights[i][j-1] >= heights[i][j]) {
                if(pv.count(i*m + j-1) == 0) {
                    pq.push(i*m + j-1);
                    pv.insert(i*m + j-1);
                }
            }
            
        }

        while(!aq.empty()) {
            int tile = aq.front();
            aq.pop();

            int j = tile % m;
            int i = tile / m;

            if(valid_step(heights, i+1, j) && heights[i+1][j] >= heights[i][j]) {
                if(av.count((i+1)*m + j) == 0) {
                    aq.push((i+1)*m + j);
                    av.insert((i+1)*m + j);
                }
                
            }
            if(valid_step(heights, i-1, j) && heights[i-1][j] >= heights[i][j]) {
                if(av.count((i-1)*m + j) == 0) {
                    aq.push((i-1)*m + j);
                    av.insert((i-1)*m + j);
                }
            }
            if(valid_step(heights, i, j+1) && heights[i][j+1] >= heights[i][j]) {
                if(av.count(i*m + j+1) == 0) {
                    aq.push(i*m + j+1);
                    av.insert(i*m + j+1);
                }
            }
            if(valid_step(heights, i, j-1) && heights[i][j-1] >= heights[i][j]) {
                if(av.count(i*m + j-1) == 0) {
                    aq.push(i*m + j-1);
                    av.insert(i*m + j-1);

                }
            }
            
        }
        vector<vector<int>> res;
        for(int tile : av) {
            if(pv.count(tile)) {
                int j = tile % m;
                int i = tile / m;
                res.push_back({i, j});
            
            }
        }
        return res;

    }
};
