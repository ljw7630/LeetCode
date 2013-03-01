#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>

using namespace std;

class CardGame
{
public:
	void solve()
	{
		freopen("a.txt","r",stdin);
		freopen("out.txt","w",stdout);
		int t,n,k;
		const int modulo = 10000007;
		int a [10005];

		cin >> t;
		int c = 0;
		while(t--)
		{
			cin >> n >> k;

			for(int i=0;i<n;++i)
			{
				cin >> a[i];
			}

			sort(a, a+n);
			int result = 0;
			for(int i=n-1;i>-1;--i)
			{
				long long num = combinations(i, k-1);
				result = (result + a[i] * num)%modulo;
				if( num == 1 )
					break;
			}
			c ++;
			cout << "Case #" << c << ": " << result << endl;
		}
	}

	long long combinations(int n, int k)
	{
		int nMinusK = n-k;
		if( nMinusK < k )
			swap(nMinusK, k);

		long long tmp = 1;
		int divisor = 2;
		while( n > nMinusK )
		{
			tmp = tmp * n;
			n --;
			while( tmp > INT_MAX && divisor <= k )
			{
				tmp  = tmp/divisor;
				divisor ++;
			}
		}

		while( divisor <= k )
		{
			tmp /= divisor;
			divisor ++;
		}

		return tmp;
	}
};

//int main()
//{
//	//getchar();
//	CardGame().solve();
//	return 0;
//}