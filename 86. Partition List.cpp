

// Partition List Total Accepted: 25941 Total Submissions: 95500 My Submissions Question Solution 
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

// Show Tags
// Have you met this question in a real interview? Yes  No





class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode Lower_node(-1), Upper_node(-1);
		ListNode* Lower_head = &Lower_node, *Upper_head = &Upper_node, *Cur_Node = head;
		ListNode* lower_prev = Lower_head, *upper_prev = Upper_head;

		while (Cur_Node)
		{
			if (Cur_Node->val < x){
				lower_prev->next = Cur_Node;
				lower_prev = lower_prev->next;
			}
			else{
				upper_prev->next = Cur_Node;
				upper_prev = upper_prev->next;
			}
			Cur_Node = Cur_Node->next;
		}
		upper_prev->next = nullptr;
		lower_prev->next = Upper_head->next;

		return Lower_head->next;
	}
};