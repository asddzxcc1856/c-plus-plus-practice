#include <iostream>
using namespace std;

int arr[100005];
int n,k;

void mergesort(int l,int r)
{
	if(k == 1 || l >= r - 1)
	{
		return;
	}
	int mid = (l + r) >> 1;
	swap(arr[mid - 1],arr[mid]);
	k -= 2;
	mergesort(l,mid);
	mergesort(mid,r);
}

int main ()
{
	
	cin >> n >> k; 
	if(k % 2 == 0)
	{
		cout << "-1\n"; 
	}
	else
	{
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = i + 1;
		}	
		mergesort(0,n);
		
		if(k != 1)
		{
			cout << "-1\n";
		}
		else
		{
			for(int i = 0 ; i < n - 1 ; i++)
			{
				cout << arr[i] << " ";
			}
			cout << arr[n - 1] << "\n";
		}
	}
	
	
}
