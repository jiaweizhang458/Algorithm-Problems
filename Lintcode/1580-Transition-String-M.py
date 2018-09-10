'''
1580. Transition String

Give a startString, an endString, ask if you can transfer from start to end through a series of independent transformations. 
The rule is to have only 26 lowercase letters, and only one type of letter can be changed per operation. 
For example, if you change a to b, then all a in the start string must be b. 
For each type of character you can choose to convert or not convert, 
if you convert it must be converted to the corresponding character of endString. Return true or false.:
Example
Given : startString = "abc" ; endString = "cde"
Return : True

Explanation : "abc"->"abe"->"ade"->"cde"
'''

#Solution 1: only beats 20%
class Solution:
    """
    @param startString: 
    @param endString: 
    @return: Return true or false
    """
    def canTransfer(self, startString, endString):
        # Write your code here
        if (len(startString) != len(endString)):
            return False
        diff = {}
        a = set()
        b = set()
        for i in range(len(startString)):
            a.add(startString[i])
            b.add(endString[i])
            if (startString[i] not in diff):
                diff[startString[i]] = endString[i]
            else:
                if (endString[i] != diff[startString[i]]):
                    return False
        if (a == b):
            return False
        return True