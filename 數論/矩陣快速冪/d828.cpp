#include <iostream>
#include <cstring>
using namespace std;

long long int mod = 10000;

struct mat{
	long long int a[2][2];
	
	mat()
	{
		memset(a,0,sizeof(a));	
	}
	
	mat operator * (const mat &b)
	const{
		mat ret;
		for(int i = 0 ; i < 2 ; i++)
			for(int j = 0 ; j < 2 ; j++)
				for(int k = 0 ; k < 2 ; k++)
					ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j])%mod;
		return ret;
	}
		
};
mat f;
int main ()
{
	int m,n;
	while(cin >> n)
	{
		
		mat ret;
		ret.a[0][0] = 1;
		ret.a[1][0] = 0;
		f.a[0][0] = 1;
		f.a[1][0] = 1;
		f.a[0][1] = 1;
		f.a[1][1] = 0;
		while(n)
		{
			if(n&1)
			{
				ret = f * ret;
			}
			f = f * f;	
			n >>= 1;
		}
		cout << ret.a[0][0] << "\n"; 
		
		
	}
} 
