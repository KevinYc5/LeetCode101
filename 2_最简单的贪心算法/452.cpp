#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if(points.empty()){
			return 0;
		}
		int n = points.size();
		sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){
			return a[0] < b[0];
		});
		int total = 1, prev = points[0][1];
		for(int i = 1; i < n; i++){
			if(points[i][0] > prev){
				++total;
				prev = points[i][1];
			} else if(points[i][1] < prev){
				prev = points[i][1];
			}
		}
		return total;
	}
};
//
// Created by Kevin on 2020/7/14.
//

