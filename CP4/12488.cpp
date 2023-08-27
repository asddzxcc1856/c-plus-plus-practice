#include <iostream> // cin cout
#include <vector> // vector<int> v
#include <cmath>  // abs(int n)
using namespace std; // std::cin std::cout

int main ()
{
	int n; // n 個競爭者 
	while(cin >> n)
	{
		vector<int> v1(n),v2(n); // 宣告 n 大小的陣列 
		// input
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v1[i];
		}
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v2[i];
		}
		// 1.找到第一個陣列中的元素(起點位置)在第二個陣列的位置(終點位置) => 存在第一個陣列(用不到第一個陣列，所以可以覆蓋掉資料) 
		// 2.bubble sort 
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(v1[i] == v2[j]) // 找到對應的位置 
				{
					v1[i] = j;
					break; // 只會出現一次 
				}
			}
		}
		int cnt = 0; //計算答案所需要知道的 超越次數 = bubble sort 對於(終點位置的順序)完成排序的交換次數 
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n - i - 1 ; j++)
			{
				if(v1[j] > v1[j + 1])
				{
					int tmp = v1[j + 1];
					v1[j + 1] = v1[j];
					v1[j] = tmp;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
