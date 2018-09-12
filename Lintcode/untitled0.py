# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 13:45:50 2018

@author: jiawe
"""

Matrix = [[1,2,3],[4,5,6],[7,8,9]]
dp = Matrix[0]
N = len(Matrix)
for row in range(N):
    if row == 0:
        continue
    dp_row = []
    for col in range(N):
        min_list = []
        if col > 0:
            min_list.append(dp[col-1])
        if col < N - 1:
            min_list.append(dp[col+1])
        min_list.append(dp[col])
        cur_res = min(min_list) +  Matrix[row][col]
        dp_row.append(cur_res)
    dp = dp_row
print(dp)