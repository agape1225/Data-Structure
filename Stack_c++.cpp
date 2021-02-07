#include <cstdio>
#define SIZE 100

class Stack {
private:
	int arr[SIZE];
	int top;

public:
	Stack() { top = -1; }
	void Push();
	int Pop();
	int isFull();
	int isEmpty();
	void PrintError(const char *msg);
};

void Stack:: Push() {
	top += 1;
	if (isFull()) {
		top -= 1;
		PrintError("함수가 포화상태입니다.");
	}
	else {
		int item;
		printf("정수: ");
		scanf("%d", &item);
		arr[top] = item;
	}
}

int Stack::Pop() {
	if (isEmpty()) {
		PrintError("스택이 비어있습니다.");
		return false;
	}
	else
		return arr[top--];
}

int Stack::isFull() {
	return top >= SIZE ? true : false;
}

int Stack::isEmpty() {
	return top == -1 ? true : false;
}

void Stack::PrintError(const char *msg) {
	printf("-----%s-----\n\n", msg);

}


int main(void) {
	
	Stack stack;

	while (1) {
		int input;
		printf("[push: 1  pop: 2  exit: 3]");
		scanf("%d", &input);

		if (input == 1) {
			stack.Push();
			printf("\n");
		}
		else if (input == 2) {
			int buff = stack.Pop();
			if (buff)
				printf("Pop: %d\n\n", buff);
		}
		else
			break;
	}
	return 0;
}