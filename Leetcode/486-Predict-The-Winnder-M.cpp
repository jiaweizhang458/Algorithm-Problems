//486. Predict the Winner
//
//Given an array of scores that are non - negative integers.Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on.Each time a player picks a number, that number will not be available for the next player.This continues until all the scores have been chosen.The player with the maximum score wins.
//
//Given an array of scores, predict whether player 1 is the winner.You can assume each player plays to maximize his score.
//
//Example 1:
//Input: [1, 5, 2]
//Output : False
//Explanation : Initially, player 1 can choose between 1 and 2.
//If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
//So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
//Hence, player 1 will never be the winner and you need to return False.
//
//Example 2 :
//Input : [1, 5, 233, 7]
//Output : True
//Explanation : Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
//Finally, player 1 has more score(234) than player 2 (12), so you need to return True representing player1 can win.
//
//Note :
//	1 <= length of the array <= 20.
//	Any scores in the given array are non - negative integers and will not exceed 10, 000, 000.
//	If the scores of both players are equal, then player 1 is still the winner.


//Solution 1: min-max + recursion. No dp
//Reference: https://www.youtube.com/watch?v=g5wLHFTodm0

class Solution {
public:

	int helper(vector<int>& nums, int i, int j) { // max(scoreA - scoreB)
		if (i == j) {
			return nums[i];
		}
		int temp = max(nums[i] - helper(nums, i + 1, j), nums[j] - helper(nums, i, j - 1));
		return temp;
	}

	bool PredictTheWinner(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1) >= 0;
	}
};

//Solution 2: DP
//Reference: https://www.youtube.com/watch?v=g5wLHFTodm0
class Solution {
public:

	int helper(const vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
		if (i == j) {
			return nums[i];
		}
		if (dp[i][j]) {
			return dp[i][j];
		}
		int temp = max(nums[i] - helper(nums, i + 1, j, dp), nums[j] - helper(nums, i, j - 1, dp));
		dp[i][j] = temp;
		return temp;
	}

	bool PredictTheWinner(vector<int>& nums) {
		vector<int> dp_row(nums.size(), 0);
		vector<vector<int>> dp(nums.size(), dp_row);
		return helper(nums, 0, nums.size() - 1, dp) >= 0;
	}

};