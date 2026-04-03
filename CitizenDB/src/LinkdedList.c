#include <stdlib.h>
#include "../inc/LinkedList.h"

int ListInit(LinkedList* list)
{
	if (list == NULL) return -1;
	list->head = NULL;
	list->end = NULL;
	return 0;
}

int ListFree(LinkedList* list) {
	if (list == NULL) return -1;
	Node* ptr = list->head;

	while (ptr != NULL)
	{
		Node* nextNode = ptr->next;
		free(ptr);
		ptr = nextNode;
	}

	// reset for safety
	list->head = NULL;
	list->end = NULL;
	return 0;
}

int ListLength(LinkedList* list)
{
	int count = 0;
	Node* ptr = list->head;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

int ListPush(LinkedList* list, Node node) {
	if (list == NULL) return -1;

	Node* addr = (Node*)malloc(sizeof(Node));
	if (addr == NULL) return -1;

	addr->data = node.data;
	addr->next = NULL;

	if (list->head == NULL) {
		// pushing first item
		list->head = addr;
		list->end = addr;
	}
	else {
		// push to the end
		list->end->next = addr;
		list->end = addr;
	}
	return 0;
}

int ListPop(LinkedList* list, Node* retItem)
{
	if (list == NULL || list->head == NULL)
	{
		return -1;
	}

	if (list->head == list->end)
	{
		retItem->data = list->head->data;
		retItem->next = NULL;

		// free the memory
		free(list->head);

		// fix the list
		list->head = NULL;
		list->end = NULL;
		return 0;
	}

	Node* ptr = list->head;
	while (ptr != NULL)
	{
		if (ptr->next != list->end)
		{
			ptr = ptr->next;
		}

		else break;
	}

	Node* last = ptr->next;
	ptr->next = NULL;

	retItem->data = last->data;
	retItem->next = NULL;

	free(last);
	list->end = ptr;

	return 0;
}