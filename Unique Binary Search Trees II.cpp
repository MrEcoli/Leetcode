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

	vector<TreeNode *> generateTrees(int n) {
		return generateTrees(1, n);
	}

	vector<TreeNode *> generateTrees(int start, int end){
		if (start == end){
			return vector<pNode>{new TreeNode(start)};
		}
		if (start > end)
			return vector<pNode>{nullptr};
		vector<pNode> res;
		for (int i = start; i <= end; ++i)
		{
			vector<pNode> lhs = generateTrees(start, i-1);
			vector<pNode> rhs = generateTrees(i + 1, end);
			for (int p = 0; p != lhs.size(); ++p)
			{
				for (int q = 0; q != rhs.size(); ++q)
				{
					pNode cur = new TreeNode(i);
					cur->left = lhs[p];
					cur->right = rhs[q];
					res.push_back(cur);
				}
			}
		}
		return res;
	}

};
