/*

Binary Tree Zigzag Level Order Traversal Total 
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/









class Solution {
public:
	typedef TreeNode* pNode;
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> res;
		if(root == nullptr)
			return res;
		queue<pNode> cur_q, nxt_q;
		cur_q.push(root);
		bool rev = false;
		while(!cur_q.empty()){
			vector<int> cur_lvl;
			while(!cur_q.empty()){
				pNode tmp = cur_q.front();
				cur_q.pop();
				cur_lvl.push_back(tmp->val);
				if(tmp->left != nullptr)
					nxt_q.push(tmp->left);
				if (tmp->right != nullptr)
					nxt_q.push(tmp->right);

			}
			if(rev){
				reverse(cur_lvl.begin(), cur_lvl.end());
			}
			rev = !rev;

			res.push_back(cur_lvl);
			cur_q.swap(nxt_q);
		}

		return res;
	}
};
