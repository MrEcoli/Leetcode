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
	ListNode *swapPairs(ListNode *head) {
		return reverseKGroup(head, 2);
	}
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *cur = head;
		int n = 0;
		while (cur)
		{
			cur = cur->next;
			++n;
		}
		if (n<2 || n < k || k < 2){
			return head;
		}

		return reverseKGroup(head, n, k);
	}

	ListNode *reverseKGroup(ListNode *head, int n, int k){
		if (n < k){
			return head;
		}
		if (head == nullptr)
			return head;

		ListNode dummpy(-1);
		ListNode *prev = &dummpy;
		prev->next = head;
		ListNode *last = head;
		ListNode *cur = head->next;

		int m = k;
		while (--m){
			last->next = cur->next;
			cur->next = prev->next;
			prev->next = cur;
			cur = last->next;
		}

		last->next = reverseKGroup(cur, n - k, k);

		return prev->next;
	}

};