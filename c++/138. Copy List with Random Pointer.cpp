class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
			return nullptr;
		RandomListNode *cur = head, *tmp = head->next;
		unsigned n = 0;
		while (cur)
		{
			++n;
			tmp = cur->next;
			cur->next = new RandomListNode(cur->label);
			cur->next->next = tmp;
			cur = tmp;
		}
		
		RandomListNode *prev = head;
		cur = head->next;
		unsigned m = n;
		for (RandomListNode* cur = head; cur != nullptr; ) {
            if (cur->random != NULL)
            cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
		RandomListNode dummy(-1);
		for (RandomListNode* cur = head, *new_cur = &dummy;
            cur != nullptr; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;

    }
};