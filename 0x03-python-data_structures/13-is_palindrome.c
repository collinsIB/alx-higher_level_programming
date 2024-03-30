#include "lists.h"

struct Node
{
	int data;
	struct Node* next;
};

/**
 * ispalindrome - function to check if a linked list is a palindrome
 * @head: pointer head
 *
 * Return: Null
 */

bool ispalindrome(struct Node* head)
{
	struct Node* slow = *head;
	struct Node* fast = *head;
	struct Node* prev_slow = *head;
	struct Node* midnode = NULL;
	int res = true;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next-next;
		prev_slow = slow;
		slow = slow->next;
	}
	if (fast != NULL)
	{
		midnode = slow;
		slow = slow->next;
	}

	struct Node* second_half = slow;
	prev_slow->next = NULL;
	struct Node* prev = NULL;
	struct Node* current = second_half;
	struct Node* next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	struct Node* temp1 = *head;
	struct Node* temp2 = prev;

	while (temp1 && temp2)
	{
		if (temp1->data != temp2->data)
		{
			res = false;
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	prev_slow->next = prev;
	if (midnode != NULL)
	{
		midnode->next = second_half;
	}
	return (res);
}
