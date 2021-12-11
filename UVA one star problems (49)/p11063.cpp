#include <iostream>
#include <cstring>
using namespace std;

int n,i,j,c[105],b[20005],t;
bool ok;


int main ()
{
	t = 1;
	while(cin >> n)
	{
		memset(b,0,sizeof(b));
		ok = true;
		for(i = 0 ; i < n ; i++)
		{
			cin >> c[i]; 
			if(c[i]<1)
				ok = false;
		}
		
		
		for(i = 0 ; i < n ; i++)
		{
			for(j = i ; j < n ; j++)
			{
				if(b[c[i]+c[j]]==0)
					b[c[i]+c[j]]++;
				else
					ok = false;
			}
		}
		for(i = 1 ; i < n ; i++)
		{
			if(c[i] <= c[i - 1])
				ok = false;
		}
		if(ok)
		{
			cout << "Case #" << t++ << ": It is a B2-Sequence.\n\n";
		}
		else
		{
			cout << "Case #" << t++ << ": It is not a B2-Sequence.\n\n";
		}
	}

    return 0;
}

