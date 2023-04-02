
// sumarray linear binary search using recurrsion checking whether array is sorted or not
#include <iostream>
using namespace std;

int sumArray(int arr[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    else
    {
        int sum = arr[0] + arr[1];
        sum += sumArray(arr + 2, size - 2);
        return sum;
    }
}
bool issorted(int arr[], int size)
{
    // checking array is sorted with the help of recursion

    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
        return false;
    else
    {
        bool remaining = issorted(arr + 1, size - 1);
        return remaining;
    }
}
bool linearsearch(int arr[], int size, int k)
{
    if (size == 0)
        return false;
    if (arr[0] == k)
        return true;
    else
    {
        bool remaining = linearsearch(arr + 1, size - 1, k);

            return remaining;
    }
}
bool binarysearch(int arr[ ] , int s , int e , int k)
{//base case
if(s>e)
return false; 

int mid = s+ (e-s)/2;
if(arr[mid] == k)
return true; 
if(arr[mid] < k)
{
    return binarysearch(arr, mid+1 , e , k );

}
else
{
    return binarysearch(arr, s , mid-1 , k);
}
}

int main()
{
    int arr[5] = {2, 4 , 6 , 8 , 10};
    int size = 5;
    int k = 4;
    int ans = linearsearch(arr, size , k);

    /*if(ans)
    {
        cout<<"array sorted";
    }
    else
    cout<<"not sorted";*/
    cout << ans;
    return 0;
}