
/*
Binary Tree Level Order Traversal II Total Accepted: 22136 Total Submissions: 71447 My Submissions Question Solution 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		queue<pNode> cur_que, nxt_que;
		vector<vector<int>> res;
		if(root == nullptr)
			return res;
		cur_que.push(root);

		while(!cur_que.empty()){
			vector<int> cur_lvl;
			while(!cur_que.empty()){
				pNode cur_node = cur_que.front();
				cur_que.pop();
				cur_lvl.push_back(cur_node->val);
				if(cur_node->left != nullptr)
					nxt_que.push(cur_node->left);
				if(cur_node->right != nullptr)
					nxt_que.push(cur_node->right);
			}
			res.push_back(cur_lvl);
			if(nxt_que.empty())
				break;
			else
				nxt_que.swap(cur_que);
		}
		reverse(res.begin(), res.end());
		return res;

	}
};