//
// LinkedList.h
// Simple linked list header.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
* @brief Representing a single linked list node.
*/
typedef struct tagNode
{
	/**
	* @brief Representing the next node.
	*/
	void* next;

	/**
	* @brief Representing pointer to the associated data.
	*/
	void* data;
} Node;

/**
* @brief Representing a simple linked list structure.
*/
typedef struct tagLinkedList
{
	/**
	* @brief Representing the address of the first node within the linked list.
	*/
	Node* head;

	/**
	* @brief Representing the pointer to the last item within the linked list.
	*/
	Node* end;

} LinkedList;

/**
* @brief Initializes the given linked list.
* @param list Target linked list.
* @returns Operation result.
*/
int ListInit(LinkedList* list);

/**
* @brief Frees the given linked list.
* @param list Target linked list.
* @returns Operation result.
*/
int ListFree(LinkedList* list);

/**
* @brief Gets the length of the linked list.
* @param list Target linked list.
* @returns Length of the given linked list.
*/
int ListLength(LinkedList* list);

/**
* @brief Pushes the item to the end of the linked list.
* @param list The target linked list.
* @param dataToCopy Data to be copied into the list node.
* @param dataSize Size of the input data.
* @returns Operation result.
*/
int ListPush(LinkedList* list, void* dataToCopy, size_t dataSize);

/**
* @brief Pops the last node from the given linked list.
* @param list The target linked list.
* @param outData The popped item.
* @param dataSize Size of the data.
* @returns Operation result.
*/
int ListPop(LinkedList* list, void* outData, size_t dataSize);

#endif // !LINKEDLIST_H