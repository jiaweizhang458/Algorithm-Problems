//1470. The Game Of Take Numbers
//Now there is an array arr.There are two players, No. 1 and No. 2 take turns to get numbers from the array.
//They can only fetch from both ends of the array, and only one can be taken at a time.
//Both of them adopt an optimal strategy.After the number in the last array is taken, 
//the sum of the numbers taken is more, and the victory is won.Player No. 1 is taken first.Ask who will win in the end.If the No. 
//1 player wins or the two draw a tie, return 1 and if the 2nd player wins, return 2.
//
//Example
//Give arr = [1, 3, 1, 1].Return 1.
//
//sum1, sum2 are the scores of two players
//The optimal strategy for the No. 1 player takes the tail of the array, at which point the array is[1, 3, 1].sum1 = 1.
//At this time, the second player has two ways to take it.
//1,
//Player No. 2 takes the head and the array is[3, 1].sum2 = 1.
//Player No. 1 takes the head and the array is[1].sum1 = 4.
//Player No. 2 takes the head.sum2 = 2.
//Sum1>sum2
//2,
//Player No. 2 takes the head and the array is[1, 3].sum2 = 1.
//The first player takes the tail and the array is[1].sum1 = 4.
//Player No. 2 takes the head.sum2 = 2.
//sum1>sum2
//Therefore, player No. 1 must win and return 1.
//Give arr = [1, 3, 3, 1].Returns 1.
//
//Sum1, sum2 are the scores of two players
//Since the array is symmetrical, the player No. 1 starts from the head and tail and the result is the same.
//The first player takes the array header, and the array is[3, 3, 1].sum1 = 1.
//At this time, the second player has two ways to take it.
//1,
//Player No. 2 takes the head and the array is[3, 1].sum2 = 3.
//Player No. 1 takes the head and the array is[1].sum1 = 4.
//Player No. 2 takes the head.Sum2 = 4.
//sum1 = sum2
//2,
//Player No. 2 takes the tail and the array is[3, 3].sum2 = 1.
//Player No. 1 takes the head and the array is[3].sum1 = 4.
//Player No. 2 takes the head.Sum2 = 4.
//sum1 = sum2
//So the 1st player and the 2nd player draw a tie and return 1.
//Notice
//1 \leq n \leq 100001¡Ün¡Ü10000
//1 \leq arr[i] \leq 100001¡Üarr[i]¡Ü10000
//Ensure that the array length is even

//!!!!!!!!!!!!!!
//Length of list is even. Player 1 can always choose to get all even index or all odd index.
return 1;