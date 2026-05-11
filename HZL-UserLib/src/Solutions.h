#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iostream>


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


//
//	Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.
//
//		Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).
//
//
//
//		Example 1:
//
//Input: x = 123
//	Output : 321
//	Example 2 :
//
//	Input : x = -123
//	Output : -321
//	Example 3 :
//
//	Input : x = 120
//	Output : 21
//
//
//	Constraints :
//
//	-231 <= x <= 231 - 1
//
	int reverse(int x);

//	Implement the myAtoi(string s) function, which converts a string to a 32 - bit signed integer.
//
//		The algorithm for myAtoi(string s) is as follows :
//
//Whitespace: Ignore any leading whitespace(" ").
//	Signedness : Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//	Conversion : Read the integer by skipping leading zeros until a non - digit character is encountered or the end of the string is reached.If no digits were read, then the result is 0.
//	Rounding : If the integer is out of the 32 - bit signed integer range[-231, 231 - 1], then round the integer to remain in the range.Specifically, integers less than - 231 should be rounded to - 231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//	Return the integer as the final result.
//
//
//
//	Example 1 :
//
//	Input : s = "42"
//
//	Output : 42
//
//	Explanation :
//
//	The underlined characters are what is read in and the caret is the current reader position.
//	Step 1 : "42" (no characters read because there is no leading whitespace)
//	^
//	Step 2 : "42" (no characters read because there is neither a '-' nor '+')
//	^
//	Step 3 : "42" ("42" is read in)
//	^
//	Example 2 :
//
//	Input : s = " -042"
//
//	Output : -42
//
//	Explanation :
//
//	Step 1 : "   -042" (leading whitespace is read and ignored)
//	^
//	Step 2 : "   -042" ('-' is read, so the result should be negative)
//	^
//	Step 3 : "   -042" ("042" is read in, leading zeros ignored in the result)
//	^
//	Example 3 :
//
//	Input : s = "1337c0d3"
//
//	Output : 1337
//
//	Explanation :
//
//	Step 1 : "1337c0d3" (no characters read because there is no leading whitespace)
//	^
//	Step 2 : "1337c0d3" (no characters read because there is neither a '-' nor '+')
//	^
//	Step 3 : "1337c0d3" ("1337" is read in; reading stops because the next character is a non - digit)
//	^
//	Example 4 :
//
//	Input : s = "0-1"
//
//	Output : 0
//
//	Explanation :
//
//	Step 1 : "0-1" (no characters read because there is no leading whitespace)
//	^
//	Step 2 : "0-1" (no characters read because there is neither a '-' nor '+')
//	^
//	Step 3 : "0-1" ("0" is read in; reading stops because the next character is a non - digit)
//	^
//	Example 5 :
//
//	Input : s = "words and 987"
//
//	Output : 0
//
//	Explanation :
//
//	Reading stops at the first non - digit character 'w'.
	int myAtoi(std::string s); 

//	Given an integer x, return true if x is a palindrome, and false otherwise.
//
//		Example 1:
//
//Input: x = 121
//	Output : true
//	Explanation : 121 reads as 121 from left to right and from right to left.
//	Example 2 :
//
//	Input : x = -121
//	Output : false
//	Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//	Example 3 :
//
//	Input : x = 10
//	Output : false
//	Explanation : Reads 01 from right to left.Therefore it is not a palindrome.
//
//
//	Constraints :
//
//	-231 <= x <= 231 - 1
//
bool isPalindrome(int x); 


//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//Return a boolean indicating whether the matching covers the entire input string(not partial).
//
//Example 1:
//
//Input: s = "aa", p = "a"
//	Output : false
//	Explanation : "a" does not match the entire string "aa".
//	Example 2 :
//
//	Input : s = "aa", p = "a*"
//	Output : true
//	Explanation : '*' means zero or more of the preceding element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
//	Example 3 :
//
//	Input : s = "ab", p = ".*"
//	Output : true
//	Explanation : ".*" means "zero or more (*) of any character (.)".
//
//	Constraints :
//
//	1 <= s.length <= 20
//	1 <= p.length <= 20
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '.', and '*'.
//	It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
//
bool isMatch(std::string s, std::string p); 



//You are given an integer array height of length n.There are n vertical lines drawn such that the two endpoints 
//of the ith line are(i, 0) and (i, height[i]).
//
//Find two lines that together with the x - axis form a container, such that the container contains the most water.
//
//Return the maximum amount of water a container can store.
//
//Notice that you may not slant the container.
//
//
//
//Example 1:
//Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
//	Output : 49
//	Explanation : The above vertical lines are represented by array[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section) the container can contain is 49.
//	Example 2:
//
//	Input: height = [1, 1]
//		Output : 1
//
//
//		Constraints :
//
//		n == height.length
//		2 <= n <= 105
//		0 <= height[i] <= 104
//
int maxArea(std::vector<int>& height);

};

//when i show you a problem.Please show an fair complicated example, and explain code each step, each loop, until the example is done.
//and please always use the time - efficient way to solve problem, as nowadyas, space is not as critical as speed.
