

#include "../include/include.hpp"


class Solution
{
public:
	ListNode *rotateRight(ListNode *head, int k)
	{
		if (head == nullptr || k == 0) return head;

		ListNode* old_tail = head;
		int n;
		for (n = 1; old_tail->next != nullptr; ++n)
		{
			old_tail = old_tail->next;
		}

		k = k % n;
		if (k == 0)
			return (head);
		ListNode* new_tail = head;
		for (int i = 1; i < n - k; ++i)
		{
			new_tail = new_tail->next;
		}

		ListNode *newhead = new_tail->next;
		old_tail->next = head;
		new_tail->next = nullptr;
		return (newhead);
	}
};

int main()
{
	Solution ss;

	ListNode *head = nullptr;

	for (int i = 0; i <= 2; i++)
	{
		addNodeToBack(head, i);
	}
	printList(head);
	ListNode* newhead = ss.rotateRight(head, 4);
	printList(newhead);

	clearList(head);
	return (0);
}
