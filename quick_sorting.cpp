#include <iostream>
using namespace std;

void quick_sorting(int b[],int size,int L,int R)
{
	if(L<R)
	{
		int l = L + 1;
		int r = R;
		while(1)
		{
			for(int i = L + 1 ; i <= R ; i++)
			{
				if(b[i] >= b[L])
				{
					l = i;
					break;
				}
				l++;
			}
			for(int j = R ; j >= L + 1 ; j--)
			{
				if(b[j] <= b[L])
				{
					r = j;
					break;
				}
				r--;
			}
			if(l<r)
			{
				int tmp = b[l];
				b[l] = b[r];
				b[r] = tmp; 
			}
			else
			{
				break;
			}
		}
		if(l>=r)
		{
			int tmp = b[L];
			b[L] = b[r];
			b[r] = tmp;
			
			quick_sorting(b,size,L,r - 1);
			quick_sorting(b,size,r + 1,R);
		}
		
		
	}
}

void print_arr(int b[])
{
	cout << "±Æ§Çµ²ªG : ";
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << b[i] << " ";
	}
	cout << "\n";
}

int main ()
{
	int c[5] = {55,23,87,62,16};
	
	quick_sorting(c,5,0,4);
	
	print_arr(c);
	
    return 0;
}

