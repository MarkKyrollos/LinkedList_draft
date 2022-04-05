//#include "LinkedList.h"
//
//LinkedList::LinkedList()
//{
//	head = NULL;
//	numberOfElements = 0;
//}
//
//int LinkedList::getNumberOfElements()
//{
//	return numberOfElements;
//}
//
//
//void LinkedList::addFirst(int data)
//{
//	if (head == NULL)
//	{
//		head = new Node;
//		head->value = data;
//		head->next = NULL;
//	}
//	else
//	{
//		Node* temp = new Node;
//		temp->value = data;
//		temp->next = head;
//		head = temp;
//	}
//}
//
//void LinkedList::addLast(int data)
//{
//	while (head->next != NULL)
//	{
//		head = head->next;
//	}
//
//	/*Node* temp = new Node;
//	temp->value = data;
//	temp->next = head;
//	head = temp;*/
//}
//
//void LinkedList::insert(int data, int index)
//{
//	
//}