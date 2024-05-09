#include <stdio.h>
# define MAX 10

int* bubble_sort(int arr[], int n) 
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--) 
    {
        for (j = 0; j < i; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;

}

int main() 
{
    int arr[MAX] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    int* arr_new = bubble_sort(arr, MAX);
    for (int i = 0; i < MAX; i++) 
    {
        printf(" %d ", *(arr_new + i));
    }
    return 0;
}