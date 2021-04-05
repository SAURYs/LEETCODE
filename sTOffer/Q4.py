#二维(行列均有序)排序数组查找对应元素
#输入
#1 2 8 9
#2 4 9 12
#4 7 10 13
#6 8 11 15
#7
#输出 True
#二分查找的变形 持续二分查找 当查找范围缩减为一个2*2的数组时 挨个返回判断结果
#在python中 / 并不是整除，其返回值是一个浮点数，//才是整除
def findElement(w,e):
    m=len(w[0])
    n=len(w)
    i=0
    j=0
    def findElement2(w,e,i,j,m,n):
        if m-i<=1 and n-j<=1:
            if e == w[i][j] or e == w[m][n]:
                return True
            elif e == w[i][n] or e== w[m][j]:
                return True
            return False
        l=(i+m)//2
        r=(j+n)//2
        tmp=w[l][r]
        if e > tmp:
            print(tmp,l,r,m,n)
            return findElement2(w,e,l,r,m,n)
        elif e < tmp:
            print(tmp,l,r,m,n)
            return findElement2(w,e,i,j,l,r)
        else:
            return True
    return findElement2(w,e,i,j,m,n)

w=[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
print(w)
e=9
findE=findElement(w,e)
print(findE)



