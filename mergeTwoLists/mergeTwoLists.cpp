#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;



struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode temp;
		ListNode *head = &temp;

		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val < list2->val)
			{
				head->next = list1;
				list1 = list1->next;
			}
			else
			{
				head->next = list2;
				list2 = list2->next;
			}
			head = head->next;
		}
		if (list1 != nullptr)
		{
			head->next = list1;
		}
		if (list2 != nullptr)
		{
			head->next = list2;
		}
		return (temp.next);
	}

	void printLinkedList(ListNode* head)
	{
		ListNode* current = head;
			while (current != nullptr)
			{
				std::cout << current->val << " ";
				current = current->next;
			}
		std::cout << std::endl;
	}
};

int main()
{
	Solution s;
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(4);

	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);

	s.printLinkedList(list1);
	s.printLinkedList(list2);
	ListNode* head = s.mergeTwoLists(list1, list2);
	s.printLinkedList(head);


	return (0);
}