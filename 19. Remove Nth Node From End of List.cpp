

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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == nullptr)
			return head;
		ListNode dummpy(-1);
		dummpy.next = head;
		ListNode *fast = head, *slow = &dummpy;
		while (n--){
			fast = fast->next;
		}
		while (fast){
			fast = fast->next;
			slow = slow->next;
		}

		ListNode* tmp = slow->next;

		slow->next = slow->next->next;
		delete tmp;

		return dummpy.next;
	}
};