#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long int,long long int**> mem;
long long int** M_mul(long long int** arr1,long long int** arr2)
{
	long long int i,j,k;
	
	long long int **ret;
	ret = new long long int*[2];
	for (int i = 0; i < 2; ++i) {
		ret[i] = new long long int[2];
		  	// each i-th pointer is now pointing to dynamic array (size 10) of actual int values
	}
	for (int i = 0; i < 2;++i) {   // for each row
	  	for (int j = 0; j < 2; ++j) { // for each column
	    	ret[i][j] = 0;
	  	}
	}
	for(i = 0 ; i < 2 ; i++)
	{
		for(j = 0 ; j < 2 ; j++)
		{
			for(k = 0 ; k < 2 ; k++)
			{
				ret[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	return ret;
	
}
long long int** cnt(long long int n)
{
	if(n == 0)
	{
		long long int **temp;
		temp = new long long int*[2];
		for (int i = 0; i < 2; ++i) {
		  	temp[i] = new long long int[2];
		  	// each i-th pointer is now pointing to dynamic array (size 10) of actual int values
		}
		for (int i = 0; i < 2;++i) {   // for each row
	  		for (int j = 0; j < 2; ++j) { // for each column
	    		temp[i][j] = 1;
	  		}
		}
		return temp;
	
	}	
	else if (n == 1)
	{
		long long int **temp;
		temp = new long long int*[2];
		for (int i = 0; i < 2; ++i) {
		  	temp[i] = new long long int[2];
		  	// each i-th pointer is now pointing to dynamic array (size 10) of actual int values
		}
		for (int i = 0; i < 2;++i) {   // for each row
	  		for (int j = 0; j < 2; ++j) { // for each column
	    		temp[i][j] = 1;
	  		}
		}
		temp[1][1] = 0;
		return temp;
	}
	else if(n % 2 == 0)
	{
		if(mem.find(n/2) != mem.end())
			return M_mul(mem[n/2],mem[n/2]);
		else
		{
			long long int** temp = M_mul(cnt(n/2),cnt(n/2));
			mem[n] = temp;
			return temp;
		}				
	}
	else
	{
		if(mem.find(n/2) != mem.end())
			return M_mul(M_mul(mem[n/2],mem[n/2]),cnt(1));
		else
		{
			long long int** temp = M_mul(M_mul(cnt(n/2),cnt(n/2)),cnt(1));
			mem[n] = temp;
			return temp;
		}	
	}
}



int main ()
{
	int n;
	cin >> n;
	long long int** ret = cnt(n - 2);
	long long int f[2][1] = {{1},{1}};
	long long int ans[2][1] = {};
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 1 ; j++)
		{
			for(int k = 0 ; k < 2 ; k++)
			{
				ans[i][j] += ret[i][k] * f[k][j];
			}
		}
	}
	cout << ans[0][0] << "\n";
}