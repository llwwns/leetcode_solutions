/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    map<int, UndirectedGraphNode *> finished;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        UndirectedGraphNode* d = new UndirectedGraphNode(node->label);
        finished[node->label] = d;
        for (auto p : node->neighbors) {
            auto f = finished.find(p->label);
            if (f != finished.end()) {
                d->neighbors.push_back(f->second);
            } else {
                d->neighbors.push_back(cloneGraph(p));
            }
        }
        return d;
    }
};