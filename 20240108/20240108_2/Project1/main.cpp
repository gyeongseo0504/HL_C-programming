#include <stdio.h>




int search_binaryRecur(int list[], int low, int high, int key)
{
	int middle = (low + high) / 2;
	if (low > high) 
	{
		return -1;
	}
	if (list[middle] == key)
	{
		return middle;
	}
	if (list[middle] > key)
	{
		return search_binaryRecur(list, low, middle - 1, key);
		return search_binaryRecur(list, middle + 1, high, key);
	}
}
int main(void) 
{
	int list[18] = { 4, 9, 11, 24, 29, 30, 37, 38, 39, 49 ,50 , 84 , 45 , 60 ,70 };
	int n;
	int low = 0;
	int high = sizeof(list) / sizeof(list[0]) - 1;

	for (int i = 0; i < 18; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n\n위 배열에서 찾으실 정수를 입력하세요: ");
	scanf_s("%d", &n);

	int num = search_binaryRecur(list, low, high, n);

	if (num != -1)
	{
		printf("인덱스 %d에 있습니다.", num);
	}
	else

	{
		printf("배열 안에 존재하지 않는 수입니다.");
	}
}