
/*

Construct Binary Tree from Inorder and Postorder Traversal Total Accepted: 17856 Total Submissions: 67137 My Submissions Question Solution 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Show Tags Tree Array Depth-first Search
Have you met this question in a real interview? Yes  No
Discuss




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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		unsigned n = inorder.size();
		if(n == 0)
			return nullptr;
		return build(inorder, 0, n-1, postorder, 0, n-1);
	}

	pNode build(vector<int> &inorder, int s1, int e1, vector<int> &postoder, int s2, int e2){
		if(s1 > e1)
			return nullptr;
		if(s1 == e1)
			return new TreeNode(inorder[s1]);
		pNode root = new TreeNode(postoder[e2]);
		int val = postoder[e2], index;

		for(index = s1; index <= e1; ++index){
			if(inorder[index] == val)
				break;
		}

		int rhs = index - s1, lhs = (e1 - index);
		root->left = build(inorder, s1, index-1, postoder, s2, s2+rhs-1);
		root->right = build(inorder, index+1, e1, postoder, s2+ rhs, e2-1);
		return root;
	}

};