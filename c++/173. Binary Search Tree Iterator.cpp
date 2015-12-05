/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
	typedef TreeNode* pNode;
private:
	stack<pNode> stk;
	pNode cur_p;
public:
	BSTIterator(TreeNode *root) {
		cur_p = root;
		while (cur_p != nullptr){
			stk.push(cur_p);
			cur_p = cur_p->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (stk.empty() && !cur_p)
			return false;
		return true;
	}

	/** @return the next smallest number */
	int next() {
		if (!hasNext())
			return -1;
		while (cur_p){
			stk.push(cur_p);
			cur_p = cur_p->left;
		}
		cur_p = stk.top();
		stk.pop();
		int res = cur_p->val;
		cur_p = cur_p->right;
		return res;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */