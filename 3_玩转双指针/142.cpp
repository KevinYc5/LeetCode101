#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		do{
			if(fast == NULL || fast ->next == NULL)
				return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		} while (fast != slow); // 第一次相遇
		fast = head;
		while (fast != slow){   // 第二次相遇
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

//
// Created by Kevin on 2020/7/17 10:52.
// 求真求实，大气大为
//

