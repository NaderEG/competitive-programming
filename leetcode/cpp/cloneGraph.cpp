/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if(visited.count(node) > 0) {
            return visited[node];
        }

        Node* copy = new Node(node->val);
        visited[node] = copy;
        for(Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return copy;
    }
};
