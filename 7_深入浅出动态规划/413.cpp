#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include<numeric>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if( n < 3) return 0;
		vector<int>dp(n, 0);
		for(int i = 2; i < n; ++i){
			if(A[i] - A[i-1] == A[i-1] - A[i-2]){
				dp[i] = dp[i-1] + 1;
			}
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};
//
// Created by Kevin on 2020/8/1 10:01.
// 求真求实，大气大为
//

