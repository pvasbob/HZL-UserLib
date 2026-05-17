#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <queue>


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


//
//Seven different symbols represent Roman numerals with the following values :
//
//Symbol	Value
//I	1
//V	5
//X	10
//L	50
//C	100
//D	500
//M	1000
//
//Roman numerals are formed by appending the conversions of decimal place values from highest to lowest.Converting a decimal place value into a Roman numeral has the following rules :
//
//If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
//If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I)less than 5 (V) : IV and 9 is 1 (I)less than 10 (X) : IX.Only the following subtractive forms are used : 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
//Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D)multiple times.If you need to append a symbol 4 times use the subtractive form.
//Given an integer, convert it to a Roman numeral.
//
//
//
//Example 1:
//
//Input: num = 3749
//
//	Output : "MMMDCCXLIX"
//
//	Explanation :
//
//	3000 = MMM as 1000 (M)+1000 (M)+1000 (M)
//	700 = DCC as 500 (D)+100 (C)+100 (C)
//	40 = XL as 10 (X)less of 50 (L)
//	9 = IX as 1 (I)less of 10 (X)
//	Note : 49 is not 1 (I)less of 50 (L)because the conversion is based on decimal places
//	Example 2 :
//
//	Input : num = 58
//
//	Output : "LVIII"
//
//	Explanation :
//
//	50 = L
//	8 = VIII
//	Example 3 :
//
//	Input : num = 1994
//
//	Output : "MCMXCIV"
//
//	Explanation :
//
//	1000 = M
//	900 = CM
//	90 = XC
//	4 = IV
//
//
//	Constraints :
//
//	   1 <= num <= 3999
//
std::string intToRoman(int num); 


//Roman numerals are represented by seven different symbols : I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II.The number 27 is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//
//I can be placed before V(5) and X(10) to make 4 and 9.
//X can be placed before L(50) and C(100) to make 40 and 90.
//C can be placed before D(500) and M(1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer.
//
//
//
//Example 1:
//
//Input: s = "III"
//	Output : 3
//	Explanation : III = 3.
//	Example 2 :
//
//	Input : s = "LVIII"
//	Output : 58
//	Explanation : L = 50, V = 5, III = 3.
//	Example 3 :
//
//	Input : s = "MCMXCIV"
//	Output : 1994
//	Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.
//
//
//	Constraints :
//
//	1 <= s.length <= 15
//	s contains only the characters('I', 'V', 'X', 'L', 'C', 'D', 'M').
//	It is guaranteed that s is a valid roman numeral in the range[1, 3999].
//
int romanToInt(std::string s);


//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//
//
//Example 1:
//
//Input: strs = ["flower", "flow", "flight"]
//	Output : "fl"
//	Example 2 :
//
//	Input : strs = ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
//
//
//	Constraints :
//
//	1 <= strs.length <= 200
//	0 <= strs[i].length <= 200
//	strs[i] consists of only lowercase English letters if it is non - empty.
//
std::string longestCommonPrefix(std::vector<std::string>& strs); 


//Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.
//
//
//
//Example 1:
//
//Input: nums = [-1, 0, 1, 2, -1, -4]
//	Output : [[-1, -1, 2], [-1, 0, 1]]
//	Explanation :
//	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//	The distinct triplets are[-1, 0, 1] and [-1, -1, 2].
//	Notice that the order of the output and the order of the triplets does not matter.
//	Example 2:
//
//   Input: nums = [0, 1, 1]
//	   Output : []
//	   Explanation : The only possible triplet does not sum up to 0.
//	   Example 3 :
//
//	   Input : nums = [0, 0, 0]
//	   Output : [[0, 0, 0]]
//	   Explanation : The only possible triplet sums up to 0.
//
//
//	   Constraints :
//
//	   3 <= nums.length <= 3000
//	   - 105 <= nums[i] <= 105
//
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

//
//Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
//
//Return the sum of the three integers.
//
//You may assume that each input would have exactly one solution.
//
//
//
//Example 1:
//
//Input: nums = [-1, 2, 1, -4], target = 1
//	Output : 2
//	Explanation : The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//	Example 2 :
//
//	Input : nums = [0, 0, 0], target = 1
//	Output : 0
//	Explanation : The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
//
//
//	Constraints :
//
//	3 <= nums.length <= 500
//	- 1000 <= nums[i] <= 1000
//	- 104 <= target <= 104
//
int threeSumClosest(std::vector<int>& nums, int target);



//
//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.Return the answer in any order.
//
//A mapping of digits to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//Example 1:
//
//Input: digits = "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//	Example 2 :
//
//	Input : digits = "2"
//	Output : ["a", "b", "c"]
//
//
//	Constraints :
//
//	1 <= digits.length <= 4
//	digits[i] is a digit in the range['2', '9'].
//
std::vector<std::string> letterCombinations(std::string digits); 


//
//Given an array nums of n integers, return an array of all the unique quadruplets[nums[a], nums[b], nums[c], nums[d]] such that :
//
//0 <= a, b, c, d < n
//	a, b, c, and d are distinct.
//	nums[a] + nums[b] + nums[c] + nums[d] == target
//	You may return the answer in any order.
//
//
//
//	Example 1:
//
//Input: nums = [1, 0, -1, 0, -2, 2], target = 0
//	Output : [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
//	Example 2 :
//
//	Input : nums = [2, 2, 2, 2, 2], target = 8
//	Output : [[2, 2, 2, 2]]
//
//
//	Constraints :
//
//	1 <= nums.length <= 200
//	- 109 <= nums[i] <= 109
//	- 109 <= target <= 109
//
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);


//Given the head of a linked list, remove the nth node from the end of the list and return its head.
//Input: head = [1, 2, 3, 4, 5], n = 2
//	Output : [1, 2, 3, 5]
//	Example 2 :
//
//	Input : head = [1], n = 1
//	Output : []
//	Example 3 :
//
//	Input : head = [1, 2], n = 1
//	Output : [1]
//
//
//	Constraints :
//
//	The number of nodes in the list is sz.
//	1 <= sz <= 30
//	0 <= Node.val <= 100
//	1 <= n <= sz
//
ListNode* removeNthFromEnd(ListNode* head, int n);


//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
//
//
//Example 1:
//
//Input: s = "()"
//
//	Output : true
//
//	Example 2 :
//
//	Input : s = "()[]{}"
//
//	Output : true
//
//	Example 3 :
//
//	Input : s = "(]"
//
//	Output : false
//
//	Example 4 :
//
//	Input : s = "([])"
//
//	Output : true
//
//	Example 5 :
//
//	Input : s = "([)]"
//
//	Output : false
//
//
//
//	Constraints :
//
//	1 <= s.length <= 104
//	s consists of parentheses only '()[]{}'.
//
bool isValid(std::string s);

//You are given the heads of two sorted linked lists list1 and list2.
//
//Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
//
//Return the head of the merged linked list.
//
//Example 1:
//Input: list1 = [1, 2, 4], list2 = [1, 3, 4]
//	Output : [1, 1, 2, 3, 4, 4]
//	Example 2 :
//
//	Input : list1 = [], list2 = []
//	Output : []
//	Example 3 :
//
//	Input : list1 = [], list2 = [0]
//	Output : [0]
//
//
//	Constraints :
//
//	The number of nodes in both lists is in the range[0, 50].
//	- 100 <= Node.val <= 100
//	Both list1 and list2 are sorted in non - decreasing order.
//
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);


//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//Example 1:
//
//Input: n = 3
//	Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
//	Example 2 :
//
//	Input : n = 1
//	Output : ["()"]
//
//
//	Constraints :
//
//	1 <= n <= 8

std::vector<std::string> generateParenthesis(int n);

//
//You are given an array of k linked - lists lists, each linked - list is sorted in ascending order.
//Merge all the linked - lists into one sorted linked - list and return it.
//
//Example 1:
//
//Input: lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
//	Output : [1, 1, 2, 3, 4, 4, 5, 6]
//	Explanation : The linked - lists are :
//	   [
//		   1->4->5,
//		   1->3->4,
//		   2->6
//	   ]
//	   merging them into one sorted linked list :
//	   1->1->2->3->4->4->5->6
//		   Example 2 :
//
//		   Input : lists = []
//		   Output : []
//		   Example 3 :
//
//		   Input : lists = [[]]
//		   Output : []
//
//
//		   Constraints :
//
//		   k == lists.length
//		   0 <= k <= 104
//		   0 <= lists[i].length <= 500
//		   - 104 <= lists[i][j] <= 104
//		   lists[i] is sorted in ascending order.
//		   The sum of lists[i].length will not exceed 104.
//
ListNode* mergeKLists(std::vector<ListNode*>& lists); 


//Given a linked list, swap every two adjacent nodes and return its head.You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
//Example 1:
//
//	Example 1 :
//Input: head = [1, 2, 3, 4]
//	Output : [2, 1, 4, 3]
//	Example 2 :
//	Input : head = []
//	Output : []
//	Example 3 :
//	Input : head = [1]
//	Output : [1]
//	Example 4 :
//	Input : head = [1, 2, 3]
//	Output : [2, 1, 3]
//
ListNode* swapPairs1(ListNode* head);
ListNode* swapPairs2(ListNode* head);


//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes, in the end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.
//
//
//Example 1:
//Input: head = [1, 2, 3, 4, 5], k = 2
//	Output : [2, 1, 4, 3, 5]
//
//Example 2 :
//Input : head = [1, 2, 3, 4, 5], k = 3
//	Output : [3, 2, 1, 4, 5]
//
//
//	Constraints :
//
//	The number of nodes in the list is n.
//	1 <= k <= n <= 5000
//	0 <= Node.val <= 1000
//
ListNode* reverseKGroup(ListNode* head, int k);


//Given an integer array nums sorted in non - decreasing order, remove the duplicates in - place such 
//that each unique element appears only once.The relative order of the elements should be kept the same.
//
//Example 1:
//
//Input: nums = [1, 1, 2]
//	Output : 2, nums = [1, 2, _]
//	Explanation : Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
//	It does not matter what you leave beyond the returned k(hence they are underscores).
//	Example 2 :
//
//	Input : nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//	Output : 5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]
//	Explanation : Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
//	It does not matter what you leave beyond the returned k(hence they are underscores).
//
//
int removeDuplicates(std::vector<int>& nums); 

//Given an integer array nums and an integer val, remove all occurrences of val in nums in - place.
//The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.
//
//Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things :
//
//Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//The remaining elements of nums are not important as well as the size of nums.
//Return k.
//
int removeElement(std::vector<int>& nums, int val);

//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//Example 1:
//
//Input: haystack = "sadbutsad", needle = "sad"
//	Output : 0
//	Explanation : "sad" occurs at index 0 and 6.
//	The first occurrence is at index 0, so we return 0.
//	Example 2 :
//
//	Input : haystack = "leetcode", needle = "leeto"
//	Output : -1
//	Explanation : "leeto" did not occur in "leetcode", so we return -1.
//
//
//	Constraints :
//
//	1 <= haystack.length, needle.length <= 104
//	haystack and needle consist of only lowercase English characters.
//
int strStr(std::string haystack, std::string needle);

};

//when i show you a problem.Please show an fair complicated example, and explain code each step, each loop, until the example is done.
//and please always use the time - efficient way to solve problem, as nowadyas, space is not as critical as speed.

