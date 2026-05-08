#pragma once

#include "Solutions.h"


std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) 
{
	std::unordered_map<int, int> numMap;

	for (int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];

		if (numMap.find(complement) != numMap.end()) {
			return { numMap[complement], i };
		}

		numMap[nums[i]] = i;
	}

	return {};
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(0);
	ListNode* curr = dummyHead;
	int carry = 0;

	// Continue as long as there are nodes to process or a carry remains
	while (l1 != nullptr || l2 != nullptr || carry != 0) {
		int x = (l1 != nullptr) ? l1->val : 0;
		int y = (l2 != nullptr) ? l2->val : 0;

		int sum = carry + x + y;
		carry = sum / 10;

		curr->next = new ListNode(sum % 10);
		curr = curr->next;

		// Move to the next nodes
		if (l1 != nullptr) l1 = l1->next;
		if (l2 != nullptr) l2 = l2->next;
	}

	ListNode* result = dummyHead->next;
	delete dummyHead; // Good practice to clean up the dummy node
	return result;
}

int Solution::lengthOfLongestSubstring(std::string s) {
	// Space for all 128 ASCII characters, initialized to 0
	std::vector<int> charMap(128, 0);
	int maxLength = 0;
	int left = 0;

	for (int right = 0; right < s.length(); ++right) {
		char c = s[right];

		if (charMap[c] > left) {
			left = charMap[c]; // Jump 'left' to skip the repeat
		}

		maxLength = std::max(maxLength, right - left + 1);

		charMap[c] = right + 1;
	}
	return maxLength;
}





