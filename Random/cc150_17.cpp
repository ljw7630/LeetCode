#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"
#include "ListNode.h"

using namespace std;
using namespace AlgorithmImpl;


void swap_in_place(int & a, int &b){
	a = a+b;
	b = a-b;
	a = a-b;
}

