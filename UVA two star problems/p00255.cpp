#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int adj[8][8];
int K,Q,M,nowk,nowq,cnt,cor,in1,in2;
bool adj2[8][8],qmlegal,movel;
vector<int> v,v2;

int main ()
{
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 8 ; j++)
			adj[i][j] = i * 8 + j;
	
	while(cin >> K >> Q >> M)
	{
		if(K == Q)
		{
			cout << "Illegal state\n";
		}
		else
		{
			v.clear();
			nowk = adj[K/8][K%8];
			nowq = adj[Q/8][Q%8];
			adj2[8][8];
			memset(adj2,false,sizeof(adj2));
			adj2[K/8][K%8] = true;	  

			qmlegal = false;
			for(int i = Q/8 + 1 ; i < 8 && adj2[i][Q%8] != true; i++)
			{
				v.push_back(adj[i][Q%8]);
				if(adj[i][Q%8] == M)
				{
					qmlegal = true;
				}
			}
			for(int i = Q/8 - 1; i >= 0 && adj2[i][Q%8] != true; i--)
			{
				v.push_back(adj[i][Q%8]);
				if(adj[i][Q%8] == M)
				{
					qmlegal = true;
				}
			}
			for(int i = Q%8 + 1 ; i < 8 && adj2[Q/8][i] != true; i++)
			{
				v.push_back(adj[Q/8][i]);
				if(adj[Q/8][i] == M)
				{
					qmlegal = true;
				}
			}
			for(int i = Q%8 - 1; i >= 0 && adj2[Q/8][i] != true; i--)
			{
				v.push_back(adj[Q/8][i]);
				if(adj[Q/8][i] == M)
				{
					qmlegal = true;
				}
			}
			if(qmlegal == false)
			{
				cout << "Illegal move\n";
			}
			else
			{
				movel = true; 
				if(K%8 + 1 <= 7)
				{
					if(adj[K/8][K%8 + 1] == M)
					{
						movel = false;
					}
				}
				if(K%8 - 1 >= 0)
				{
					if(adj[K/8][K%8 - 1] == M)
					{
						movel = false;
					}
				}
				if(K/8 + 1 <= 7)
				{
					if(adj[K/8 + 1][K%8] == M)
					{
						movel = false;
					}
				}
				if(K/8 - 1 >= 0)
				{
					if(adj[K/8 - 1][K%8] == M)
					{
						movel = false;
					}
				}
				if(movel == false)
				{
					cout << "Move not allowed\n";
				}
				else
				{
					cnt = 0;
					cor = 0;
					v2.clear();
					in1,in2;
					for(int i = 0 ; i < 8 ; i++)
					{
						for (int j = 0 ; j < 8 ; j++)
						{
							if(adj[i][j] == M)
							{
								in1 = i;
								in2 = j;
							}
						}
					}
					for(int i = in1 + 1 ; i < 8; i++)
					{
						v2.push_back(adj[i][in2]);
					}
					for(int i = in1 - 1; i >= 0; i--)
					{
						v2.push_back(adj[i][in2]);
					}
					for(int i = in2 + 1 ; i < 8; i++)
					{
						v2.push_back(adj[in1][i]);
					}
					for(int i = in2 - 1; i >= 0; i--)
					{
						v2.push_back(adj[in1][i]);
					}
					if(K%8 + 1 <= 7)
					{
						cnt++;
						vector<int>::iterator it = find(v2.begin(),v2.end(),adj[K/8][K%8 + 1]);
						if(it != v2.end())
						{
							cor++;
						}
					}
					if(K%8 - 1 >= 0)
					{
						cnt++;
						vector<int>::iterator it = find(v2.begin(),v2.end(),adj[K/8][K%8 - 1] );
						if(it != v2.end())
						{
							cor++;
						}
					}
					if(K/8 + 1 <= 7)
					{
						cnt++;
						vector<int>::iterator it = find(v2.begin(),v2.end(),adj[K/8 + 1][K%8] );
						if(it != v2.end())
						{
							cor++;
						}
					}
					if(K/8 - 1 >= 0)
					{
						cnt++;
						vector<int>::iterator it = find(v2.begin(),v2.end(),adj[K/8 - 1][K%8] );
						if(it != v2.end())
						{
							cor++;
						}
					}	
					
					if(cnt != cor)
					{
						cout << "Continue\n";
					}
					else
					{
						cout << "Stop\n";
					}
				}
			}
			
		}
		
		
	}
} 
