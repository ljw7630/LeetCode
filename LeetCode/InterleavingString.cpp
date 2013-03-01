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

/// !!!!!
/// Recursive algorithm works only when we check the begin and the end of the text
/// It will prune a lot of braches

/// dynamic programming:
/// define matrix[i][j] as: whether s3[0,..., i+j] is the interleaving of s1, s2
/// if s1[i] = s3[i+j] matrix[i][j] = matrix[i-1][j] || matrix[i][j]
/// if s2[i] = s3[i+j] matrix[i][j] = matrix[i][j-1] || matrix[i][j]

class Solution {
public:

	 bool isInterleave(string s1, string s2, string s3) {
		 if( s1.size() + s2.size() != s3.size() )
			 return false;
		 // define matrix[i][j] as: whether s3[0,..., i+j] is the interleaving of s1, s2
		 vector<vector<bool> > matrix(s1.size()+1,  vector<bool> (s2.size()+1, false) );
		 
		matrix[0][0] = true;
		for(int i=0;i<s1.size();++i)
		{
			if( s1[i] == s3[i] )
				matrix[i+1][0] = true;
			else
				break;
		}

		for(int i=0;i<s2.size();++i)
		{
			if( s2[i] == s3[i] )
				matrix[0][i+1] = true;
			else
				break;
		}

		for(int i = 1; i < s1.size()+1; ++i)
		{
			char c1 = s1[i-1];
			for(int j = 1; j < s2.size()+1; ++j)
			{
				char c2 = s2[j - 1];
				int index = i + j -1;
				if( c1 == s3[index] )
				{
					matrix[i][j] = matrix[i-1][j] || matrix[i][j];
				}
				if( c2 == s3[index] )
				{
					matrix[i][j] = matrix[i][j-1] || matrix[i][j];
				}
			}
		}

		return matrix[s1.size()][s2.size()];
	 }

//    bool isInterleave(string s1, string s2, string s3) {
//		if( s1.size() + s2.size() != s3.size() )
//			return false;
//
//		return isInterleaveHelper(s1, s2, s3, 0, s1.size()-1, 0, s2.size()-1, 0, s3.size()-1);
//    }
//
//	bool isInterleaveHelper(const string &s1, const string &s2, const string &s3, 
//			int index1, int end1, int index2, int end2, int index3, int end3) 
//	{
//		if( index3 > end3)
//		{
//			return true;
//		}
//
//		if( index1 <= end1 ){
//			if( s1[index1] == s3[index3] ){
//				if( index1 != end1 && s1[end1] == s3[end3]){
//					bool res = isInterleaveHelper(s1, s2, s3, index1+1, end1-1, index2, end2, index3+1, end3-1);
//					if( res ) return true;
//				}
//				if( index2 <= end2 && s2[end2] == s3[end3] ){
//					bool res = isInterleaveHelper(s1, s2, s3, index1+1, end1, index2, end2-1, index3+1, end3-1);
//					if( res ) return true;
//				}
//			}
//		}
//		else
//		{
//			while( index3 != end3+1 && s2[index2] == s3[index3]) index2++, index3++;
//			if( index3 != end3+1 ) return false;
//			else return true;
//		}
//
//		if( index2 <= end2 ){
//			if( s2[index2] == s3[index3] ){
//				if( index2 != end2 && s2[end2] == s3[end3] ){
//					bool res = isInterleaveHelper(s1, s2,s3,index1, end1, index2+1, end2-1, index3+1, end3-1);
//					if( res ) return true;
//				}
//				if( index1 <= end1 && s1[end1] == s3[end3] ){
//					bool res = isInterleaveHelper(s1, s2,s3,index1, end1-1, index2+1, end2, index3+1, end3-1);
//					if( res ) return true;
//				}
//			}
//		}
//		else
//		{
//			while( index3 != end3+1	&& s1[index1] == s3[index3]) index1++, index3++;
//			if( index3 != end3+1 ) return false;
//			else return true;
//		}
//
//		return false;
//	}
};

//int main()
//{
//	Solution solution;
//	cout << solution.isInterleave("aabcc","dbbca","aadbbcbcac") << endl;
//	cout << solution.isInterleave("a","","c") << endl;
//	getchar();
//	return 0;
//}