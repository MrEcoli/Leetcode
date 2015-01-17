

/*
Symmetric Tree Total Accepted: 30820 Total Submissions: 97404 My Submissions Question Solution 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
 
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
	bool isSymmetric(TreeNode *root) {
		if(root == nullptr)
			return true;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(pNode lhs, pNode rhs){
		if(lhs == nullptr && rhs == nullptr)
			return true;
		if((lhs && !rhs) || (!lhs && rhs) || lhs->val != rhs->val)
			return false;
		return isSymmetric(lhs->left, rhs->right) && isSymmetric(lhs->right, rhs->left);

	}

};