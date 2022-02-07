#include <iostream>
#include <algorithm>
using namespace std;

struct dragon{
	int strength;
	int	bonus;
};

bool cmp(dragon a,dragon b)
{
	return a.strength < b.strength;
}

int main ()
{
	int s,n;
	dragon c[1005];
	cin >> s >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> c[i].strength >> c[i].bonus;
		
	sort(c,c+n,cmp);	
	 
	bool win = true;
	for(int i = 0 ; i < n ; i++)
	{
		if(c[i].strength < s)
		{
			s += c[i].bonus;
		}	
		else
		{
			win = false;
			break;
		}
	} 
	if(win)
		cout << "YES\n";
	else
		cout << "NO\n";
}
