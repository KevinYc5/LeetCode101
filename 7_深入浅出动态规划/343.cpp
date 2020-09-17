#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <limits.h>
#include <queue>

using namespace std;
class Solution0 {
public:
	int integerBreak(int n) {
		if (n == 2) {
			return 1;
		}
		int res = -1;
		for (int i = 1; i <= n - 1; i++) {
			res = max(res, max(i * (n - i), i * integerBreak(n - i)));
		}
		return res;
	}
};
class Solution {
public:
	int integerBreak(int n) {
		vector <int> dp(n + 1);
		for (int i = 2; i <= n; i++) {
			int curMax = 0;
			for (int j = 1; j < i; j++) {
				curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
			}
			dp[i] = curMax;
		}
		return dp[n];
	}
};

//
// Created by Kevin on 2020/9/14 21:10.
// 求真求实，大气大为
//

