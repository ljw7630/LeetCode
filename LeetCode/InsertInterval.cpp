#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/// !!!!!
/// has to re-think about this problem
/// too many cases


/// 1. (append after case)
/// 2. (append before case)
/// 3. keep updating case

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		int start =  newInterval.start, end = newInterval.end;

		if( intervals.size() == 0)
		{
			result.push_back( newInterval );
			return result;
		}
		bool hasBeenInserted = false;

		for(int i = 0; i < intervals.size(); ++i){

			// the intervals before the newInterval
			if( intervals[i].end < newInterval.start)
			{
				result.push_back( intervals[i] );
				continue;
			}

			// the intervals after the newInterval
			if( hasBeenInserted )
			{
				result.push_back( intervals[i] );
				continue;
			}

			// stop case
			if( intervals[i].start > end && !hasBeenInserted)
			{
				result.push_back( Interval(start, end) );
				result.push_back( intervals[i] );
				hasBeenInserted = true;
				continue;
			}

			// start case
			if( intervals[i].end >= start )
			{
				start = min( intervals[i].start, start );
				end = max( intervals[i].end, end );
			}
		}

		if( !hasBeenInserted )
		{			
			result.push_back( Interval(start, end) );
		}

		return result;
    }
};
//
//int main()
//{
//	/*Interval intervals[] = { Interval(2,4), Interval(5,7),
//			Interval(8,10), Interval(11,13)};*/
//	Interval intervals[] = { Interval(1,5), Interval(6,8)} ;
//	vector<Interval> vec = AlgorithmImpl::Utility::createVector<Interval>(intervals, 2);
//	Interval newInterval (5,6);
//	Solution().insert(vec, newInterval);
//	return 0;
//}