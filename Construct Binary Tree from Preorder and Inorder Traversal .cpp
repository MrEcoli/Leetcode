

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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		unsigned n = preorder.size();
		if(n == 0)
			return NULL;

		return build(preorder, 0, n-1, inorder, 0, n-1);
	}

	pNode build(vector<int> &preoder, int s1, int e1, vector<int> &inorder, int s2, int e2){
		if(s1> e1)
			return nullptr;
		if(s1 == e1)
			return new TreeNode(preoder[s1]);
		int value = preoder[s1];
		pNode root = new TreeNode(value);
		
		int index;
		for(index = s2; index <= e2; index++){
			if(inorder[index] == value)
				break;
		}
		
		int rhs = index - s2;

		root->left = build(preoder, s1+1, s1 + rhs, inorder, s2, index - 1);
		root->right = build(preoder, s1+rhs+1, e1, inorder, index+1, e2);
		return root;
		
	}
};