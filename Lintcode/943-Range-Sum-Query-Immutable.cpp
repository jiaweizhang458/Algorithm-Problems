//943. Range Sum Query - Immutable
//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//Example
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> - 1
//sumRange(0, 5) -> - 3
//Notice
//You may assume that the array does not change.
//There are many calls to sumRange function.

class NumArray {
public:
	NumArray(vector<int> nums) {
		sumNums = vector<int>(nums.size(), 0);
		sumNums[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			sumNums[i] = sumNums[i - 1] + nums[i];
			std::cout << sumNums[i] << std::endl;
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) return sumNums[j];
		return sumNums[j] - sumNums[i - 1];
	}
private:
	vector<int> sumNums;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/