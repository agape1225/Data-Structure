#include "DoubledLinkedList.h"

DoubledLinkedList::DoubledLinkedList()
{
	head = tail = nullptr;
}



DoubledLinkedList::~DoubledLinkedList()
{
	resetList();
	printf("\n리스트가 최기화 되었습니다.\n");
}


bool DoubledLinkedList::insertNode(int n) {
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->data = n;
		if (head || tail) {
			tail->rLink = pNew;
			pNew->lLink = tail;
			pNew->rLink = head;
			head->lLink = tail = pNew;
		}
		else {
			pNew->rLink = pNew->lLink = pNew;
			head = tail = pNew;
		}
		return true;
	}
	return false;
}

 NodePtr DoubledLinkedList::searchNode(int n) {
	 
	 if (head || tail) {
		 NodePtr search = head->rLink;
		 while (search->data != n && search != head)
			 search = search->rLink;
		 if (head->data == n || search->data == n)
			 return search;
		 else
			 return nullptr;
	 }
	 else
		 return nullptr;

}

 bool DoubledLinkedList::deleteNode(int n) {
	 NodePtr pDel = searchNode(n);
	 if (pDel) {
		 if (pDel == head && pDel == tail)
			 head = tail = nullptr;
		 else {
			 if (pDel == head)
				 head = pDel->rLink;
			 else if (pDel == tail)
				 tail = pDel->lLink;
			 NodePtr rNode = pDel->rLink;
			 NodePtr lNode = pDel->lLink;
			 rNode->lLink = lNode;
			 lNode->rLink = rNode;
		 }
		 delete pDel;
	 }
	 else
		 return false;
 }

 void DoubledLinkedList::printList() {
	 
	 if (head) {
		 for (NodePtr buff = head; buff != tail; buff = buff->rLink)
			 printf("%d <--> ", buff->data);
		 printf("%d", tail->data);
	 }
	 else
		 printf("empty list");
 }

 void DoubledLinkedList::resetList() {
	 while (head != nullptr) 
		 deleteNode(tail->data);
	 
 }