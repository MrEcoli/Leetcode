/*

Convert Sorted List to Binary Search Tree Total Accepted: 23089 Total Submissions: 84408 My Submissions Question Solution 
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Show Tags Depth-first Search Linked List
Have you met this question in a real interview? Yes  No
Discuss



*/


class Solution {
public:
	typedef TreeNode* pNode;
	typedef ListNode* lNode;
	TreeNode *sortedListToBST(ListNode *head) {
		if(head == nullptr)
			return nullptr;
		lNode cur = head;
		unsigned n = 0;
		while(cur != nullptr){
			++n;
			cur = cur->next;
		}

		pNode root = toBST(head, n);
		return root;
	}

	pNode toBST(lNode head, unsigned n){
		if(head == nullptr)
			return nullptr;
		if(n == 1)
			return new TreeNode(head->val);
		if(n == 0)
			return nullptr;

		unsigned mid = n>>1;
		lNode nxt = head;
		
		for(int i = 0; i != mid; ++i)
			nxt = nxt->next;
		pNode root = new TreeNode(nxt->val);

		root->left = toBST(head, n>>1);
		root->right = toBST(nxt->next, n-(n>>1)-1);
		return root;
	}

};