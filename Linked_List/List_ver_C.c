#include <stdio.h>

typedef struct list {
	int item;
	struct list *link;
} Node, *NodePtr;

NodePtr CreateNode(int n);
NodePtr InsertNode(NodePtr head, int prev, int n);
NodePtr DeleteNode(NodePtr head, int n);
void PrintList(NodePtr head);

int main(void) {
	NodePtr head = NULL;
	
	while (1) {
		int input, size;
		int prev;
		printf("[Creat: 1 Insert: 2, Delete: 3 Exit: 4]");
		scanf("%d", &input);

		switch (input) {
		case 1:
			printf("Size? ");
			scanf("%d", &input);
			head = CreateNode(input);
			break;
		case 2:
			printf("position? ");
			scanf("%d", &prev);
			printf("Num? ");
			scanf("%d", &input);
			InsertNode(head, prev, input);
			break;
		case 3:
			printf("Num? ");
			scanf("%d", &prev);
			head = DeleteNode(head, prev);
			break;
		default:
			return 0;
		}
		PrintList(head);
	}
}

NodePtr CreateNode(int n) {
	NodePtr head, last;
	NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	pNew->item = 1;
	head = last = pNew;
	for (int i = 2; i <= n; i++) {
		NodePtr pNew = (NodePtr)malloc(sizeof(Node));
		if (pNew) {
			pNew->item = i;
			last->link = pNew;
			last = pNew;
			last->link = NULL;
		}
		else
			return NULL;
	}
	return head;
}

NodePtr InsertNode(NodePtr head, int prev, int n) {
	NodePtr label = head;
	while (label->item != prev && label)
		label = label->link;
	NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	if (pNew) {
		pNew->item = n;
		pNew->link = label->link;
		label->link = pNew;
	}
	return head;
}

NodePtr DeleteNode(NodePtr head, int n) {
	NodePtr del, index;
	index = head;
	while ((index->link)->item != n && index)
		index = index->link;
	if (index) {
		del = index->link;
		index->link = del->link;
		free(del);
	}
	else
		printf("존재하지 않는 요소 입니다.");
	return head;
}

void PrintList(NodePtr head) {
	NodePtr pointer;
	pointer = head;
	while (1) {
		if (pointer->link) {
			printf("%d --> ", pointer->item);
			pointer = pointer->link;
		}
		else {
			printf("%d\n\n",pointer->item);
			break;
		}
	}
}
