#include <iostream>
using namespace std;

char mat[10][10];

int main ()
{
	int T;
	cin >> T;
	for(int k = 0 ; k < T ; k++)
	{
		int n;
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
				cin >> mat[i][j];
			cin.get();
		}
			
			
		int M;
		cin >> M;
		for(int w = 0 ; w < M ; w++)
		{
			string str;
			cin >> str;
			if(str == "row")
			{
				int a,b;
				cin >> a >> b;
				a -= 1;
				b -= 1;
				for(int i = 0 ; i < n ; i++)
				{
					int tmp = mat[a][i];
					mat[a][i] = mat[b][i];
					mat[b][i] = tmp;
				}
			}
			else if (str == "col")
			{
				int a,b;
				cin >> a >> b;
				a -= 1;
				b -= 1;
				for(int i = 0 ; i < n ; i++)
				{
					int tmp = mat[i][a];
					mat[i][a] = mat[i][b];
					mat[i][b] = tmp;
				}
			}
			else if (str == "inc")
			{
				for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0 ; j < n ; j++)
					{
						mat[i][j]++;
						if(mat[i][j] == 58)
						{
							mat[i][j] = '0';
						}
					}
				}
			}
			else if (str == "dec")
			{
				for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0 ; j < n ; j++)
					{
						mat[i][j]--;
						if(mat[i][j] == 47)
						{
							mat[i][j] = '9';
						}
					}
				}
			}
			else if (str == "transpose")
			{
				char tmp[10][10];
				for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0 ; j < n ; j++)
					{
						tmp[j][i] = mat[i][j]; 
					}
				}
				for(int i = 0 ; i < n ; i++)
				{
					for(int j = 0 ; j < n ; j++)
					{
						mat[i][j] = tmp[i][j]; 
					}
				}
			}
		}
		cout << "Case #" << k + 1 << "\n";
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cout << (int)(mat[i][j] - 48);
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
