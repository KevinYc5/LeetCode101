#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
	bool judgeSquareSum(int c) {
		long i = 0, j = sqrt(c);
		while (i <= j)
			if (i * i + j * j == c) return true;
			else if (i * i + j * j > c) j --;
			else i ++;
		return false;
	}
};

class Solution1 {
public:
	bool judgeSquareSum(int c) {
		long l = 0, r = floor(sqrt(c) + 0.5), sum;
		while(l <= r){
			sum = l*l + r*r;
			if(sum == c)
				break;
			if(sum < c)
				++l;
			else
				--r;
		}
		return l <= r;
	}
};
//
// Created by Kevin on 2020/7/17 22:11.
// 求真求实，大气大为
//

