/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	typedef ListNode* plnode;
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (!head || m == n)
			return head;

		ListNode* fakeHead = new ListNode(-1);
		int Reverse_Count = n - m;
		fakeHead->next = head;
		
		ListNode* Cur_head_node = fakeHead;
		while (--m){
			Cur_head_node = Cur_head_node->next;
		}
		ListNode* Prev_node = Cur_head_node->next;
		ListNode* Nxt_node = Prev_node->next;
		while (Reverse_Count--){
			Prev_node->next = Nxt_node->next;
			Nxt_node->next = Cur_head_node->next;
			Cur_head_node->next = Nxt_node;
			Nxt_node = Prev_node->next;
		}
		return fakeHead->next;
	}
};