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
    unordered_map<Node*, Node*> u;
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        Node *first = new Node(node->val, {});
        u[node] = first;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node *curr = q.front();     q.pop();
            for(auto adj : curr->neighbors){
                if(u.find(adj) == u.end()){
                    u[adj] = new Node(adj->val, {});
                    q.push(adj);
                }
                u[curr]->neighbors.push_back(u[adj]);
            }
        }
        return u[node];
    }
};
