#include <iostream>
using namespace std;

int main ()
{
	int N,R,C,K;
	int land[101][101],nland[101][101];
	while(cin >> N >> R >> C >> K)
	{
		if(N == 0 && R == 0 && C == 0 && K == 0)
		{
			return 0;	
		}	
		for(int i = 0 ; i < R ; i++)
		{
			for(int j = 0 ; j < C ; j++)
			{
				cin >> land[i][j];
				nland[i][j] = land[i][j];
			}
		}
		
		for(int k = 0 ; k < K ; k++)
		{
			for(int i = 0 ; i < R ; i++)
			{
				for(int j = 0 ; j < C ; j++)
				{
					if(j + 1 < C && land[i][j + 1] == (land[i][j] + 1) % N)
					{
						nland[i][j + 1] = land[i][j];
					}
					if(j - 1 >= 0 && land[i][j - 1] == (land[i][j] + 1) % N)
					{
						nland[i][j - 1] = land[i][j];
					}
					if(i + 1 < R && land[i + 1][j] == (land[i][j] + 1) % N)
					{
						nland[i + 1][j] = land[i][j];
					}
					if(i - 1 >= 0 && land[i - 1][j] == (land[i][j] + 1) % N)
					{
						nland[i - 1][j] = land[i][j];
					}
				}
			}	
			for(int i = 0 ; i < R ; i++)
			{
				for(int j = 0 ; j < C ; j++)
				{
					land[i][j] = nland[i][j];
				}
			}
		}
		for(int i = 0 ; i < R ; i++)
		{
			for(int j = 0 ; j < C - 1; j++)
			{
				cout << land[i][j] << " ";
			}
			cout << land[i][C - 1];
			cout << "\n";
		}
	}	
}
