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


std::string Solution::longestPalindrome(std::string s) 
{
	// 1. Pre-process to handle even/odd symmetry
	std::string t = "#";
	for (char c : s) 
	{ 
		t += c; 
		t += "#"; 
	}

	size_t n = t.length();
	std::vector<int> p(n, 0); // Palindrome radius array
	int center = 0, right = 0;
	int maxLen = 0, maxCenter = 0;

	for (int i = 0; i < n; ++i) 
	{
		// 2. Use the "Mirror Trick" to skip redundant work
		if (i < right) 
		{
			// center >= right - center  > i - center 
			// center - (i-center) > 0
			// mirror  = 2*center -i  > 0
			int mirror = 2 * center - i;
			p[i] = std::min(right - i, p[mirror]);
		}

		// 3. Attempt expansion beyond what symmetry guarantees
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
			t[i - p[i] - 1] == t[i + p[i] + 1]) {
			p[i]++;
		}

		// 4. Update the "Frontier" if we found a palindrome reaching further right
		// algorithm does not care about the "biggest" palindrome found so far; it cares about the "furthest" one.
		if (i + p[i] > right) {
			center = i;
			right = i + p[i];
		}

		if (p[i] > maxLen) {
			maxLen = p[i];
			maxCenter = i;
		}
	}
	return s.substr((maxCenter - maxLen) / 2, maxLen);
}




std::string Solution::convert(std::string s, int numRows) {
	// 1. Handle edge cases: No zigzag possible
	if (numRows <= 1 || s.length() <= numRows) return s;

	std::string result;
	size_t n = s.length();

	// 2. The Period (Step size): One full "V" shape cycle
	// Down (numRows) + Up (numRows - 2)
	int cycleLen = 2 * numRows - 2;

	// 3. Optimization: Allocate all memory at once
	result.reserve(n);

	// 4. Iterate row by row
	for (int i = 0; i < numRows; i++) {
		// Traverse the string in jumps of cycleLen
		for (int j = 0; j + i < n; j += cycleLen) {

			// --- Step A: The Vertical Character ---
			// Every row has at least one character per cycle
			result += s[j + i];

			// --- Step B: The Diagonal Character ---
			// Middle rows (not top, not bottom) have a second character
			if (i != 0 && i != numRows - 1) {
				int diagonalIdx = j + cycleLen - i; // The "Reflected" index

				if (diagonalIdx < n) {
					result += s[diagonalIdx];
				}
			}
		}
	}

	return result;
}



int Solution::reverse(int x) {
	int rev = 0;
	while (x != 0) {
		// Step 1: Extract the digit
		int pop = x % 10;
		x /= 10;

		// -2,147,483,648 to 2,147,483,647.
		// Step 2: Portable Overflow Check
		// We check if multiplying 'rev' by 10 will exceed INT_MAX.
		// INT_MAX / 10 is a constant (214748364).
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;

		// Step 3: Portable Underflow Check
		// INT_MIN / 10 is a constant (-214748364).
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

		// Step 4: Combine
		rev = rev * 10 + pop;
	}
	return rev;
}


// Fast I/O optimization
// The compiler sees static const int _, executes the lambda, and breaks the sync between C and C++ streams.
// lambda function: one time setup routine.
// static keyword is the engine that forces the execution to happen during that loading/initialization window.
// and after that the main() begins.
static const int _ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

int Solution::myAtoi(std::string s) {
	size_t i = 0;
	size_t n = s.length();

	// 1. Skip leading whitespace
	while (i < n && s[i] == ' ') {
		i++;
	}

	if (i == n) return 0;

	// 2. Handle sign
	int sign = 1;
	if (s[i] == '-') {
		sign = -1;
		i++;
	}
	else if (s[i] == '+') {
		i++;
	}

	// 3. Convert digits and check for overflow
	int res = 0;
	while (i < n && s[i] >= '0' && s[i] <= '9') {
		int digit = s[i] - '0';

		// Overflow check (identical logic to Integer Reverse)
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
			return (sign == 1) ? INT_MAX : INT_MIN;
		}

		res = res * 10 + digit;
		i++;
	}

	return res * sign;
}


bool Solution::isPalindrome(int x) {
	// Special cases:
			// x < 0 is never a palindrome.
			// If the last digit is 0, the first digit must also be 0 (only 0 itself fits this).
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	int revertedNumber = 0;
	while (x > revertedNumber) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
	// For example, when x = 121, at the end of the loop we have x = 1, revertedNumber = 12
	// Since the middle digit doesn't matter in palindrome check, we can simply eliminate it.
	return x == revertedNumber || x == revertedNumber / 10;

}

bool Solution::isMatch(std::string s, std::string p) {
	int m = s.length();
	int n = p.length();

	// dp[i][j] means s[0..i-1] matches p[0..j-1]
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

	dp[0][0] = true;

	// Deailing with patterns that can match an empty string (e.g., a*, a*b*)
	for (int j = 2; j <= n; j++) {
		if (p[j - 1] == '*') {
			dp[0][j] = dp[0][j - 2];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') 
			{
				// Case 1: * counts as empty (skip the character and the *)
				dp[i][j] = dp[i][j - 2];

				// Case 2: * counts as one or more (if preceding char matches)
				if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
			}
		}
	}

	return dp[m][n];
}

int Solution::maxArea(std::vector<int>& height) {
	int max_water = 0;
	int left = 0;
	int right = height.size() - 1;

	while (left < right) {
		// Calculate current height and width
		int h = std::min(height[left], height[right]);
		int w = right - left;

		// Update maximum area if current is larger
		max_water = std::max(max_water, h * w);

		// Move the pointer pointing to the shorter line
		if (height[left] < height[right]) {
			left++;
		}
		else {
			right--;
		}
	}

	return max_water;
}

std::string Solution::intToRoman(int num) {
	// Define the mapping of values to Roman numeral symbols
	// Including the special subtractive cases (900, 400, etc.)
	const std::vector<std::pair<int, std::string>> romanMap = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
		{10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
		{1, "I"}
	};

	std::string result = "";

	for (const auto& [value, symbol] : romanMap) {
		// Greedily append the largest possible symbols
		while (num >= value) {
			result += symbol;
			num -= value;
		}
		// Optimization: if num hits 0, we can stop early
		if (num == 0) break;
	}

	return result;

}


int Solution::romanToInt(std::string s) {
	// Create a fixed-size array for ASCII characters.
		// This is faster than unordered_map as it avoids hashing and heap access.
	int values[128];
	values['I'] = 1;
	values['V'] = 5;
	values['X'] = 10;
	values['L'] = 50;
	values['C'] = 100;
	values['D'] = 500;
	values['M'] = 1000;

	int total = 0;
	int n = s.length();

	for (int i = 0; i < n; ++i) {
		// Standard Roman numeral logic: if current < next, subtract.
		// Using s[i+1] is safe because the string is null-terminated ('\0').
		// values['\0'] is uninitialized here, so we check index bounds.
		if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
			total -= values[s[i]];
		}
		else {
			total += values[s[i]];
		}
	}

	return total;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
	if (strs.empty()) return "";

	// Sort the strings lexicographically
	std::sort(strs.begin(), strs.end());

	std::string first = strs[0];
	std::string last = strs[strs.size() - 1];
	std::string result = "";

	// Compare the first and last strings only
	for (int i = 0; i < std::min(first.length(), last.length()); i++) {
		if (first[i] != last[i]) {
			return result;
		}
		result += first[i];
	}

	return result;
}



std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
	std::vector<std::vector<int>> res;
	std::sort(nums.begin(), nums.end()); // O(N log N)
	int n = nums.size();

	for (int i = 0; i < n - 2; ++i) {
		// Optimization 1: If smallest number > 0, sum can't be 0.
		if (nums[i] > 0) break;

		// Optimization 2: Skip duplicates for the fixed pointer.
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int left = i + 1, right = n - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0) {
				res.push_back({ nums[i], nums[left], nums[right] });
				// Optimization 3: Skip duplicates for left/right pointers.
				while (left < right && nums[left] == nums[left + 1]) left++;
				while (left < right && nums[right] == nums[right - 1]) right--;
				left++;
				right--;
			}
			else if (sum < 0) {
				left++; // Need a larger value.
			}
			else {
				right--; // Need a smaller value.
			}
		}
	}
	return res;
}

int Solution::threeSumClosest(std::vector<int>& nums, int target) {
	int n = nums.size();
	std::sort(nums.begin(), nums.end());
	int closestSum = nums[0] + nums[1] + nums[2];

	for (int i = 0; i < n - 2; ++i) {
		// Optimization: Skip duplicate values for the first element
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int left = i + 1;
		int right = n - 1;

		while (left < right) {
			int currentSum = nums[i] + nums[left] + nums[right];

			if (currentSum == target) {
				return currentSum;
			}

			// Update closestSum if the current deviation is smaller
			if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
				closestSum = currentSum;
			}

			if (currentSum < target) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	return closestSum;
}

std::vector<std::string> Solution::letterCombinations(std::string digits) {
	if (digits.empty()) return {};

	static const std::string mapping[] = {
		"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
	};

	std::vector<std::string> result = { "" };

	// Pre-calculate total combinations to reserve memory
	int totalSize = 1;
	for (char d : digits) totalSize *= mapping[d - '0'].size();
	result.reserve(totalSize);

	for (char digit : digits) {
		const std::string& letters = mapping[digit - '0'];
		std::vector<std::string> temp;
		// result.size() returns the number of elements (strings)
		temp.reserve(result.size() * letters.size());

		for (const std::string& combination : result) {
			for (char l : letters) {
				temp.push_back(combination + l);
			}
		}
		result = std::move(temp); // Efficiently swap buffers
	}

	return result;
}

std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target) {
	std::vector<std::vector<int>> result;
	int n = nums.size();
	if (n < 4) return result;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 3; ++i) {
		// Skip duplicates for the first number
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		// Pruning 1: Smallest possible sum is too large
		if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
		// Pruning 2: Largest possible sum is too small
		if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

		for (int j = i + 1; j < n - 2; ++j) {
			// Skip duplicates for the second number
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;

			// Pruning 3: Smallest possible sum for this j is too large
			if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
			// Pruning 4: Largest possible sum for this j is too small
			if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

			int left = j + 1;
			int right = n - 1;

			while (left < right) {
				long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

				if (sum == target) {
					result.push_back({ nums[i], nums[j], nums[left], nums[right] });
					// Skip duplicates for the third and fourth numbers
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;
					left++;
					right--;
				}
				else if (sum < target) {
					left++;
				}
				else {
					right--;
				}
			}
		}
	}
	return result;
}


ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0, head);
	ListNode* fast = dummy;
	ListNode* slow = dummy;

	// Move fast so that there is a gap of n nodes between fast and slow
	for (int i = 0; i <= n; ++i) {
		fast = fast->next;
	}

	// Move fast to the end, maintaining the gap
	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	// Skip the nth node from the end
	ListNode* nodeToDelete = slow->next;
	slow->next = slow->next->next;

	// Clean up memory (optional in LeetCode, but good practice)
	delete nodeToDelete;

	ListNode* newHead = dummy->next;
	delete dummy;
	return newHead;
}


bool Solution::isValid(std::string s) {
	std::stack<char> st;
	std::unordered_map<char, char> bracketMap = {
		{')', '('},
		{'}', '{'},
		{']', '['}
	};

	for (char c : s) {
		// If the character is a closing bracket
		if (bracketMap.count(c)) {
			// Check if stack is empty or top doesn't match
			if (st.empty() || st.top() != bracketMap[c]) {
				return false;
			}
			st.pop();
		}
		else {
			// If it's an opening bracket, push to stack
			st.push(c);
		}
	}

	return st.empty();
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
	// Create a dummy node to act as the starting point
	ListNode dummy(0);
	ListNode* tail = &dummy;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val <= list2->val) {
			tail->next = list1;   // Connect the smaller node
			list1 = list1->next;  // Move the list1 pointer
		}
		else {
			tail->next = list2;   // Connect the smaller node
			list2 = list2->next;  // Move the list2 pointer
		}
		tail = tail->next;        // Move the tail forward
	}

	// If one list is exhausted, attach the rest of the other list
	if (list1 != nullptr) {
		tail->next = list1;
	}
	else {
		tail->next = list2;
	}

	// Return the actual head (the node after our dummy)
	return dummy.next;

}


std::vector<std::string> Solution::generateParenthesis(int n) {
	std::vector<std::string> result;
	// Optimization: Pre-allocate a string of the required size
	std::string current(2 * n, ' ');

	// Using a generic lambda (C++14) to avoid std::function overhead
	auto backtrack = [&](auto self, int open, int close, int index) -> void {
		if (index == 2 * n) {
			result.push_back(current);
			return;
		}

		if (open < n) {
			current[index] = '(';
			self(self, open + 1, close, index + 1);
		}
		if (close < open) {
			current[index] = ')';
			self(self, open, close + 1, index + 1);
		}
	};

	backtrack(backtrack, 0, 0, 0);
	return result;
}


std::vector<std::string> generateParenthesis(int n) {
	std::vector<std::string> result;

	// 1. Address Memory Allocation:
	// The 8th Catalan number is 1430. Reserving space avoids 
	// all internal vector reallocations and data copying.
	result.reserve(1430);

	// 2. Address Recursion/String Overhead:
	// Pre-size the string so we only overwrite indices 
	// instead of calling push_back/pop_back.
	std::string current(2 * n, ' ');

	// Using a "Fixed-Type" Lambda to avoid std::function overhead.
	// We pass the lambda to itself as the first argument.
	auto backtrack = [&](auto& self, int open, int close, int index) -> void {
		// Base case
		if (index == 2 * n) {
			result.push_back(current);
			return;
		}

		// Branch 1: Add opening
		if (open < n) {
			current[index] = '(';
			self(self, open + 1, close, index + 1);
		}

		// Branch 2: Add closing
		if (close < open) {
			current[index] = ')';
			self(self, open, close + 1, index + 1);
		}
	};

	backtrack(backtrack, 0, 0, 0);
	return result;
}


ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
	// Lambda comparator for a min-heap based on node values
	auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
	std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);

	// Initialize heap with the head of each non-empty list
	for (auto l : lists) {
		if (l) minHeap.push(l);
	}

	ListNode dummy(0);
	ListNode* curr = &dummy;

	while (!minHeap.empty()) {
		ListNode* smallest = minHeap.top();
		minHeap.pop();

		curr->next = smallest;
		curr = curr->next;

		// If the popped node has a successor, push it back into the heap
		if (smallest->next) {
			minHeap.push(smallest->next);
		}
	}

	return dummy.next;

}


ListNode* Solution::swapPairs1(ListNode* head) {
	// Pointer to a pointer allows us to modify the 'next' 
		// field of the previous node (or the head itself) uniformly.
	ListNode** pp = &head;

	// Lambda for swapping pairs to keep the loop clean and performant
	auto swapNextTwo = [](ListNode** indirect) {
		ListNode* a = *indirect;
		ListNode* b = a->next;

		// Perform the swap
		a->next = b->next;
		b->next = a;
		// 
		(*indirect)->next = (*indirect)->next->next;
		(*indirect)->next->next = *indirect;



		// Update the pointer that was pointing to 'a' to now point to 'b'
		*indirect = b;
	};

	// Standard while loop is faster than recursion due to lack of stack overhead
	while (*pp && (*pp)->next) {
		swapNextTwo(pp);
		// Move pp to the 'next' pointer of the new second node in the pair
		pp = &((*pp)->next->next);
	}

	return head;
}


ListNode* Solution::swapPairs2(ListNode* head) {
	// High-performance early exit optimization
	if (!head || !head->next)[[unlikely]]{
		return head;
	}

		// Modern stack-allocated dummy node to eliminate initial null checks
	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;

	// High-performance lambda defined locally to manage the swap execution.
	// Capturing by reference allows zero-overhead access to the execution context.
	auto performSwap = [](ListNode* prior, ListNode* first) noexcept[[dont_discard]]->ListNode*{
		ListNode* second = first->next;

	// Re-link the nodes
	first->next = second->next;
	second->next = first;
	prior->next = second;

	// Return the new trailing node for the next iteration step
	return first;
	};

	// Standard iterative traversal loop
	// Passing both arguments leverages values already loaded into CPU registers during the loop 
	// condition check. This prevents redundant memory reads, avoids pointer-chasing overhead inside 
	// the lambda, and allows the compiler to map the node addresses directly to high-speed hardware 
	// registers (RDI and RSI) for maximum execution velocity.
	while (prev->next && prev->next->next) {
		// Pass the anchor node and the first node of the pair to the lambda
		prev = performSwap(prev, prev->next);
	}

	return dummy.next;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
	// High-performance early exit optimization
	if (!head || k == 1)[[unlikely]]{
		return head;
	}

		// Stack-allocated dummy anchor to eliminate the "head" special case
	ListNode dummy(0);
	dummy.next = head;
	ListNode* group_prev = &dummy;

	// Lambda to reverse a sub-list of exactly k nodes.
	// Accepts the boundary anchors to maintain optimal CPU register mapping.
	auto reverseNextK = [k](ListNode* prior, ListNode* first) noexcept[[dont_discard]]->ListNode*{
		ListNode* curr = first;
		ListNode* prev = nullptr;
		ListNode* next_node = nullptr;

		// Standard iterative in-place reversal loop for k nodes
		for (int i = 0; i < k; ++i) {
			next_node = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next_node;
		}

		// Connect the reversed segment back into the main list topology
		prior->next = prev;
		first->next = curr;

		// Return the new tail of the reversed group (the original 'first' node)
		return first;
	};

	while (true) {
		// Fast check: Verify if there are at least k nodes remaining
		ListNode* tracker = group_prev;
		for (int i = 0; i < k && tracker; ++i) {
			tracker = tracker->next;
		}

		// If fewer than k nodes remain, leave them untouched and terminate
		if (!tracker) {
			break;
		}

		// Execute the batch reversal and advance group_prev to the new tail
		group_prev = reverseNextK(group_prev, group_prev->next);
	}

	return dummy.next;
}


int Solution::removeDuplicates(std::vector<int>& nums) {
	// Quick escape for empty arrays to avoid edge-case errors
	if (nums.empty()) return 0;

	// 'write_idx' tracks where the next unique element should be placed
	int write_idx = 1;

	// Modern range-based loop with a lambda helper for filtering
	// The lambda captures nothing and compiles down to an inline comparison
	auto is_duplicate = [](int current, int previous) noexcept {
		return current == previous;
	};

	for (size_t read_idx = 1; read_idx < nums.size(); ++read_idx) {
		if (!is_duplicate(nums[read_idx], nums[write_idx - 1])) {
			nums[write_idx] = nums[read_idx];
			++write_idx;
		}
	}

	return write_idx;
}


int Solution::removeElement(std::vector<int>& nums, int val) {
	int k = 0;

	// A stateful lambda that mutates the vector in-place using the captured tracking index 'k'
	// 'mutable' isn't needed here because we capture 'k' by reference, allowing us to modify it
	auto process_element = [val, &k, &nums](const int num) noexcept {
		if (num != val) {
			nums[k++] = num;
		}
	};

	// Use std::for_each to pass every element into our modern lambda pipeline
	std::for_each(nums.begin(), nums.end(), process_element);

	return k;
}


int Solution::strStr(std::string haystack, std::string needle) {
	// Step 1: Use string_view for ultra-fast, zero-copy windowing
	std::string_view h(haystack);
	std::string_view n(needle);

	const size_t h_len = h.length();
	const size_t n_len = n.length();

	if (n_len == 0) return 0;
	if (h_len < n_len) return -1;

	// Fast path check for single characters
	if (n_len == 1) {
		auto pos = h.find(n[0]);
		return (pos == std::string_view::npos) ? -1 : static_cast<int>(pos);
	}

	// Step 2: Use a high-performance modern lambda for scanning
	// We limit the search space up to (h_len - n_len)
	const size_t max_search_idx = h_len - n_len;
	const char first_char = n[0];

	for (size_t i = 0; i <= max_search_idx; ++i) {
		// Micro-optimization: Skip immediately if the first character doesn't match
		if (h[i] != first_char) continue;

		// Modern direct memory comparison via string_view slicing
		// Compilers heavily optimize substr() comparison into vector instructions (SIMD memcmp)
		if (h.substr(i, n_len) == n) {
			return static_cast<int>(i);
		}
	}

	return -1;
}
