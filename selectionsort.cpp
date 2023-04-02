#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[k])
                k = j;
        swap(arr[k], arr[i]);
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
    cout << "Unsorted array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    cout << "Sorted array:";
    printArray(arr, n);
    return 0;
}