#include <iostream>
#include <algorithm>
using namespace std;

struct s{
	char ch;
	int times;
};

bool cmp (s a,s b)
{
	if(a.times != b.times)
	{
		return a.times < b.times;
	}
	return a.ch > b.ch;
}

string str;
s c[130];
bool ok;

int main ()
{
	ok = false;
	while(getline(cin,str))
	{
		if(ok)
			cout << "\n";
			
		for (int i = 0 ; i < 130 ; i++)
		{
			c[i].ch = i;
			c[i].times = 0;
		}
		for (int i = 0 ; i < str.length() ; i++)
		{
			c[str[i]].times++;
		}
		sort(c,c+130,cmp);
		for (int i = 0 ; i < 130 ; i++)
		{
			if(c[i].times!=0)
			{
				cout << (int)c[i].ch << " " << c[i].times << "\n";
			}
		}
		ok = true;
	}
	

    return 0;
}

