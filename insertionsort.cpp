#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    cout << "Unsorted array :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, n);
    cout << "Sorted array:";
    printArray(arr, n);
    return 0;
}
