

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
	typedef UndirectedGraphNode* pNode;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == nullptr)
			return nullptr;
		unordered_map<int, pNode> marker;
		return dfs(marker, node);
    }

	pNode dfs(unordered_map<int, pNode> &marker, pNode node){
		if(node == nullptr)
			return nullptr;
		if(marker.find(node->label) != marker.end()){
			return marker[node->label];
		}

		pNode res = new UndirectedGraphNode(node->label);
		marker[node->label] = res;
		for(auto iter = node->neighbors.begin(); iter != node->neighbors.end(); ++iter){
			if(marker.find((*iter)->label) != marker.end())
				res->neighbors.push_back(marker[(*iter)->label]);
			else
				res->neighbors.push_back(dfs(marker, (*iter)));
		}
		return res;
	}
};
