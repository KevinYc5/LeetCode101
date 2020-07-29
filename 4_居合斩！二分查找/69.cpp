#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		long long l = 1, r = x, mid;    // long long /int不够。。。
		while(l <= r){
			//mid = (l+r)/2;              // 易错点
			mid = l + (r-l)/2;            // 可避免整型溢出
			if(mid*mid < x){
				l = mid + 1;
				if(l > r){
					return mid;
				}
			}else if(mid*mid > x){
				r = mid - 1;
				if(l > r){
					return r;
				}
			}else{
				return mid;
			}
		}
		return 0;
	}
	int mySqrt1(int a) {
		if (a == 0) return a;
		int l = 1, r = a, mid, sqrt;
		while (l <= r) {
			mid = l + (r - l) / 2;
			sqrt = a / mid;             // a / mid 与 mid 比较 避免使用long long
			if (sqrt == mid) {
				return mid;
			} else if (mid > sqrt) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return r;
	}
	//牛顿迭代法，
	// 其公式为 xn+1 = xn − f(xn)/ f′(xn)。给 定 f(x) = x2 − a = 0，
	// 这里的迭代公式为 xn+1 = (xn + a/xn)/2
	int mySqrt2(int a) {
		long x = a;
		while (x * x > a) {
			x = (x + a / x) / 2;
		}
		return x;
	}
};
//
// Created by Kevin on 2020/7/18 18:25.
// 求真求实，大气大为
//

