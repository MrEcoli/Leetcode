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
    void reorderList(ListNode *head) {
		if(head == nullptr || head->next == nullptr)
			return;
		ListNode *fast = head, *slow = head, *mid;
		while(fast->next != nullptr && fast->next->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}
		mid = reverseList(slow->next);
		slow->next = nullptr;
		ListNode *cur = head;
		while(cur->next){
			ListNode *tmp = cur->next;
			cur->next = mid;
			mid = mid->next;
			cur->next->next = tmp;
			cur = tmp;
		}
		cur->next = mid;

    }
	ListNode* reverseList(ListNode *head){
		if(head == nullptr || head->next == nullptr)
			return head;
		ListNode *pioneer = new ListNode(0);
		pioneer->next = head;
		ListNode *cur = head->next, *prev = head;
		while(cur != nullptr){
			prev->next = cur->next;
			cur->next = pioneer->next;
			pioneer->next = cur;
			cur = prev->next;
		}
		ListNode *tmp = pioneer->next;
		delete pioneer;
		return tmp;
	}
};