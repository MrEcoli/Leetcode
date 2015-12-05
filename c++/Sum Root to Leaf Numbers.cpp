
/**

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

**/



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
    int sumNumbers(TreeNode *root) {
        if(root == nullptr)
			return 0;
		int sum = 0;
		vector<pNode> path;
		dfs(sum, root, path);
		return sum;
    }

	void dfs(int &sum, pNode cur, vector<pNode> &path){
		if(cur->left == nullptr && cur->right == nullptr){
			sum += (pathSum(path)*10 + cur->val);
			return;
		}
		if(cur->left != nullptr){
			path.push_back(cur);
			dfs(sum, cur->left, path);
			path.pop_back();
		}
		if (cur->right != nullptr){
			path.push_back(cur);
			dfs(sum, cur->right, path);
			path.pop_back();
		}
	}

	int pathSum(vector<pNode> path){
		unsigned n = path.size();
		int res = 0;
		for(int i = 0; i != n; ++i){
			res = res*10 + (path[i]->val);
		}
		return res;
	}

};