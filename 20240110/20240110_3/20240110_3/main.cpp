#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = 0;
int rear = 0;
int is_full() {
	return (rear + 1) % MAX_SIZE == front;
}
int is_empty() {
	return front == rear;
}
void enqueue(int value) {
	if (is_full()) {
		printf("큐가 가득 찼습니다.\n");
		return;
	}
	queue[rear] = value;
	rear = (rear + 1) % MAX_SIZE;
}
int dequeue() {
	if (is_empty()) {
		printf("큐가 비어있습니다.\n");
		return -1;
	}
	int value = queue[front];
	front = (front + 1) % MAX_SIZE;
	return value;
}
int menu(void)
{
	int n;
	printf("\n====================\n");
	printf("1. 큐에 값을 입력\n");
	printf("2. 큐를 출력하고 초기화\n");
	printf("3. 종료\n");
	printf("====================\n");
	scanf_s("%d", &n);
	return n;
}
int main() {
	int n;
	while (1)
	{
		switch (menu())
		{
		case 1:
			printf("값을 입력하세요: ");
				scanf_s("%d", &n);
			enqueue(n);
			break;
		case 2:
			while (!is_empty())
				printf("%d ", dequeue());
			break;
		case 3:
			printf("종료합니다.");
			return 0;
		}
	}
	return 0;
}