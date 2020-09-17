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
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n < 2){
			return 0;
		}
		int dp[n][3];
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[0][2] = 0;
		for(int i = 1; i < n; ++i){
			dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
			dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]);
			dp[i][2] = dp[i-1][0];
		}
		return max(dp[n-1][0], dp[n-1][2]);
	}
};
//
// Created by Kevin on 2020/9/6 21:34.
// 求真求实，大气大为
//

//public class Solution {
//
//public int maxProfit(int[] prices) {
//		int len = prices.length;
//		// 特判
//		if (len < 2) {
//			return 0;
//		}
//
//		int[][] dp = new int[len][3];
//
//		// 初始化
//		dp[0][0] = 0;
//		dp[0][1] = -prices[0];
//		dp[0][2] = 0;
//
//		for (int i = 1; i < len; i++) {
//			dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//			dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
//			dp[i][2] = dp[i - 1][0];
//		}
//		return Math.max(dp[len - 1][0], dp[len - 1][2]);
//	}
//}
//
//		作者：liweiwei1419
//		链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/dong-tai-gui-hua-by-liweiwei1419-5/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。