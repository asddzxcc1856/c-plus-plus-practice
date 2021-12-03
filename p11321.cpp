#include <iostream>
#include <algorithm>
using namespace std;

struct s{
	int num;
	int modlus_value;
};

s c[10005];
int n,mod,i;

bool cmp(s a,s b)
{
	if(a.modlus_value != b.modlus_value)
		return a.modlus_value < b.modlus_value;
	if(a.num % 2 == 0 && b.num % 2 == 0)
		return a.num < b.num;
	if(a.num % 2 != 0 && b.num % 2 == 0)
		return true;
	if(a.num % 2 == 0 && b.num % 2 != 0)
		return false;
	if(a.num % 2 != 0 && b.num % 2 != 0)
		return a.num > b.num;
}

int main ()
{
	while(cin >> n >> mod)
	{
		if(n == 0 && mod == 0)
		{
			cout << "0 0\n";
			return 0;
		}
			
		for(i = 0 ; i < n ; i++)
		{
			cin >> c[i].num;
		
			c[i].modlus_value = c[i].num%mod; 
		}	
		sort(c,c+n,cmp);
		cout << n << " " << mod << "\n";
		for(i = 0 ; i < n ; i++)
		{
			cout << c[i].num << "\n";
		}
	}	

    return 0;
}

