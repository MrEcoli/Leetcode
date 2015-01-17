/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *cur = l1;
		int n1 = 0, n2 = 0;
		while (cur)
		{
			cur = cur->next;
			n1++;
		}

		cur = l2;
		while (cur)
		{
			cur = cur->next;
			n2++;
		}
		return addTwoNumbers(l1, n1, l2, n2);
	}

	ListNode *addTwoNumbers(ListNode *l1, int n1, ListNode *l2, int n2){
		if (n1 < n2){
			return addTwoNumbers(l2, n2, l1, n1);
		}

		ListNode *cur1 = l1, *cur2 = l2;
		ListNode *prev = nullptr;

		int overflow = 0;
		while (cur1 || cur2)
		{
			int val1 = cur1->val, val2 = cur2 ? cur2->val : 0;
			cur1->val = (val1 + val2 + overflow) % 10;
			overflow = (val1 + val2 + overflow) / 10;
			if (cur1->next == nullptr){
				prev = cur1;
			}
			cur1 = cur1->next;
			cur2 = cur2 ? cur2->next : nullptr;
		}
		if (overflow){
			prev->next = new ListNode(overflow);
		}

		return l1;
	}
};