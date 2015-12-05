class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr || l2 == nullptr)
			return l1 == nullptr ? l2 : l1;
		if (l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty())
			return nullptr;
		int curSize = lists.size(), halfSize;
		while (curSize > 1){
			halfSize = (curSize + 1) / 2;
			for (int i = 0; i < halfSize && (i + halfSize) < curSize; ++i){
				lists[i] = mergeTwoLists(lists[i], lists[i + halfSize]);
			}
			curSize = halfSize;
		}

		return lists[0];
	}
};