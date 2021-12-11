#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main ()
{
	string s1,s2,s3[105];
	int cnt = 0 , maxl = 0;
	while(getline(cin,s3[cnt]))
	{
		maxl = max(s3[cnt].length(),maxl);
		cnt++;
	}
	
	for (int i = 0 ; i < maxl ; i++)
	{
		for(int j = cnt - 1 ; j >= 0; j--)
		{
			if(i<s3[j].length())
				cout << s3[j][i];
			else
				cout << " "; 
		}
		cout << "\n";
	}
	
	
	
	

    return 0;
}

