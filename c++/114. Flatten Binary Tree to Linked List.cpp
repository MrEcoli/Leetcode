







/*

Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


recursive method
*/




class Solution {
public:

	typedef TreeNode *pNode;
    void flatten(TreeNode *root) {
        root = myFlatten(root);
    }
	pNode myFlatten(pNode ptr){
		if(ptr == nullptr)
			return nullptr;

		pNode lhs = myFlatten(ptr->left);
		pNode rhs = myFlatten(ptr->right);
		if(lhs != nullptr && rhs != nullptr){
			ptr->right = lhs;
			while(lhs->right != nullptr){
				lhs = lhs->right;
			}
			ptr->left = nullptr;
			lhs->right = rhs;
			lhs->left = nullptr;
		}else if(lhs != nullptr){
			ptr->right = lhs;
			ptr->left = nullptr;
		}
		return ptr;
	}
	
};
