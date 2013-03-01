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
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {

		sort(intervals.begin(), intervals.end(), Solution());
		vector<Interval> result;
		if( intervals.size() == 0){
			return result;
		}
		int start = intervals[0].start, end = intervals[0].end;

		for(int i = 1;i<intervals.size();++i){

			if( end < intervals[i].start ){
				result.push_back(Interval(start, end));
				start = intervals[i].start, end = intervals[i].end;
			}
			else{
				end = max(end, intervals[i].end);
			}
		}

		result.push_back(Interval(start, end));

		return result;
	}


	bool operator() (const Interval &a, const Interval &b){
		if( a.start < b.start )
			return true;
		else if( a.start == b.start )
			return a.end < b.end;
		else
			return false;
	}
};