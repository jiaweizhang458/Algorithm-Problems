//633. Find the Duplicate Number
//Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), 
//prove that at least one duplicate number must exist.Assume that there is only one duplicate number, find the duplicate one.
//
//Example
//Given nums = [5, 5, 4, 3, 2, 1] return 5
//Given nums = [5, 4, 4, 3, 2, 1] return 4
//
//Notice
//You must not modify the array(assume the array is read only).
//You must use only constant, O(1) extra space.
//Your runtime complexity should be less than O(n ^ 2).
//There is only one duplicate number in the array, but it could be repeated more than once.

//Solution 1: Binary search:
//Reference: https://www.jianshu.com/p/b35c528e01d7
//在数字 1~n 中取中间值 m = (1 + n) / 2, 此时数字包括 1~m, m + 1~n 两段；
//遍历数组，获得数字 1~m 的个数;
//如果数字 1~m 的个数大于 m，说明 1~m 这一段内肯定有重复数字，那么在这一段内继续取中间值比较；
//如果数字 1~m 的个数等于 m，这一段不一定有重复数字，比较后一段；
//如果数字 1~m 的个数小于 m，说明 m + 1~n 这一段一定有重复数字，在后一段取中间值比较；
//按照上述方法一直取中间值比较，直到只剩一个数字且这个数字出现次数超过 1 ，该数字即为重复数字

class Solution {
public:
	/**
	* @param nums: an array containing n + 1 integers which is between 1 and n
	* @return: the duplicate one
	*/
	int findDuplicate(vector<int> &nums) {
		// write your code here
		int start = 1;
		int end = nums.size() - 1;
		if (start == end) return start;
		while (start != end) {
			int mid = start + (end - start) / 2;
			int cnt = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] <= mid) cnt++;
			}
			if (cnt > mid) end = mid;
			else start = mid + 1;
		}
		return end;
	}
};

//Solution 2: Linked List
class Solution {
public:
	/**
	* @param nums: an array containing n + 1 integers which is between 1 and n
	* @return: the duplicate one
	*/
	int findDuplicate(vector<int> &nums) {
		int slow, fast;
		slow = 0;
		fast = 0;
		while (1) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		slow = 0;
		while (1) {
			slow = nums[slow];
			fast = nums[fast];
			if (slow == fast) break;
		}
		return slow;

	}
};