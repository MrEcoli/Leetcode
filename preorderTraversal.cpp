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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if(root == nullptr)
			return res;
		stack<TreeNode*> node_stack;
		node_stack.push(root);
		while(!node_stack.empty()){
			TreeNode *tmp = node_stack.top();
			node_stack.pop();
			res.push_back(tmp->val);
			if(tmp->right != nullptr)
				node_stack.push(tmp->right);
			if(tmp->left != nullptr)
				node_stack.push(tmp->left);
		}
		return res;
    }
};
