#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int binary_search(int b[],int L,int R,int val) // (要搜尋的陣列,左界,右界,要搜尋的值)
{
	if(L<=R)
	{
		int mid = (L + R) / 2; // 先找出中間的位置 
		if(b[mid] == val) // 如果 (相等) 就回傳位置 
			return mid; 
		else if (b[mid] > val) // 如果 (中間位置的值 > 要找的值) 代表 要找的值在中間值的左邊  
			return binary_search(b,L,mid - 1,val); //不需要mid => 找(左,中-1)
		else if (b[mid] < val) // 如果 (中間位置的值 < 要找的值) 代表 要找的值在中間值的右邊  
			return binary_search(b,mid + 1,R,val); //不需要mid => 找(中+1,右)
	}
}

int main ()
{
	int c[10] = {1,5,89,71,54,65,75,13,29,46}; //宣告一個未排序的陣列 
	cout << "索引值          0  1  2  3  4  5  6  7  8  9\n";
	cout << "排序前陣列 c : ";
	for(int i = 0 ; i < 10 ; i++)
		cout << setw(2) << c[i] << " ";
	cout << "\n"; 
	
	sort(c,c+10); // 排序:小到大 
	
	cout << "排序後陣列 c : ";
	for(int i = 0 ; i < 10 ; i++)
		cout << setw(2) << c[i] << " ";
	cout << "\n"; 
	
	
	int loc = binary_search(c,0,9,71); // 找出 71 在排序後陣列中的位置 

	cout << "71 在排序後 c 陣列的" << loc + 1 << "位置" << "\n"; // 回傳為陣列 index 所以要 + 1 才是位置 

    return 0;
}

