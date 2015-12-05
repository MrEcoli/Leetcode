

/*

Convert Sorted Array to Binary Search Tree Total Accepted: 24717 Total Submissions: 75091 My Submissions Question Solution 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Show Tags
Have you met this question in a real interview? Yes  No
Discuss



*/









class Solution {
public:
	typedef TreeNode* pNode;
	TreeNode *sortedArrayToBST(vector<int> &num) {
		unsigned n = num.size();
		if(n == 0)
			return nullptr;
		return toBST(num, 0, n);
		
	}

	pNode toBST(vector<int> &num, unsigned start, unsigned n){
		if(n == 0)
			return nullptr;
		if(n == 1)
			return new TreeNode(num[start]);

		unsigned mid = (n-1)>>1;
		pNode root = new TreeNode(num[start + mid]);
		root->left = toBST(num, start, (n-1)>>1);
		root->right = toBST(num, start + mid + 1, n - ((n-1)>>1) -1);
		return root;
	}

};