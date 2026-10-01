class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        set<int> visited_1;
        vector<int> distances_1(edges.size(), INT_MAX);
        int distance = 0;
        int current = node1;
        while(visited_1.count(current) == 0 && current!=-1) {
            visited_1.insert(current);
            distances_1[current] = distance;
            current = edges[current];
            distance++;
        }

        set<int> visited_2;
        vector<int> distances_2(edges.size(), INT_MAX);
        distance = 0;
        current = node2;
        while(visited_2.count(current) == 0 && current!=-1) {
            visited_2.insert(current);
            distances_2[current] = distance;
            current = edges[current];
            distance++;
        }

        int closest_neighbour;
        int min_distance = INT_MAX;
        for(int i = 0; i < distances_1.size(); i++) {
            if(max(distances_1[i], distances_2[i]) < min_distance) {
                min_distance = max(distances_1[i], distances_2[i]);
                closest_neighbour = i;
            }
        }
        if(min_distance == INT_MAX) {
            return -1;
        }
        return closest_neighbour;
    }
};