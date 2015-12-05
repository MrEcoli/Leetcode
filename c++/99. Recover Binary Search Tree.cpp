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
	pNode prev, first,second;
	void find_inner(pNode root){
		if(!root)
			return;
		find_inner(root->left);
		if(prev && prev->val > root->val){
			if(!first)
				first = prev;
			second = root;
		}
		prev = root;
		find_inner(root->right);
	}

	void recoverTree(TreeNode *root) {
		if(!root)
			return;
		find_inner(root);
		int tmp = first->val;
		first->val = second->val;
		second->val = tmp;

	}

};