/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloned;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        cloned.clear();
        return solve(node);
    }
    UndirectedGraphNode *solve(UndirectedGraphNode *node){
        if (node == NULL) return NULL;
        it = cloned.find(node);
        if (it != cloned.end()) {
            return it->second;
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        cloned[node] = newNode;
        vector<UndirectedGraphNode*> neighbors;
        for (UndirectedGraphNode *n : node->neighbors) {
            neighbors.push_back(solve(n));
        }
        newNode->neighbors = neighbors;
        return newNode;
    }
};
