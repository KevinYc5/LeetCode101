#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = m-- + n-- - 1;
		while(m > -1 & n > -1){
			if(nums1[m] > nums2[n])
				nums1[pos--] = nums1[m--];
			else
				nums1[pos--] = nums2[n--];
		}
		while (n > -1)
			nums1[pos--] = nums2[n--];
	}
};
//
// Created by Kevin on 2020/7/17 10:25.
// 求真求实，大气大为
//

