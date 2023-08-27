#include <iostream>
#include <map>
using namespace std;

map<string,int> ma;
string str = "abcdefghijklmnopqrstuvwxyz";
int cnt = 1;

int main ()
{
	for(int i = 0 ; i < 26 ; i++)
	{
		string tmp = " ";
		tmp[0] = str[i]; 
		ma[tmp] = cnt++;	
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		string tmp = "  ";
		tmp[0] = str[i];
		for(int j = i + 1 ; j < 26 ; j++)
		{
				tmp[1] = str[j]; 
				ma[tmp] = cnt++;		
		}
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		string tmp = "   ";
		tmp[0] = str[i];
		for(int j = i + 1 ; j < 26 ; j++)
		{
			tmp[1] = str[j]; 
			for(int k = j + 1 ; k < 26 ; k++)
			{
					tmp[2] = str[k]; 
					ma[tmp] = cnt++;			
			}	
		}
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		string tmp = "    ";
		tmp[0] = str[i];
		for(int j = i + 1 ; j < 26 ; j++)
		{

				tmp[1] = str[j]; 
				for(int k = j + 1 ; k < 26 ; k++)
				{

						tmp[2] = str[k]; 
						for(int w = k + 1 ; w < 26 ; w++)
						{
								tmp[3] = str[w]; 
								ma[tmp] = cnt++;
						}	
					
				}		
		}
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		string tmp = "     ";
		tmp[0] = str[i];
		for(int j = i + 1 ; j < 26 ; j++)
		{

				tmp[1] = str[j]; 
				for(int k = j + 1 ; k < 26 ; k++)
				{

						tmp[2] = str[k]; 
						for(int w = k + 1 ; w < 26 ; w++)
						{
								tmp[3] = str[w]; 
								for(int q = w + 1 ; q < 26 ; q++)
								{
										tmp[4] = str[q]; 
										ma[tmp] = cnt++;
								}	
							
						}	
					
				}		
		}
	}
	string tmp;
	while(cin >> tmp)
	{
		if(ma.find(tmp) != ma.end())
			cout << ma[tmp] << "\n";
		else
			cout << "0\n";
	}
} 
