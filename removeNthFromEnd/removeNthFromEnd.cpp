#include <iostream>
#include <algorithm>
#include <list>

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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *temp = head;
		int size = 0;
		
		if (head == nullptr)
			return (nullptr);
		while (temp != nullptr)
		{
			size++;
			temp = temp->next;
		}

		int positionFromStart = size - n;

		if (positionFromStart == 0)
		{
			ListNode* newHead = head->next;
			delete head;
			return newHead;
		}
		temp = head;
		for (int i = 1; positionFromStart > i; i++)
		{
			temp = temp->next;
		}
		if (temp != nullptr && temp->next != nullptr)
		{
			ListNode* nodetodelete = temp->next;
			temp->next = nodetodelete->next;
			delete nodetodelete;
		}
		return (head);
	}
};


int main()
{
	Solution s;
	ListNode *head = nullptr;  // Initialize head to nullptr
	ListNode *current = nullptr;

	// Create and add 5 nodes with values 1 to 5
	for (int i = 1; i < 6; i++)
	{
		if (head == nullptr)
		{
			head = new ListNode(i);
			current = head;
		}
		else
		{
			current->next = new ListNode(i);
			current = current->next;
		}
	}

	// Print the linked list to verify
	current = head;
	while (current != nullptr) {
	cout << current->val << " ";
	current = current->next;
	}
	cout << "\n--------------------------" << endl;
	current = s.removeNthFromEnd(head, 5);
	while (current != nullptr) {
	cout << current->val << " ";
	current = current->next;
	}
	cout << "\n--------------------------" << endl;



	return (0);
}