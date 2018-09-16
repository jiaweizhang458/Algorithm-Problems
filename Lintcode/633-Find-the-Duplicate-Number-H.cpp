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
//������ 1~n ��ȡ�м�ֵ m = (1 + n) / 2, ��ʱ���ְ��� 1~m, m + 1~n ���Σ�
//�������飬������� 1~m �ĸ���;
//������� 1~m �ĸ������� m��˵�� 1~m ��һ���ڿ϶����ظ����֣���ô����һ���ڼ���ȡ�м�ֵ�Ƚϣ�
//������� 1~m �ĸ������� m����һ�β�һ�����ظ����֣��ȽϺ�һ�Σ�
//������� 1~m �ĸ���С�� m��˵�� m + 1~n ��һ��һ�����ظ����֣��ں�һ��ȡ�м�ֵ�Ƚϣ�
//������������һֱȡ�м�ֵ�Ƚϣ�ֱ��ֻʣһ��������������ֳ��ִ������� 1 �������ּ�Ϊ�ظ�����

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