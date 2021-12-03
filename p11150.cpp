#include <iostream>
using namespace std;

int n,num,cnt,temp,maxn,borrow,i;

int main ()
{
	while(cin >> n)
	{
		maxn = -2147483648;
		for (i = 0 ;; i++)
		{
			borrow = i;
			num = n + borrow;
			cnt = n;
			while(num >=3)
			{
				temp = num/3;
				cnt += temp;
				num%=3;
				num+=temp;
			}
			
			if(num < borrow)
				break;
			if(cnt>maxn)
				maxn = cnt;
		}
		cout << maxn << "\n";
	}

    return 0;
}

