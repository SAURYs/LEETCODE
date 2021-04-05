a="hello world"
b="hello world"
c=[1,2,3]
d=[1,2,3]
print(id(a)==id(b))#True
print(id(c)==id(d))#False
print("id of a is:",id(a))
print("id of c is:",id(c))
c.append("aaa")
print(c)
print("id of c is:",id(c[1]))
print("id of c is:",id(c[2]))
print("id of c is:",id(c[3]))
#为了节省内存C/C++中把常量字符串放到一个单独的内存区域，当几个
#指针赋值给相同的常量字符串时，它们实际会指向相同的内存地址。
#但是对数组来讲则不一样，数组是先分配一段内存，然后对该内存的位置
#进行赋值。
#在python中 list的实现方式是类（一切皆对象），此时append可以添加任意元素，且无须为同一类型
