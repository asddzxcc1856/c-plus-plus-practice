#include <iostream>
using namespace std;

constexpr long int fib(int n)
{
	return (n<=1) ? n : fib(n - 1) + fib(n - 2);
}

int main ()
{
	constexpr long int num = fib(40);
	cout << num << "\n";
}