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

TreeNode *createTree(const vector<int> &arr, int index)
{
	if (index >= arr.size() || arr[index] == -1)
		return nullptr;

	TreeNode *root = new TreeNode(arr[index]);
	root->left = createTree(arr, 2 * index + 1);
	root->right = createTree(arr, 2 * index + 2);

	return root;
}

void printInOrder(TreeNode *root)
{
	if (!root)
		return;
	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

void printLevelOrder(TreeNode *root)
{
	if (!root)
		return;

	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode *current = q.front();
		q.pop();

		if (current)
		{
			cout << current->val << " ";
			q.push(current->left);
			q.push(current->right);
		}
		else
		{
			cout << "null "; // print null for missing nodes
		}
	}
	cout << endl;
}
