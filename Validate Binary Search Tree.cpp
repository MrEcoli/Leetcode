
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


class Solution {
public:
	typedef TreeNode* pNode;
	bool isValidBST(TreeNode *root) {
		if(root == nullptr)
			return true;
		this->prev = nullptr;
		this->isBST = true;
		isvalid(root);
		return isBST;
	}
	pNode prev;
	bool isBST;
	void isvalid(pNode root){
		if(!root)
			return;
		isvalid(root->left);
		if(prev && prev->val >= root->val){
			isBST = false;
			return;
		}
		prev = root;
		isvalid(root->right);
	}
};


class Solution {
public:
	typedef TreeNode* pNode;
	bool isValidBST(TreeNode *root) {
		if(root == nullptr)
			return true;
		return isvalid(root, INT_MIN, INT_MAX);
	}
	bool isvalid(pNode root, int left, int right){
		if(root == nullptr)
			return true;
		if(root->val > left && root->val < right){
			return isvalid(root->left, left, root->val) && isvalid(root->right, root->val, right);
		}else
			return false;

	}
};
