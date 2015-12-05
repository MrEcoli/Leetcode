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

	vector<int> inorderTraversal(TreeNode *root) {
		stack<pNode> stk;
		pNode cur = root;
		vector<int> res;
		while (!stk.empty() || cur)
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stk.top();
				stk.pop();
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
		return res;
	}
};