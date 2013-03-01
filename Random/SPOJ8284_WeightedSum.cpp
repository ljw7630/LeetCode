#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int vec [10000001];
int weight[10000001];

class Solution
{
public:
	void solve()
	{
		//freopen("a.txt","r",stdin);
		int t;
		int n;

		scanf("%d",&t);
		while(scanf("%d",&n)!=EOF)
		{
			for(int i=0;i<n;++i)
				scanf("%d",&vec[i]);
			
			memset(weight,0,sizeof(weight));

			weight[0] = 1;
			int power = 0; 
			for(int i=n-1;i>0;--i)
			{
				if( vec[i] < 0 )
				{
					if( power + vec[i] < 0 )
					{
						weight[i] = 2;
						power = 0;
					}
					else
					{
						power+=vec[i];
					}
				}
				else
				{
					power+=vec[i];
				}
			}

			long long result = 0;
			for(int i=0;i<n;++i)
			{
				if(weight[i] == 0)
					weight[i]=weight[i-1]+1;
				result += (long long)weight[i] * vec[i];
			}

			printf("%I64d\n",result);
		}	
	}
};

//int main()
//{
//	Solution().solve();
//	//getchar();
//	return 0;
//}