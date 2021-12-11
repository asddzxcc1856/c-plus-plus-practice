#include <iostream>
using namespace std;

void insert_sorting(int b[])
{
	for(int i = 1 ; i < 5 ; i++)
	{
		int temp = b[i];
		int j = i - 1;
		while(j>=0 && temp < b[j])
		{
			b[j + 1] = b[j];
			j--;
		}
		b[j + 1] = temp;
	}
}

void print_arr(int b[])
{
	cout << "±Æ§Çµ²ªG : ";
	for (int i = 0 ; i < 5 ; i++)
	{
		cout << b[i] << " ";
	}
	cout << "\n";
}

int main ()
{
	int c[10] = {55,23,87,62,16};
	
	insert_sorting(c);
	
	print_arr(c);
	
    return 0;
}

