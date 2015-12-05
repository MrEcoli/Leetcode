/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	typedef TreeNode* pNode;
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		queue<pNode> cur_que, nxt_que;
		vector<vector<int>> res;
		if(root == nullptr)
			return res;
		cur_que.push(root);

		while(!cur_que.empty()){
			vector<int> cur_lvl;
			while(!cur_que.empty()){
				pNode cur_node = cur_que.front();
				cur_que.pop();
				cur_lvl.push_back(cur_node->val);
				if(cur_node->left != nullptr)
					nxt_que.push(cur_node->left);
				if(cur_node->right != nullptr)
					nxt_que.push(cur_node->right);
			}
			res.push_back(cur_lvl);
			if(nxt_que.empty())
				break;
			else
				nxt_que.swap(cur_que);
		}
		reverse(res.begin(), res.end());
		return res;

	}
};