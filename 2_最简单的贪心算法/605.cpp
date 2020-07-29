#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;


class Solution
{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		int count =  0;
		flowerbed.insert(flowerbed.begin(),0);
		flowerbed.insert(flowerbed.end(),0);
		for(int i = 1; i < flowerbed.size()-1; i++)
		{
			if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
			{
				flowerbed[i] = 1;
				count++;
			}
		}
		return n <= count;
	}
};

//
// Created by Kevin on 2020/7/14.
//

class Solution2 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int size = flowerbed.size();
		int count = 0;
		if(size < 2 && flowerbed[0] == 0)
			count++;
		else{
			for(int i = 0; i < size; i++){
				if(flowerbed[i] == 0){
					if(i == 0){
						if(flowerbed[i+1] == 0){
							flowerbed[i] = 1; count++;
						}
					} else if(i == size - 1){
						if(flowerbed[i-1] == 0){
							flowerbed[i] = 1; count++;
						}
					} else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
						flowerbed[i] = 1; count++;
					}

				}
			}
		}
		return count >= n;
	}
};