/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * 
 **************************************************************************/

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

map<UndirectedGraphNode*, UndirectedGraphNode*> old_new_map;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (NULL == node) {
        return NULL;
    }
    UndirectedGraphNode* new_node = NULL;
    map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = 
        old_new_map.find(node);
    if (it == old_new_map.end()) {
        new_node = new UndirectedGraphNode(node->label);
        old_new_map.insert(make_pair(node, new_node));
        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            UndirectedGraphNode* tmp = cloneGraph(node->neighbors[i]);
            if (tmp != NULL) {
                new_node->neighbors.push_back(tmp);
            }
        }
        return new_node;
    } else {
        new_node = it->second;
    }
    return new_node;
} 
 
 






















/* vim: set ts=4 sw=4 sts=4 tw=100 */
