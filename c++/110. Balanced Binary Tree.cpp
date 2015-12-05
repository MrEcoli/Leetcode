
/*
Balanced Binary Tree Total Accepted: 29868 Total Submissions: 91915 My Submissions Question Solution 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/


/*Definition for binary tree*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
	typedef TreeNode* pNode;
	bool isBalanced(TreeNode *root) {
		int h = height(root);

		if(h == -1)
			return false;
		else
			return true;
	}

	int height(pNode ptr){
		if(ptr == nullptr)
			return 0;
		int rhs = height(ptr->right);
		int lhs = height(ptr->left);

		if(rhs == -1 || lhs == -1 || abs(lhs - rhs) > 1)
			return -1;
		return (lhs > rhs ? lhs: rhs) + 1;
	}

};