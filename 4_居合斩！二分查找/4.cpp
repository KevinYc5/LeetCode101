#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include<climits>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			return findMedianSortedArrays(nums2, nums1);
		}
		int N = nums1.size();
		int M = nums2.size();
		int half = (N + M) / 2;
		int low = 0;
		int high = N;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int t = half - mid;
			int lmax1 = (mid - 1 >= 0) ? nums1[mid - 1] : INT_MIN;
			int rmin1 = (mid < N) ? nums1[mid] : INT_MAX;
			int lmax2 = (t - 1 >= 0) ? nums2[t - 1] : INT_MIN;
			int rmin2 = (t < M) ? nums2[t] : INT_MAX;
			if (lmax1 > rmin2) {
				high = mid - 1;
			} else if (lmax2 > rmin1) {
				low = mid + 1;
			} else {
				low = high = mid;
				break;
			}
		}
		int u = low;
		int v = half - low;
		int l = max(
				u - 1 >= 0 ? nums1[u - 1] : INT_MIN,
				v - 1 >= 0 ? nums2[v - 1] : INT_MIN);
		int r = min(
				u < N ? nums1[u] : INT_MAX,
				v < M ? nums2[v] : INT_MAX);
		if ((N + M) % 2 == 1) return r;
		return (l + r) * 1.0 / 2;
	}
};

//转为寻找第k小数问题
int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){//从nums1中的i和nums2的j开始 找第k大的数
	if(nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);//保证第二个大于等于第一个
	if(nums1.size() == i) return nums2[j+k-1];//第一个数组为空时
	if(k==1) return min(nums1[i],nums2[j]);//递归边界 即为两个最小值
	int si = min(int(nums1.size()),i + k/2), sj = j + k - k/2;//每个数组从起点开始的第k/2大数的后一个数的下标
	if(nums1[si-1] > nums2[sj-1]){//若前者的该数大于后者的该数 则后者的前部分就没用了
		return find(nums1, i, nums2, sj, k - (sj-j));//sj-j即为删去的数的个数
	}
	else return find(nums1, si, nums2, j, k - (si - i));//同理 此时 前者的前部分就没用了
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int tot = nums1.size() + nums2.size();
	if(tot % 2) {//总数为奇数时的中位数
		return find(nums1, 0, nums2, 0, tot/2+1);
	}
	else {
		int l = find(nums1, 0, nums2, 0, tot/2), r = find(nums1, 0, nums2, 0, tot/2 + 1);
		return (l + r)/2.0;
	}
}
//
// Created by Kevin on 2020/7/20 12:17.
// 求真求实，大气大为
//

