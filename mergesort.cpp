#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int p, int r)
{
    if (p >= r)
        return;
    int mid = p + (r - p) / 2;
    mergeSort(a, p, mid);
    mergeSort(a, mid + 1, r);
    merge(a, p, mid, r);
}
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    cout << "Given array is:" << endl;
    display(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array is:" << endl;
    display(arr, n);
    return 0;
}