/*

Path Sum II Total Accepted: 24239 Total Submissions: 90268 My Submissions Question Solution 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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



	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> res;

		if(root == nullptr)
			return res;

		vector<int> path;
		
		path.push_back(root->val);

		dfs(res, path, root->val, sum, root);
		return res;
	}
	void dfs(vector<vector<int>> &res, vector<int> &path, int cur_sum, int target_sum, pNode cur_node){
		if(cur_node->left == nullptr && cur_node->right == nullptr){
			if(cur_sum == target_sum){
				res.push_back(path);
			}
			return;
		}

		if(cur_node->left != nullptr){
			int val = cur_node->left->val;
			path.push_back(val);
			dfs(res, path, cur_sum + val, target_sum, cur_node->left);
			path.pop_back();
		}

		if(cur_node->right != nullptr){
			int val = cur_node->right->val;
			path.push_back(val);
			dfs(res, path, cur_sum+val, target_sum, cur_node->right);
			path.pop_back();
		}
	}
};