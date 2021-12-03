#include <iostream>
using namespace std;

long long int m,n,i,cnt;

int main()
{
    while(cin >> m >> n)
    {
        cnt = 0;
        for(i = m ; ; i++)
        {
            cnt += i;
            if(cnt >= n)
            {
                cout << i << "\n";
                break;
            }
        }
        
    }
    return 0;
}
