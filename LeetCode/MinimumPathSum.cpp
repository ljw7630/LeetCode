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

class Solution {

public:
	typedef pair<int, int> position;
    int minPathSum(vector<vector<int> > &grid) {
		if(grid.empty())
			return 0;
		
		int direction[2][2] = {			
			{1, 0},
			{0, 1} };
		vector<vector<bool> >hasBeenVisit(grid.size(), vector<bool>(grid[0].size(),false));
		priority_queue<pair<position, int>, vector<pair<position, int> >, Solution> nodes;
		position dest(grid.size()-1, grid[0].size()-1);
		nodes.push( make_pair(position(0,0), grid[0][0]) );
		hasBeenVisit[0][0] = true;
		while(!nodes.empty()){
			pair<position, int> node = nodes.top();
			nodes.pop();
			if( node.first == dest ){
				return node.second;
			}
			for(int i=0;i<2;++i)
			{
				int x = node.first.first+direction[i][0];
				int y = node.first.second+direction[i][1];
				if( x >= 0 && x < grid.size() && y >= 0 && y <= grid[0].size()
					&& hasBeenVisit[x][y] == false){
						hasBeenVisit[x][y] = true;
						nodes.push(make_pair(position(x,y), node.second+grid[x][y]));
				}
			}
		}
    }
	
	bool operator() (const pair<position, int> &a, const pair<position, int> &b){
		return a.second > b.second;
	}
};
