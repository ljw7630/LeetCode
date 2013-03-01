#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool canJump(int A[], int n) {
		// vector<bool> canVisit(n, false);
		//canVisit[0] = true;
		int maxi = 0;
		
		for(int i=0;i<n;++i)
		{
			// this position might not be reachable
			if(i > maxi)
				return false;
			int tmp = A[i] + i;

			if(tmp > maxi)
				maxi = tmp;
		}

		if(maxi >= n-1)
			return true;
		else
			return false;
	}
};

//int main()
//{
//	int a[1] = {0};
//	cout << Solution().canJump(a, 1) << endl;
//	getchar();
//	return 0;
//}