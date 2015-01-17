class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next){
			return head;
		}

		ListNode* Cur_node = head->next, *Prev_node = head;

		while (Cur_node)
		{
			if (Cur_node->val == Prev_node->val){
				Prev_node->next = Cur_node->next;
				delete Cur_node;
				Cur_node = Prev_node->next;
			}
			else{
				Prev_node = Cur_node;
				Cur_node = Cur_node->next;
			}
		}
		return head;
	}
};