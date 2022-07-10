#include <iostream>
#include <cstring>
#include <map>
#define MAXN (1 << 20)
using namespace std;

bool arr[MAXN + 5];
map<int,int> m[25];
int depth,idx;

int main ()
{
	
	int t;

	while(cin >> t)
	{
		if(t == -1)
		{
			return 0;
		}
		for(int k = 1 ; k <= t ; k++)
		{
			int D,I;
			cin >> D >> I;	
			I -= 1;
			depth = 1;
			idx = 1;
			while(depth != D)
			{	
				int next = I%2;
				I/=2;
				if(next == 0)
				{
					idx = idx << 1;
				}
				else
				{
					idx = (idx << 1) + 1;
				}
				depth++;
			}
			cout << idx << "\n";
		}
	}
}