#include <iostream>
using namespace std;

char mat[10][10];
char ans[10][10];

int main ()
{
	int times = 1,n;
	while(cin >> n)
	{
		string end;
		getline(cin,end);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin >> mat[i][j];		
			}
			cin.get();
			for(int j = 0 ; j < n ; j++)
			{
				cin >> ans[i][j];		
			}	
			cin.get();
		}
		//rotate 90
		char nmat[8][10][10],tmp[10][10];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				nmat[1][j][n - i - 1] = mat[i][j];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				tmp[i][j] = mat[i][j];
		for(int k = 0 ; k < 2 ; k++)
		{	
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					nmat[2][j][n - i - 1] = tmp[i][j];
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					tmp[i][j] = nmat[2][i][j];	
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				tmp[i][j] = mat[i][j];
		for(int k = 0 ; k < 3 ; k++)
		{	
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					nmat[3][j][n - i - 1] = tmp[i][j];
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					tmp[i][j] = nmat[3][i][j];	
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				nmat[4][n - i - 1][j] = mat[i][j];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				nmat[0][i][j] = mat[i][j];	
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				nmat[5][j][n - i - 1] = nmat[4][i][j];
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				tmp[i][j] = nmat[4][i][j];
		for(int k = 0 ; k < 2 ; k++)
		{	
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					nmat[6][j][n - i - 1] = tmp[i][j];
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					tmp[i][j] = nmat[6][i][j];	
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				tmp[i][j] = nmat[4][i][j];
		for(int k = 0 ; k < 3 ; k++)
		{	
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					nmat[7][j][n - i - 1] = tmp[i][j];
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					tmp[i][j] = nmat[7][i][j];	
		}
		int k = 0;
		for( ; k < 8 ; k++)
		{	
			bool same = true;
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)
					if(nmat[k][i][j] != ans[i][j])
						same = false;
			if(same == true)
			{
				if(k == 0)
				{
					cout << "Pattern " << times++ << " was preserved.\n"; 
				}
				else if (k == 1)
				{
					cout << "Pattern " << times++ << " was rotated 90 degrees.\n"; 
				}
				else if (k == 2)
				{
					cout << "Pattern " << times++ << " was rotated 180 degrees.\n"; 
				}
				else if (k == 3)
				{
					cout << "Pattern " << times++ << " was rotated 270 degrees.\n"; 
				}
				else if (k == 4)
				{
					cout << "Pattern " << times++ << " was reflected vertically.\n"; 
				}
				else if (k == 5)
				{
					cout << "Pattern " << times++ << " was reflected vertically and rotated 90 degrees.\n"; 
				}
				else if (k == 6)
				{
					cout << "Pattern " << times++ << " was reflected vertically and rotated 180 degrees.\n"; 
				}
				else if (k == 7)
				{
					cout << "Pattern " << times++ << " was reflected vertically and rotated 270 degrees.\n"; 
				}
				break;
			}
		}
		if(k == 8)
		{
			cout << "Pattern " << times++ << " was improperly transformed.\n"; 
		}
	}	
} 
