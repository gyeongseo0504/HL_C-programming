#include <stdio.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int is_full() {
	return rear >= MAX_SIZE - 1;
}
int is_empty() {
	return front > rear;
}
void enqueue(int value) {
	if (is_full()) {
		printf("ť�� �� �����ȴ粲��~!.\n");
		return;
	}
	queue[++rear] = value;
}
int dequeue() {
	if (is_empty()) {
		printf("�Ƶ� ť ����ڳ� ���� \n");
		return -1;
	}
	return queue[front++];
}
int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printf("�� �� %d\n", dequeue());
	printf("�� �� %d", dequeue());
	return 0;
}