#替换字符串中的空格为%x  其中x为空格的ASCII码的16进制数
#空格的ASCII码为32 即0x20
#如果是C/C++ 如果需要对字符串本身进行操作 我们只需先统计出空格的数量
#并直接按照对应内存大小进行后续的移动赋值即可
#如果是需要新建字符串，则可以直接判断并对新的字符串原地赋值
#Python：python中有replace 函数
#str.replace(old,new[,max])
#max 为可选参数，替换的最大次数
#此为不改变原字符串直接新建。
string="hello world!"
print(string)
stringRep=string.replace(" ","%20")
print("use replace func:",stringRep)
def replaceSpace(string,str1,str2,*max):
    counter=False
    if len(max) > 1:
        error()
    elif len(max) == 1:
        str1Counter=0
        counterMax=max[0]
        if counterMax>=0:
            counter=True
            print("counter max is:",counterMax)
    newString=""
    str1Counter=0
    lenStr=len(string)
    lenStr1=len(str1)
    lenStr2=len(str2)
    print(lenStr,lenStr1,lenStr2)
    print("counter:",counter)
    for i in range(lenStr):
        if not(counter and str1Counter >= counterMax):
            if i<(lenStr -lenStr1) and string[i:(i+lenStr1)] == str1:
                newString=newString+str2
                str1Counter+=1
                i+=(lenStr1-1)
            else:
                newString=newString+string[i]
        else:
            newString=newString+string[i]
    #print("counter is:", str1Counter)
    return newString
string="hello world!"
str1=" "
str2="%20"
print(string)
str3=replaceSpace(string,str1,str2,0)
print("use func we wrote:",str3)
