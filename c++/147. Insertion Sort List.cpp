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
    ListNode *insertionSortList(ListNode *head) {
        if(head==nullptr||head->next==nullptr)
			return head;
		int Min=INT_MAX;
		ListNode* pCur,*pMin,*pTrva;
		for(pCur=head;pCur->next!=nullptr;pCur=pCur->next){
			Min=INT_MAX;
			for(pTrva=pCur;pTrva!=nullptr;pTrva=pTrva->next){
				if(pTrva->val<Min){
					pMin=pTrva;
					Min=pTrva->val;
				}
			}
			pMin->val=pCur->val;
			pCur->val=Min;
		}
		return head;
    }
};