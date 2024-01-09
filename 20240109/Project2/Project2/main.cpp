#include <stdio.h>
#define MAX_SIZE 100
int lowS[MAX_SIZE], highS[MAX_SIZE], midS[MAX_SIZE];
int top = -1;
void push(int low, int high, int mid) {
	if (top >= MAX_SIZE - 1) {
		printf("스택이 꽉 찼습니다.\n");
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
		printf("스택이 비어있습니다.\n");
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
			if (arr[mid] == key) return mid; // 키를 찾은 경우
			if (arr[mid] > key) {
				push(low, mid - 1, -1); // 왼쪽 부분 탐색
			}
			else {
				push(mid + 1, high, -1); // 오른쪽 부분 탐색
			}
		}
	}
	return -1; // 키를 찾지 못한 경우
}
int menu(int arr[], int n) {
	int key;
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n찾을 값을 입력하세요: ");
	scanf_s("%d", &key); // scanf_s를 scanf로 변경
	return key;
}
2024 - 01 - 09 3
int main() {
	int arr[] = { 2, 3, 4, 10, 21, 33, 45, 61, 78, 81 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = menu(arr, n);
	int result = binarySearch(arr, n, key);
	if (result != -1)
		printf("원소 %d는 인덱스 %d에 있습니다.\n", key, result);
	else
		printf("원소를 찾을 수 없습니다.\n");
	return 0;
}