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
		printf("ť�� ���� á���ϴ�.\n");
		return;
	}
	queue[rear] = value;
	rear = (rear + 1) % MAX_SIZE;
}
int dequeue() {
	if (is_empty()) {
		printf("ť�� ����ֽ��ϴ�.\n");
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
	printf("1. ť�� ���� �Է�\n");
	printf("2. ť�� ����ϰ� �ʱ�ȭ\n");
	printf("3. ����\n");
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
			printf("���� �Է��ϼ���: ");
				scanf_s("%d", &n);
			enqueue(n);
			break;
		case 2:
			while (!is_empty())
				printf("%d ", dequeue());
			break;
		case 3:
			printf("�����մϴ�.");
			return 0;
		}
	}
	return 0;
}