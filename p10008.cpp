#include <iostream>
#include <algorithm>
using namespace std;

struct ch{
	int num;
	char c;
};

bool cmp(ch a,ch b)
{
	if(a.num!=b.num)
		return a.num > b.num;
	else
		return a.c < b.c;
}

int main ()
{
	int n;
	cin >> n;
	string str;
	getline(cin,str);
	ch C[26];
	for(int i = 0 ; i < 26 ; i++)
	{
		C[i].num = 0;
		C[i].c = 'A' + i;
	}
	for (int k = 0 ; k < n ; k++)
	{
		getline(cin,str);
		for(int i = 0 ; i < str.length() ; i++)	
		{
			if(isalpha(str[i]))
				C[toupper(str[i]) - 'A'].num++;
		}
	}		
	sort(C,C+26,cmp);
	for (int i = 0 ; i < 26 && C[i].num != 0; i++)
	{
		cout << C[i].c << " " << C[i].num << "\n";
	}
	
	return 0;
} 
