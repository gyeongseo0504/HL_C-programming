#include <stdio.h>
#define MAX_SIZE 100
int lowS[MAX_SIZE], highS[MAX_SIZE], midS[MAX_SIZE];
int top = -1;
void push(int low, int high, int mid) {
	if (top >= MAX_SIZE - 1) {
		printf("������ �� á���ϴ�.\n");
		return;
	}
	lowS[++top] = low;
	highS[top] = high;
	midS[top] = mid;
}
int isStackEmpty() {
	return top == -1;
}
void pop(int* low, int* high, int* mid) {
	if (isStackEmpty()) {
		printf("������ ����ֽ��ϴ�.\n");
		*low = -1;
		*high = -1;
		*mid = -1;
		return;
	}
	*low = lowS[top];
	*high = highS[top];
	*mid = midS[top];
	top--;
	2024 - 01 - 09 2
}
int binarySearch(int arr[], int n, int key) {
	push(0, n - 1, -1);
	while (!isStackEmpty()) {
		int low, high, mid;
		pop(&low, &high, &mid);
		if (mid == -1) {
			mid = low + (high - low) / 2;
		}
		if (low <= high) {
			if (arr[mid] == key) return mid; // Ű�� ã�� ���
			if (arr[mid] > key) {
				push(low, mid - 1, -1); // ���� �κ� Ž��
			}
			else {
				push(mid + 1, high, -1); // ������ �κ� Ž��
			}
		}
	}
	return -1; // Ű�� ã�� ���� ���
}
int menu(int arr[], int n) {
	int key;
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nã�� ���� �Է��ϼ���: ");
	scanf_s("%d", &key); // scanf_s�� scanf�� ����
	return key;
}
2024 - 01 - 09 3
int main() {
	int arr[] = { 2, 3, 4, 10, 21, 33, 45, 61, 78, 81 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = menu(arr, n);
	int result = binarySearch(arr, n, key);
	if (result != -1)
		printf("���� %d�� �ε��� %d�� �ֽ��ϴ�.\n", key, result);
	else
		printf("���Ҹ� ã�� �� �����ϴ�.\n");
	return 0;
}