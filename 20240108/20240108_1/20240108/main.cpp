#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int binarySearch(int A[], int low, int high, int target) 
{
    while (low <= high) {
        int mid = low + (high - low) / 2; // 중간값 계산 방법 수정
        if (A[mid] == target) return mid;
        if (A[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int binarySearchRecur(int A[], int low, int high, int target) 
{
    if (low > high) return -1;

    int mid = low + (high - low) / 2; // 중간값 계산 방법 수정
    if (A[mid] == target) return mid;
    if (A[mid] > target) 
    {
        return binarySearchRecur(A, low, mid - 1, target);
    }
    return binarySearchRecur(A, mid + 1, high, target); // 매개변수 수정
}

int main() {
    int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    int target = 11;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, target);
    printf("Iterative Binary Search:\n");
    if (result != -1) 
    {
        printf("요소 %d은(는) 인덱스 %d에 있습니다.\n", target, result);
    }
    else {
        printf("배열에서 요소 %d을(를) 찾을 수 없습니다.\n", target);
    }
    return 0;
}
