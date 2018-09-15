//817. Range Sum Query 2D - Mutable
//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//Example
//Given matrix = [
//	[3, 0, 1, 4, 2],
//		[5, 6, 3, 2, 1],
//		[1, 2, 0, 1, 5],
//		[4, 1, 0, 1, 7],
//		[1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//update(3, 2, 2)
//sumRegion(2, 1, 4, 3) -> 10
//Notice
//1.The matrix is only modifiable by the update function.
//2.You may assume the number of calls to update and sumRegion function is distributed evenly.
//3.You may assume that row1 ¡Ü row2 and col1 ¡Ü col2.


//Solution: Binary Indexed Tree
//Reference: https://www.jiuzhang.com/tutorial/binary-indexed-tree/298
class NumMatrix {
public:

	int lowbit(int x) {
		return x & (-x);
	}

	int sum(int row, int col) {
		int res = 0;
		row++;
		col++;
		for (int i = row; i > 0; i -= lowbit(i)) {
			for (int j = col; j > 0; j -= lowbit(j)) {
				res += C[i][j];
			}
		}
		return res;
	}

	NumMatrix(vector<vector<int>> matrix) {
		rowNum = matrix.size();
		colNum = matrix[0].size();
		vector<int> temp(colNum + 1, 0);
		A.assign(rowNum + 1, temp);
		C.assign(rowNum + 1, temp);

		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				update(i, j, matrix[i][j]);
			}
		}
	}

	void update(int row, int col, int val) {
		row++;
		col++;
		int diff = val - A[row][col];
		A[row][col] = val;
		for (int i = row; i <= rowNum; i += lowbit(i)) {
			for (int j = col; j <= colNum; j += lowbit(j)) {
				C[i][j] += diff;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum(row2, col2) - sum(row2, col1 - 1) - sum(row1 - 1, col2) + sum(row1 - 1, col1 - 1);
	}

private:
	vector<vector<int>> A;
	vector<vector<int>> C;
	int rowNum;
	int colNum;

};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* obj.update(row,col,val);
* int param_2 = obj.sumRegion(row1,col1,row2,col2);
*/