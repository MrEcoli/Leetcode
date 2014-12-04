/*

Same Tree Total Accepted: 34584 Total Submissions: 82742 My Submissions Question Solution 
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Show Tags Tree Depth-first Search


*/



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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if(p == nullptr && q == nullptr)
			return true;
		if((p &&!q) || (!p && q) || p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}

};