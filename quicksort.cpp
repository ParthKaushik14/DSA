#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = (s - 1);
    for (int j = s; j <= e - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return (i + 1);
}
void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int q = partition(arr, s, e);
        quickSort(arr, s, q - 1);
        quickSort(arr, q + 1, e);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {2, 8, 7, 1, 3, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    display(arr, n);

    return 0;
}