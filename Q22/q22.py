from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        List = ["()"]
        if n == 1:
            return List
        if n>1:
            List = Solution.generateParenthesis(n-1,n-1)
            list = []
            for str in List:
                str = '('+str
                for i in range(1,n*2-1):
                    print(i)
                    strNew = str[0:i]+')'+str[i:(n*2-1)]
                    if list.count(strNew) == 0:
                        list.append(strNew)
            return list



list = Solution.generateParenthesis(3,3)
print(list)

