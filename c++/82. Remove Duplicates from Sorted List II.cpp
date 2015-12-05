



class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next)
			return head;
		
		ListNode dummpy_node(0);
		ListNode* dummpy = &dummpy_node;
		dummpy->next = head;
		ListNode* prev_node = dummpy, *cur_node = head, *nxt_node;

		while (cur_node && cur_node->next)
		{
			if (cur_node->val == cur_node->next->val)
			{
				nxt_node = cur_node->next;
				int cur_dup_val = cur_node->val;
				while (nxt_node && nxt_node->val == cur_dup_val)
				{
					nxt_node = nxt_node->next;
				}
				prev_node->next = nxt_node;
				cur_node = nxt_node;
			}
			else{
				prev_node = cur_node;
				cur_node = cur_node->next;
			}
		}

		return dummpy->next;
	}
};