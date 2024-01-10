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
		printf("큐가 다 차버렸당께ㅔ~!.\n");
		return;
	}
	queue[++rear] = value;
}
int dequeue() {
	if (is_empty()) {
		printf("아따 큐 비었자네 못혀 \n");
		return -1;
	}
	return queue[front++];
}
int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printf("뺀 값 %d\n", dequeue());
	printf("뺀 값 %d", dequeue());
	return 0;
}