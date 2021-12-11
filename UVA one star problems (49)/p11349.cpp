#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

long long int matrix[10005];

int main ()
{
	long long int t,k,num,all,i,j;
	scanf("%ld",&t);
	string str;
	
	for(k = 0 ; k < t ; k++)
	{
		getline(cin,str);
		//cout << str << "\n"; 
		int po = 0;
		for (i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '=')
			{
				po = i + 2;
				break;
			}
		}
		num = 0;
		for (i = po ; i < str.length() ; i++)
		{
			num = num * 10 + (str[i] - '0');
		}
		all = num*num;
		for(i = 0 ; i < all ; i++)
			scanf("%ld",&matrix[i]);
		bool ok = true; 
		for(j = 0 ; j <= all/2 ; j++)
		{
			if(matrix[j] != matrix[all - 1 - j])
			{
				ok = false;
			}
			else if (matrix[j] < 0)
			{
				ok = false;
			}
			else if (matrix[all - 1 - j] < 0)
			{
				ok = false;
			}
		}
		if(ok == true)
		{
			printf("Test #%ld: Symmetric.\n",k+1);
		}
		else
		{
			printf("Test #%ld: Non-symmetric.\n",k+1);
		}
	}

    return 0;
}

