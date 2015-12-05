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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1==nullptr||l2==nullptr)
			return l1==nullptr?l2:l1;
		if(l1->val<l2->val){
			l1->next=mergeTwoLists(l1->next,l2);
			return l1;
		}
		else{
			l2->next=mergeTwoLists(l1,l2->next);
			return l2;
		}
    }
	ListNode *sortList(ListNode *head) {
        if(head==nullptr||head->next==nullptr)
			return head;
		ListNode* Cur, *second, *first=head;
		for(ListNode* p1=head, *p2=head;p2!=nullptr&&p2->next!=nullptr;p1=p1->next,p2=p2->next->next){
			Cur=p1;
		}
		second=Cur->next;
		Cur->next=nullptr;
		second=sortList(second);
		first=sortList(first);
		return mergeTwoLists(first,second);
    }
};