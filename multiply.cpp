#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int mini = INT_MAX;
	int count;

	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		mini = min(count, mini);
	}
	return mini;
}


int main()
{
	 int n; 
	 cin>>n;
	int arr[n] ;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	cout << "required number of multiplication are  "
		 << MatrixChainOrder(arr, 1, n - 1);

	return 0;
}