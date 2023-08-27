#include <iostream>
#include <algorithm>
using namespace std;

struct ant{
	double downward;
	int vol;
	int L,W,H;
};

ant ants[100];

bool cmp (ant a,ant b)
{
	if(a.downward != b.downward)
	{
		return a.downward < b.downward;
	}
	else
	{
		return a.vol < b.vol;
	}
}

int main ()
{
	int n;
	while(cin >> n,n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			cin >> ants[i].L >> ants[i].W >> ants[i].H;
			ants[i].downward = 1.0f - ((double)1/(2*ants[i].H));
			ants[i].vol = ants[i].L * ants[i].W * ants[i].H;
		}
		sort(ants,ants + n,cmp);
		cout << ants[n - 1].vol << "\n";
	}
}
