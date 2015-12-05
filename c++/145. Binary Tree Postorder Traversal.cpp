class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		pNode p = root, q;
		stack<pNode> stk;
		vector<int> res;

		do{
			while (p)
			{
				stk.push(p);
				p = p->left;
			}

			q = nullptr;

			while (!stk.empty())
			{
				p = stk.top();
				stk.pop();
		
				if (p->right == q){
					res.push_back(p->val);
					q = p;
				}
				else{
					stk.push(p);
					p = p->right;
					break;
				}

			}
		} while (!stk.empty());

		return res;
	}
};
