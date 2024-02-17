/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode	*ft_lstnew(int data)
{
	struct ListNode	*new;

	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (new == NULL)
		return (NULL);
	new -> val = data;
	new -> next = NULL;
	return (new);
}

void	lst_addback(struct ListNode **head,struct ListNode *new)
{
	struct ListNode *current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *head = NULL;
	struct ListNode *new = NULL;

	int isten = 0;
	int data = 0;

	while (l1 || l2 || isten != 0)
	{
		data = isten;
		if (l1 != NULL)
		{
			data += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			data += l2->val;
			l2 = l2->next;
		}

		isten = data / 10;
		data %= 10;
	
		new = ft_lstnew(data);
		lst_addback(&head, new);
	}
	return (head);
}


