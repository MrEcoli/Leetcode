/*
Binary Tree Maximum Path Sum Total Accepted: 23064 Total Submissions: 114307 My Submissions Question Solution 
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

*/



//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	typedef TreeNode* pNode;
    int maxPathSum(TreeNode *root) {
		int max_sum = INT_MIN;
	
		dfs(root, max_sum);
		
		return max_sum;
    }
	
	void dfs(pNode p, int &max_sum){
		if(p == nullptr)
			return;

		dfs(p->left, max_sum);
		dfs(p->right, max_sum);

		int lval = p->left == nullptr ? 0: p->left->val;
		int rval = p->right == nullptr ? 0 : p->right->val;
		
		int sum = p->val;
		if(lval > 0){
			sum += lval;
		}
		if(rval > 0){
			sum += rval;
		}

		max_sum = sum > max_sum ? sum : max_sum;
		int add = lval> rval ? lval : rval;
		int tmp1 = p->val, tmp2 = p->val + add;

		p->val = tmp1 > tmp2 ? tmp1:tmp2;
	}


};
