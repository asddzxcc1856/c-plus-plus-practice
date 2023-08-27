#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

struct word{
	char ch;
	int times;
	
	bool operator==(const word & a)
	{
		if(ch == a.ch)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
};

int num[36] = {2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12};
word w[105];
map<char,int> ma;

bool cmp(word a,word b)
{
	return a.times > b.times;
}


int main ()
{
	int n;
	cin >> n;
	string str;
	getline(cin,str);
	for(int k = 0 ; k < n ; k++)
	{
		getline(cin,str);
		memset(w,0,sizeof(w));
		ma.clear();
		int len = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) && ma.find(str[i]) == ma.end())
			{
				ma[str[i]] = len++;
				w[ma[str[i]]].ch = str[i];
				w[ma[str[i]]].times = 1;
			}
			else if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
			{
				w[ma[str[i]]].times += 1;
			}
		}
		sort(w,w+len,cmp);
		int all = 0;
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
			{
				word temp;
				temp.ch = str[i];
				all += num[find(w,w+len,temp) - w];
			}
			
		}
		cout << all << "\n";
	}
}