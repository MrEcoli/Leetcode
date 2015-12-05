class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head){
			return head;
		}

		int n = 1;
		ListNode* cur = head;

		while (cur->next){
			cur = cur->next;
			n++;
		}
		cur->next = head;

		k = n - k%n;
		cur = head;
		ListNode* ret;
		while (--k){
			cur = cur->next;
		}
		ret = cur->next;
		cur->next = nullptr;

		return ret;
	}
};
