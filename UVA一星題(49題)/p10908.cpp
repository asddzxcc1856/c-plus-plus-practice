#include <iostream>
#include <cstring>
using namespace std;

bool ok;
int t,m,n,q,i,j,k,w,a,b,cnt;
char adj[105][105];
char ch;

int main ()
{
	cin >> t;
	for (k = 0 ; k < t ; k++)
	{
		memset(adj,0,sizeof(adj));
		cin >> m >> n >> q;
		for (i = 0 ; i < m ; i++)
		{
			for (j = 0 ; j < n ; j++)
			{
				cin >> adj[j][i]; 
			}
		}
		cout << m << " " << n << " " << q << "\n"; 
		for (i = 0 ; i < q ; i++)
		{
			cin >> a >> b;
			ok = true;
			cnt = 1;
			ch = adj[b][a];
			while(ok)
			{
				for(j = a - (cnt/2) ; j <= a + (cnt/2) && ok ; j++)
				{
					for (w = b - (cnt/2) ; w <= b + (cnt/2) && ok; w++)
					{
						if(w < 0 || w >= n || j < 0 || j >= m || adj[w][j] != ch)
						{
							ok = false;	
						}	
					}	
				}
				if(ok == true)
				{
					cnt += 2;
				}	
				else if(cnt!=1 && ok ==false)
				{
					cnt -= 2;
				}
			}
			cout << cnt << "\n"; 
		}
		
	}
    return 0;
}

