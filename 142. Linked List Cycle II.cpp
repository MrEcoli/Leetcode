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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
		while(fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
				break;
		}
		if(fast == nullptr || fast->next == nullptr)
			return nullptr;
		slow = slow->next;
		fast->next = nullptr;
		fast = head;
		return intersection(fast, length(fast), slow, length(slow));
    }
	unsigned length(ListNode *head){
		unsigned n = 0;
		while(head != nullptr){
			++n;
			head = head->next;
		}
		return n;
	}
	ListNode* intersection(ListNode *ptr1, unsigned n1, ListNode *ptr2, unsigned n2){
		if(n1 < n2)
			return intersection(ptr2, n2, ptr1, n1);
		unsigned diff = n1 - n2;
		while(diff != 0){
			ptr1 = ptr1->next;
			--diff;
		}
		while(ptr1 != ptr2){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return ptr1;	
	}
};