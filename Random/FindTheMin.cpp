#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <time.h>
#include "AlgorithmImpl.h"

using namespace std;

//template<class T1, class T2, class T3>
//class reservable_priority_queue: public std::priority_queue<T1, T2, T3>
//{
//public:
//    typedef typename std::priority_queue<T1, T2, T3>::size_type size_type;
//    reservable_priority_queue(size_type capacity = 0) { reserve(capacity); };
//    void reserve(size_type capacity) { this->c.reserve(capacity); } 
//    size_type capacity() const { return this->c.capacity(); } 
//};


void numberGenerator(const vector<long long> &vec)
{	
	for(int i=0;i<vec.size();++i)
		cout << vec[i] << " ";
	cout << endl;
}

void findTheMin()
{
	freopen("sample.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int t, n, k, a,b,c,r; 
	cin >> t;
	int caseCount = 0;
	while(cin >> n >> k)
	{
		cin >> a >> b >> c >> r;
		vector<long long> vec;
		long long current = a;
		vector<int> occupied(k+1,0);
		int circleCount = 0;
		int realK = k;
		clock_t init = clock(), final;
		for(int i = 0;i<k;++i)
		{
			vec.push_back(current);

			if( current < k+1 )
			{
				if(occupied[current] == 1)
				{
					circleCount ++;
				}
				if(occupied[current] == 2)
				{
					realK = k - 2* circleCount;
					break;
				}
				occupied[current]++;				
			}

			current = (b*current + c) % r;			
		}
		k = realK;
		int step = (n-k)%(k+1);
		int index = 0;
		cout << "before build heap" << endl;
		cout << k+1 << endl;
		
		vector<int> notUsed;
		
		for(int i=0;i<k+1;++i)
		{
			if(occupied[i] == 0)
			{
				notUsed.push_back(i);
			}
		}
		priority_queue<int, vector<int>, greater<int>> minHeap(
			notUsed.begin(), notUsed.end());

		cout << "finish build heap" << endl;
		int vecIndex = 0;
		
		do{
			index = minHeap.top();
			occupied[index]++;
			minHeap.pop();
			step --;
			if(vecIndex < vec.size())
			{
				int valueInVec = vec[vecIndex++];
				if(valueInVec < k+1)
				{
					occupied[valueInVec]--;
					if(occupied[valueInVec] == 0)
					{
						minHeap.push(valueInVec);
					}
				}
			}
		}while(step > 0);
		final = clock() - init;
		cout << (double) final / (double)CLOCKS_PER_SEC << endl;
		caseCount++;
		cout << "Case #" << caseCount << ": " << index << endl;
	}
}

//void findTheMin()
//{
//	freopen("sample.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int t, n, k, a,b,c,r; 
//	cin >> t;
//	int caseCount = 0;
//	while(cin >> n >> k)
//	{
//		cin >> a >> b >> c >> r;
//		vector<long long> vec;
//		long long current = a;
//		vector<int> occupied(k+1,0);
//		
//		for(int i = 0;i<k;++i)
//		{
//			vec.push_back(current);
//
//			if( current < k+1 )
//			{
//				occupied[current]++;
//				
//			}
//
//			current = (b*current + c) % r;			
//		}
//		
//		int step = (n-k-1)%(k+1);
//		int index = 0;
//
//		int vecIndex = 0;
//		while(step >= 0)
//		{
//			if(occupied[index] == 0)
//			{
//				occupied[index]++;
//				step --;
//
//				if(step < 0)
//				{
//					break;
//				}
//
//				index++;
//
//				long long v = vec[vecIndex++];
//				if(v < k+1)
//				{
//					occupied[v]--;
//					if(occupied[v] == 0)
//					{
//						index = min(index,(int)v);
//					}
//				}
//			}
//			else
//			{
//				index++;
//			}
//		}
//		caseCount++;
//		cout << "Case #" << caseCount << ": " << index << endl;
//	}
//}

//int main()
//{
//	//AlgorithmImpl::Utility::printMeasureTime(&findTheMin);
//	findTheMin();
//	return 0;
//}