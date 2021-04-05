#输出长为n数组中重复的数字 数字大小都在0~n-1的范围内
#输入[2,3,1,0,2,5,3] 对应输出2或3
#1.思考可以直接对数组进行遍历 使用set() 并循环判断set长度  O(n) 空间复杂度O(n)
#2.使用hash 此种类似set O(n) 空间复杂度O(n)
#3.排序后挨个读取sort()使用自带的sort库函数 O(nlogn) 空间复杂度O(1)
#4.挨个读取，如果i=w[i] continue 否则交换w[i] 和w[w[i]] 持续判断i和w[i]大小并交换
#企图使所有w[i]=i 并在构造这个过程中找出重复的值 O(n) 空间复杂度O(1)
w=[2,3,1,0,2,5,3]
#w=[1,3,2,0]
def getDuplicateElement(w):
    lenW=len(w)
    if lenW <= 1:
        return False #考虑输入的数组长度过短时不存在重复数字
    for i in range(lenW):
        if w[i] <0 or w[i]> lenW-1:
            return False #无效的输入
    for i in range(lenW):
        while i!= w[i]:
            if w[i] != w[w[i]]:
                c=w[i]
                w[i]=w[c]
                w[c]=c
            else:
                return w[i]
    return False #考虑输入的数组不存在重复数字
d=getDuplicateElement(w)
print(d)
