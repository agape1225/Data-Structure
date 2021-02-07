#include <stdio.h>
#define SIZE 100

void Push(int stack[], int *top);
int Pop(int stack[], int *top);
int isFull(int top);
int isEmpty(int top);
void PrintError(char *msg);


int main(void) {
	int stack[SIZE];
	int top = -1;

	while (1) {
		int input;
		printf("[push: 1  pop: 2  exit: 3]");
		scanf("%d", &input);

		if (input == 1) {
			Push(stack, &top);
			printf("\n");
		}
		else if (input == 2) {
			int buff = Pop(stack, &top);
			if(buff)
				printf("Pop: %d\n\n", buff);
		}
		else
			break;
	}
	return 0;
}

void Push(int stack[], int *top) {
	if (isFull(++(*top))) {
		(*top)--;
		PrintError("스택이 포화상태입니다.");
	}
	else {
		int item;
		printf("정수: ");
		scanf("%d", &item);
		stack[*top] = item;
	}
}

int Pop(int stack[], int *top) {
	if (isEmpty(*top)) {
		PrintError("스택이 비어있습니다.");
		return NULL;
	}
	return stack[(*top)--];
}

int isFull(int top) {
	return top >= SIZE ? 1 : 0;
}

int isEmpty(int top) {
	return top == -1 ? 1 : 0;
}

void PrintError(char *msg) {
	printf("-----%s-----\n\n", msg);
}