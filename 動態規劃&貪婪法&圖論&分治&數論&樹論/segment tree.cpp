#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 100005;
ll sum[4 * maxn];
ll arr[maxn];
ll tag[4 * maxn];

void push(int l,int r,int v) // push to subtree
{
	sum[v] += (r - l) * tag[v];
	if(r - l == 1)
		return tag[v] = 0,void();
	tag[v * 2 + 1] += tag[v];
	tag[v * 2 + 2] += tag[v];
	tag[v] = 0; 
}

void pull(int l,int r,int v) // update new information to get value 
{
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	push(l,mid,v * 2 + 1);
	push(mid,r,v * 2 + 2);
	sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}

void build(int l,int r,int v = 0) // build tree + get value 
{
	if(r - l == 1)
	{
		sum[v] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,v * 2 + 1);
	build(mid,r,v * 2 + 2);
	pull(l,r,v);
}

ll query(int L,int R,int l,int r,int v = 0) // [l,r) query sum value
{
	push(l,r,v);
	if(l == L && r == R)
		return sum[v];
		
	int mid = (l + r) >> 1;
	if(R <= mid)
		return query(L,R,l,mid,v * 2 + 1);
	else if (L >= mid)
		return query(L,R,mid,r,v * 2 + 2);
	else
		return query(L,R,l,mid,v * 2 + 1) + query(L,R,mid,r,v * 2 + 2);
}

void update(int L,int R,ll val,int l,int r,int v = 0) // [l,r) modify [l,r) value + push tag + pull to new information for get value
{
	push(l,r,v);
	if(l == L && r == R)
	{
		tag[v] += val;
		push(l,r,v);
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid)
		update(L,R,val,l,mid,v * 2 + 1);
	else if (L >= mid)
		update(L,R,val,mid,r,v * 2 + 2);
	else
		update(L,R,val,l,mid,v * 2 + 1),update(L,R,val,mid,r,v * 2 + 2);
	pull(l,r,v);
}

int main ()
{
	memset(sum,0,sizeof(sum));
	memset(tag,0,sizeof(tag));
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> arr[i];
	}
	build(0,5,0);
	update(0,5,20,0,5,0);
	cout << query(0,5,0,5,0);
}