#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct word{
	char ch;
	int order;
};

word w[25];
unsigned long long int f[21];
deque<int> d;

bool cmp(word a,word b)
{
	return a.order < b.order;
}

void cnt(unsigned long long int number,int len,int now)
{
	if(len == 0)
	{
		return;
	}
	for(unsigned long long int i = 1 ; i <= len ; i++)
	{
		if(f[len - 1] < number)
		{
			number -= f[len - 1];
		}
		else
		{
			w[now].order = d[i - 1];
			d.erase(d.begin() + i - 1);
			cnt(number,len - 1,now + 1);
			break;
		}
	}
}


int main ()
{
	
	f[0] = 1;
	for(unsigned long long int i = 1 ; i < 21 ; i++)
	{
		f[i] = f[i - 1] * (i);
	} 
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		d.clear();
		string str;
		long long int num;
		cin >> str >> num;
		for(int i = 0 ; i < str.length() ; i++)
		{
			d.push_back(i + 1);
			w[i].ch = str[i];
		}
		cnt(num,str.length(),0);
		sort(w,w+str.length(),cmp);
		cout << "Case " << k << ": ";
		for(int i = 0 ; i < str.length() ; i++)
		{
			cout << w[i].ch;
		}
		cout << "\n";
	}
}