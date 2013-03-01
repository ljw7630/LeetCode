#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

class Solution {
public:
	void sortColors(int A[], int n) {
		int * ptr[3] = {A};

		for(int i=0;i<n;++i)
		{
			*ptr[A[i]] = A[i];
			ptr[A[i]]++;
		}
	}
  //  void sortColors(int A[], int n) {
		//int count[3] = {0};

		//for(int i=0;i<n;++i)
		//	count[A[i]]++;

		//int j = 0;
		//for(int i=0;i<n;++i)
		//{
		//	if( count[j] != 0 )
		//	{
		//		A[i] = j;
		//		count[j]--;
		//	}
		//	else
		//	{
		//		j++;
		//		i = i-1;
		//	}
		//}
  //  }
};