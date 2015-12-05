class Solution {
public:
	typedef TreeLinkNode* pNode;
	void connect(TreeLinkNode *root) {
		if(root == nullptr)
			return;

		pNode cur = root, nxt_head;
		pNode nxt_cur = nullptr;
		bool find_nxt_head = false;

		while(cur || find_nxt_head){
			if(!cur){
				find_nxt_head = false;
				cur = nxt_head;
				nxt_head = nullptr;
			}
			while(!find_nxt_head){
				if(cur->left != nullptr){
					find_nxt_head = true;
					nxt_head = cur->left;
					nxt_cur = nxt_head;
				}else if(cur->right != nullptr){
					find_nxt_head = true;
					nxt_head = cur->right;
					nxt_cur =nxt_head;
				}else if(cur->next != nullptr){
					cur = cur->next;
				}else
					break;
			}

			while(cur){
				if(cur->left != nullptr && cur->left != nxt_cur){
					nxt_cur->next = cur->left;
					nxt_cur = nxt_cur->next;
				}else if(cur->right !=nullptr){
					if(cur->right == nxt_cur)
						cur = cur->next;
					else{
						nxt_cur->next = cur->right;
						nxt_cur = nxt_cur->next;
						cur = cur->next;
					}
				}else
					cur = cur->next;
			}
		}

	}
};