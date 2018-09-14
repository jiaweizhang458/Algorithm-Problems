//665. Range Sum Query 2D - Immutable
//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//Example
//Given matrix =
//
//[
//	[3, 0, 1, 4, 2],
//	[5, 6, 3, 2, 1],
//	[1, 2, 0, 1, 5],
//	[4, 1, 0, 1, 7],
//	[1, 0, 3, 0, 5]
//]
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12
//
//Notice
//You may assume that the matrix does not change.
//There are many calls to sumRegion function.
//You may assume that row1 ¡Ü row2 and col1 ¡Ü col2.



//Solution 1: Intuitive, improve below. 
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		rowNum = matrix.size();
		colNum = matrix[0].size();
		A.assign(matrix.begin(), matrix.end());
		C = vector<vector<int>>(rowNum, vector<int>(colNum, 0));
		C[0][0] = A[0][0];
		for (int i = 1; i < colNum; i++) {
			C[0][i] = C[0][i - 1] + A[0][i];
		}

		for (int i = 1; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (j == 0) {
					C[i][j] = C[i - 1][j] + A[i][j];
				}
				else {
					C[i][j] = C[i - 1][j] + C[i][j - 1] + A[i][j] - C[i - 1][j - 1];
				}
			}
		}

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row2 == 0 || col2 == 0) return C[row2][col2] - C[row1][col1] + A[row1][col1];
		else if (row1 == 0 && col1 == 0) {
			return C[row2][col2];
		}
		else if (row1 == 0) {
			return C[row2][col2] - C[row2][col1 - 1];
		}
		else if (col1 == 0) {
			return C[row2][col2] - C[row1 - 1][col2];
		}
		else {
			return C[row2][col2] - C[row2][col1 - 1] - C[row1 - 1][col2] + C[row1 - 1][col1 - 1];
		}
	}

private:
	int rowNum, colNum;
	vector<vector<int>> A;
	vector<vector<int>> C;
};



/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/


//Solution 2: Improvement on 'if' clause
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		rowNum = matrix.size();
		colNum = matrix[0].size();
		A.assign(matrix.begin(), matrix.end());
		C.assign(matrix.begin(), matrix.end());

		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (i > 0) C[i][j] += C[i - 1][j];
				if (j > 0) C[i][j] += C[i][j - 1];
				if (i > 0 && j > 0) C[i][j] -= C[i - 1][j - 1];
			}
		}

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int res = C[row2][col2];
		if (col1 > 0) res -= C[row2][col1 - 1];
		if (row1 > 0) res -= C[row1 - 1][col2];
		if (col1 > 0 && row1 > 0) res += C[row1 - 1][col1 - 1];
		return res;
	}

private:
	int rowNum, colNum;
	vector<vector<int>> A;
	vector<vector<int>> C;
};



/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
