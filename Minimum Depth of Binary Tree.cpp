

/*


Minimum Depth of Binary Tree Total Accepted: 28512 Total Submissions: 96988 My Submissions Question Solution 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Show Tags Tree Depth-first Search



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
	int minDepth(TreeNode *root) {
		if(root == nullptr)
			return 0;


		int lhs = minDepth(root->left);
		int rhs = minDepth(root->right);

		if(root->left != nullptr && root->right != nullptr)
			return (lhs < rhs ? lhs : rhs) + 1;
		else
			return (lhs < rhs ? rhs : lhs) + 1;


	}
};