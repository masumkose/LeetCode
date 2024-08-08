#include "include.hpp"

void printList(ListNode *head)
{
	ListNode *current = head;
	while (current != nullptr)
	{
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

void addNodeToBack(ListNode *&head, int value)
{
	ListNode *newNode = new ListNode(value);
	ListNode *current = head;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void clearList(ListNode *&head)
{
	ListNode *current = head;
	ListNode *nextNode = nullptr;

	while (current != nullptr)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}

	head = nullptr;
}

ListNode *getEnd(ListNode *head)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	ListNode *current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}
	return current;
}