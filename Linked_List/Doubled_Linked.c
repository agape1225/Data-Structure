#include <stdio.h>

typedef struct node {
	int nData;
	struct node *rLink;
	struct node *lLink;
} Node, *NodePtr, *ListPtr;

NodePtr CreateNode(int n);
NodePtr InsertNode(NodePtr head, int prev, int n);
NodePtr DeleteNode(NodePtr head, int n);
void PrintList(NodePtr head);

int main(void) {
	NodePtr ptr = NULL;

	while (1) {
		int input, size;
		int prev;
		printf("[Creat: 1 Insert: 2, Delete: 3 Exit: 4]");
		scanf("%d", &input);

		switch (input) {
		case 1:
			printf("Size? ");
			scanf("%d", &input);
			ptr = CreateNode(input);
			break;
		case 2:
			printf("position? ");
			scanf("%d", &prev);
			printf("Num? ");
			scanf("%d", &input);
			InsertNode(ptr, prev, input);
			break;
		case 3:
			printf("Num? ");
			scanf("%d", &prev);
			ptr = DeleteNode(ptr, prev);
			break;
		default:
			return 0;
		}
		PrintList(ptr);
	}
}

NodePtr CreateNode(int n) {
	NodePtr ptr;
	ptr = NULL;
	for (int i = 1; i <= n; i++) {
		NodePtr pNew = (NodePtr*)malloc(sizeof(Node));
		if (pNew) {
			pNew->nData = i;
			if (ptr) {
				NodePtr last = ptr->lLink;
				last->rLink = pNew;
				pNew->lLink = last;
				pNew->rLink = ptr;
				ptr->lLink = pNew;
			}
			else {
				ptr = pNew->rLink = pNew->lLink = pNew;
			}
		}
	}
	return ptr;
}

NodePtr InsertNode(NodePtr head, int prev, int n) {
	NodePtr buff = head;
	if (head) {
		do {
			if (buff->nData == prev)
				break;
			buff = buff->rLink;
			if (buff == head)
			{
				printf("찾으려는 정수가 없습니다.");
				return NULL;
			}
		} while (1);
	}
	NodePtr pNew = (NodePtr*)malloc(sizeof(Node));
	if (pNew) {
		NodePtr Right = buff->rLink;
		NodePtr Left = buff;
		pNew->nData = n;
		pNew->lLink = Left;
		pNew->rLink = Right;
		Left->rLink = Right->lLink = pNew;
	}

	return head;
}

NodePtr DeleteNode(NodePtr head, int n) {
	NodePtr pDel = head;
	if (head) {
		while (1) {
			if (pDel->nData == n)
				break;
			pDel = pDel->rLink;
			if (pDel->rLink == head)
			{
				printf("찾으려는 정수가 없습니다.");
				return NULL;
			}
		}
	}
	NodePtr Left = pDel->lLink;
	NodePtr Right = pDel->rLink;
	Left->rLink = Right;
	Right->lLink = Left;
	free(pDel);
	return head;
}

void PrintList(NodePtr head) {
	NodePtr buff = head;
	while (1) {
		if (buff->rLink == head) {
			printf("%d\n\n ", buff->nData);
			break;
		}
		printf("%d <---> ", buff->nData);
		buff = buff->rLink;
	}
}