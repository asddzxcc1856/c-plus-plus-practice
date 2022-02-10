#include <iostream>
using namespace std;


int merge(int arr[],int temp[],int L,int M,int R)
{
	int i,j,k;
	i = L;
	k = L;
	j = M;
	int inv = 0;
	while((i <= M - 1) && (j <= R))
	{
		if(arr[i] <= arr[j])
		{
			temp[k++] = arr[i++]; 
		}
		else
		{
			temp[k++] = arr[j++]; 
			
			inv += (M - i);
		}
	}
	
	while(i <= M - 1)
	{
		temp[k++] = arr[i++];
	}
	while(j <= R)
	{
		temp[k++] = arr[j++];
	}
	
	for(i = L ; i <= R ; i++)
		arr[i] = temp[i];
	
	return inv;
}

int mergesort2(int arr[],int temp[],int L,int R)
{
	int inv = 0,mid;
	if(L < R)
	{
		mid = (L + R) >> 1;
		inv += mergesort2(arr,temp,L,mid);
		inv += mergesort2(arr,temp,mid + 1,R);
	
		inv += merge(arr,temp,L,mid + 1,R);
	}
	return inv;
}

int mergesort(int arr[],int size)
{
	int temp[size];
	return mergesort2(arr,temp,0,size - 1); 
}
int main ()
{
	int a[] = { 1, 20, 6, 4, 5 };
	cout << mergesort(a,5) << "\n";	
} 
