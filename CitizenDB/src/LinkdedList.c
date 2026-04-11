#include <stdlib.h>
#include <string.h>

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

	while (ptr != NULL) {
		Node* nextNode = ptr->next;
		free(ptr->data);
		free(ptr);
		ptr = nextNode;
	}
	list->head = NULL;
	list->end = NULL;
	return 0;
}

int ListLength(LinkedList* list)
{
	if (list == NULL)
	{
		return -1;
	}

	int count = 0;
	Node* ptr = list->head;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

int ListPush(LinkedList* list, void* dataToCopy, size_t dataSize) {
	if (list == NULL || dataToCopy == NULL) return -1;

	Node* addr = (Node*)malloc(sizeof(Node));
	if (addr == NULL) return -1;

	addr->data = malloc(dataSize);
	if (addr->data == NULL) {
		free(addr);
		return -1;
	}

	memcpy(addr->data, dataToCopy, dataSize);
	addr->next = NULL;

	if (list->head == NULL) {
		list->head = addr;
		list->end = addr;
	}
	else {
		list->end->next = addr;
		list->end = addr;
	}
	return 0;
}

int ListPop(LinkedList* list, void* outData, size_t dataSize)
{
	if (list == NULL || list->head == NULL || outData == NULL)
	{
		return -1;
	}

	Node* targetNode = list->end;

	memcpy(outData, targetNode->data, dataSize);

	if (list->head == list->end)
	{
		free(targetNode->data);
		free(targetNode);
		list->head = NULL;
		list->end = NULL;
	}

	else
	{
		Node* ptr = list->head;
		while (ptr->next != list->end)
		{
			ptr = ptr->next;
		}

		free(targetNode->data);
		free(targetNode);

		ptr->next = NULL;
		list->end = ptr;
	}

	return 0;
}