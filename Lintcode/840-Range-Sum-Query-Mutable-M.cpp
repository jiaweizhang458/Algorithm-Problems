//840. Range Sum Query - Mutable
//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//
//Example
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//Notice
//1.The array is only modifiable by the update function.
//2.You may assume the number of calls to update and sumRange function is distributed evenly.


//Solution: Binary Indexed Tree:
//Reference: https://www.jiuzhang.com/tutorial/binary-indexed-tree/297
class NumArray {
public:

	int lowbit(int i) {
		return i & (-i);
	}

	void add(int i, int val) {
		for (int j = i; j <= N; j += lowbit(j)) {
			C[j] += val;
		}
	}

	int sum(int i) {
		int res = 0;
		for (int j = i; j > 0; j -= lowbit(j)) {
			res += C[j]
		}
		return res;
	}



	NumArray(vector<int> nums) {
		N = nums.size();
		A.resize(N + 1);
		C.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			A[i] = nums[i - 1];
			add(i, A[i]);
		}
	}

	void update(int i, int val) {
		add(i + 1, val - A[i + 1]);
		A[i + 1] = val;
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i + 1 - 1);
	}

private:
	int N;
	vector<int> A;
	vector<int> C;

};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
/