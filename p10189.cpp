#include <iostream>
#include <cstring>
using namespace std;

int m,n,i,j,k,w,cnt,times;
char adj[105][105] = {};

int main()
{
    times = 1;
    while(cin >> m >> n)
    {
        if(m == 0 && n == 0)
            return 0;
        if(times > 1)
        {
            cout << "\n";
        }
        cout << "Field #" << times++ << ":\n";
        memset(adj,0,sizeof(adj));
        for (i = 1 ; i <= m ; i++)
        {
            for(j = 1 ; j <= n; j++)
            {
                cin >> adj[i][j];
            }
        }
        for (i = 1 ; i <= m ; i++)
        {
            for(j = 1 ; j <= n; j++)
            {
                if(adj[i][j] == '.')
                {
                    cnt = 0;
                    for(k = i - 1 ; k <= i + 1 ; k++)
                    {
                        for (w = j - 1 ; w <= j + 1 ; w++)
                        {
                            if(adj[k][w] == '*')
                            {
                                cnt++;
                            }
                        }
                    }
                    adj[i][j] = cnt + '0'; 
                }
            }
        }
        for (i = 1 ; i <= m ; i++)
        {
            for(j = 1 ; j <= n; j++)
            {
                cout << adj[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
