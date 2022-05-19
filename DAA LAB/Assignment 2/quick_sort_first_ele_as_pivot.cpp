#include <bits/stdc++.h>
using namespace std;

int N;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition1(int a[], int start, int end)
{

    int pivot = a[start], p1 = start + 1, i, temp;

    for (i = start + 1; i <= end; i++)
    {

        if (a[i] < pivot)
        {
            if (i != p1)
            {
                temp = a[p1];
                a[p1] = a[i];
                a[i] = temp;
            }
            p1++;
        }
    }

    a[start] = a[p1 - 1];
    a[p1 - 1] = pivot;

    return p1 - 1;
}

void quicksort(int *a, int start, int end)
{
    int p1;
    if (start < end)
    {
        p1 = partition1(a, start, end);
        quicksort(a, start, p1 - 1);
        quicksort(a, p1 + 1, end);
    }
}

int main()
{
    int arr[] = {7, 8, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    N = n;
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}