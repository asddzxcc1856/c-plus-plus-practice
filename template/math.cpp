#include <iostream>
using namespace std;

template<class T>
inline T max(T &a,T &b)
{
	return a >= b ? a : b;
}
template<class T>
inline T abs(T &a)
{
	return a >= 0 ? a : -a;
}
template<class T>
inline T min(T &a,T &b)
{
	return a >= b ? b : a;
}
template<class T>
inline double sqrt(T &n)
{
	double lo = min((double)1.0, (double)n), hi = max((double)1.0, (double)n), mid;
	if(n < 1)
		lo = n, hi = 1;
		
	// Update the bounds to be off the target by a factor of 10
	while(100 * lo * lo < n) lo *= 10;
	while(0.01 * hi * hi > n) hi *= 0.1;
		
	for(int i = 0 ; i < 100 ; i++)
	{
	    mid = (lo+hi) * 0.5;
		if(mid*mid == n) return mid;
	    if(mid*mid > n) hi = mid;
		else lo = mid;
	}
	return mid;
}

int main ()
{
	int aa = 30,bb = 1000;
	
	cout << max(aa,bb) << "\n";
	cout << abs(-aa) << "\n";
	cout << sqrt(aa) << "\n";
	
	return 0;
}