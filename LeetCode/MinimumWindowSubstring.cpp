#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>

#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl; 

/// if this is the char we need, tCount++, hasFound++
/// if this is the redundant char, hasFound++ only
/// if tCount == count, update leftIndex & rightIndex
/// to maintain the invariance, we need leftIndex = 0, rightIndex = -1 at the begining

class Solution {
public:
    string minWindow(string S, string T) {
		vector<int> needToFind(256,0);
		vector<int> hasFound(256,0);
		for(int i=0;i<T.size();++i){
			needToFind[T[i]]++;
		}

		int begin = 0;
		int count = T.size();
		int tCount = 0;
		int resultLen = S.size()+1;
		int resultBegin=0,resultEnd=-1;
		for(int i=0;i<S.size();++i){

			if( needToFind[S[i]]!=0 ){
				if( hasFound[S[i]] < needToFind[S[i]] ){
					tCount ++;
				}
				hasFound[S[i]]++;
				
				if( tCount == count){
					while( hasFound[S[begin]] > needToFind[S[begin]] 
								||  needToFind[S[begin]] == 0){	
						if( hasFound[S[begin]] > needToFind[S[begin]] ){
							hasFound[S[begin]] --;
							//tCount --;
						}
						begin++;
					}
												
					if( i - begin + 1 < resultLen){
						resultLen = i - begin + 1;
						resultBegin = begin;
						resultEnd = i;
					}
				}
			}
		}

		return S.substr(resultBegin, resultEnd-resultBegin+1);
	}
};

//int main(){
//	string S = "ADOBECODEBANC";
//	string T = "ABC";
//	cout << Solution().minWindow(S, T) << endl;
//	getchar();
//	return 0;
//}