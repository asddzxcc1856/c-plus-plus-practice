#include <iostream>
using namespace std;

int count(int n)
{
	int cnt = 1;
	while(n!=1)
	{
		if(n%2==0)
		{
			n = n/2;
		}
		else
		{
			n = n * 3 + 1;
		}
		cnt++;
	}
	return cnt;
}

int main ()
{
	int a,b;
	while(cin >> a >> b)
	{
		int start,end;
        if (a<b){
            start=a;
            end=b;
        }
        else{
            start=b;
            end=a;
        }
        int maxn=0;
        for (int i=start;i<=end;i++)
		{
			maxn = max(count(i),maxn);
		}	
		cout << a << " " << b; 
		cout << " " << maxn << endl;
	}		
} 

