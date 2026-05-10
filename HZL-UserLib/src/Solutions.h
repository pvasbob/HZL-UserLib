#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

 struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:

//	1. Two Sum
//		Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//		You may assume that each input would have exactly one solution, and you may not use the same element twice.
//		You can return the answer in any order.
//
//		Example 1:
//Input: nums = [2, 7, 11, 15], target = 9
//	Output : [0, 1]
//	Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//	Example 2 :
//
//	Input : nums = [3, 2, 4], target = 6
//	Output : [1, 2]
//	Example 3 :
//
//	Input : nums = [3, 3], target = 6
//	Output : [0, 1]
//
//
//	Constraints :
//
//	2 <= nums.length <= 104
//	- 109 <= nums[i] <= 109
//	- 109 <= target <= 109
//	Only one valid answer exists.
//
	std::vector<int> twoSum(std::vector<int>& nums, int target);

//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes
//contains a single digit.Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//	Example 1:
//	Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//	Output : [7, 0, 8]
//	Explanation : 342 + 465 = 807.
//
//	Example 2 :
//	Input : l1 = [0], l2 = [0]
//	Output : [0]
//
//	Example 3 :
//	Input : l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//	Output : [8, 9, 9, 9, 0, 0, 0, 1]
//
//	Constraints :
//	The number of nodes in each linked list is in the range[1, 100].
//	0 <= Node.val <= 9
//	It is guaranteed that the list represents a number that does not have leading zeros.
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

//	Given a string s, find the length of the longest substring without duplicate characters.
//
//		Example 1:
//
//Input: s = "abcabcbb"
//	Output : 3
//	Explanation : The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//	Example 2 :
//
//	Input : s = "bbbbb"
//	Output : 1
//	Explanation : The answer is "b", with the length of 1.
//	Example 3 :
//
//	Input : s = "pwwkew"
//	Output : 3
//	Explanation : The answer is "wke", with the length of 3.
//	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//	Constraints :
//
//	0 <= s.length <= 5 * 104
//	s consists of English letters, digits, symbols and spaces.
//
	int lengthOfLongestSubstring(std::string s);

//	5. Longest Palindromic Substring
//		Solved
//		Medium
//		Topics
//		premium lock icon
//		Companies
//		Hint
//		Given a string s, return the longest palindromic substring in s.
//
//
//
//		Example 1:
//
//Input: s = "babad"
//	Output : "bab"
//	Explanation : "aba" is also a valid answer.
//	Example 2 :
//
//	Input : s = "cbbd"
//	Output : "bb"
//
//
//	Constraints :
//
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
	std::string longestPalindrome(std::string s);


//	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you 
//	may want to display this pattern in a fixed font for better legibility)
//
//		P   A   H   N
//		A P L S I I G
//		Y   I   R
//		And then read line by line : "PAHNAPLSIIGYIR"
//
//		Write the code that will take a string and make this conversion given a number of rows :
//
//	string convert(string s, int numRows);
//
//
//	Example 1:
//
//Input: s = "PAYPALISHIRING", numRows = 3
//	Output : "PAHNAPLSIIGYIR"
//	Example 2 :
//
//	Input : s = "PAYPALISHIRING", numRows = 4
//	Output : "PINALSIGYAHRPI"
//	Explanation :
//	P     I    N
//	A   L S  I G
//	Y A   H R
//	P     I
//	Example 3 :
//
//	Input : s = "A", numRows = 1
//	Output : "A"
//
//
//	Constraints :
//
//	1 <= s.length <= 1000
//	s consists of English letters(lower - case and upper - case), ',' and '.'.
//	1 <= numRows <= 1000
//
	std::string convert(std::string s, int numRows);
};


//when i show you a problem.Please show an fair complicated example, and explain code each step, each loop, until the example is done.
//and please always use the time - efficient way to solve problem, as nowadyas, space is not as critical as speed.
