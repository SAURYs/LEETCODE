### gdb调试

先生成可执行程序注意加上`-g`。

`gcc xxx.c  -o app -g`

加上`-g`参数的可执行文件大小更大，只有调试的时候才需要包含调试信息。要调试，启动gdb。

`gdb app`

进入界面之后，`l`列出源文件，默认打开包含`main`函数的文件。查看别的文件：`l xxx.c:20`冒号后面的数据代表想查寻第几行。

`l xxx.c:funtionName`查看某一文件里的某个函数。再`l`继续查看，之后要想查看就直接按`ENTER`就行了。

- 怎么打断点？

  1. 普通断点：`break 22`在22行打断点 或者`b 22`

  2. 满足某一条件断点：`b 15 if i==15`

     查看断点信息`i b`或者`info b`..

  3. 在该文件中给别的文件设断点，`b filename 行号(函数名)`若是函数名，就在函数入口处停。

- `start`只执行一步，单步调试`n`，完后继续执行`c` 。进入函数体内部`s` (step)。具体查看某一变量的值，假如是循环里的`i`，输入`p i`。若果是`s`也是单步，当可以进入函数，`n`不会。

- 查看变量类型`ptype 变量名`

- 追踪变量的值`display + 变量`，查看每次循环变量的值，如何不追踪`undisplay + 编号`编号用`info + 变量`

- `u`跳出单次循环，跳过这次循环。

- `finish`跳出当前函数，前提是取消该函数中的所有断点，`d + 断点编号` 删除断点。

- 将某一变量设置为某一值，即函数运行为该值，例在for循环中的`i` 使用`set var i=10`

- 退出调试`quit`

在gdb之前先设好断点，开始调试`r`或者`start` 。

### C库函数

为什么需要缓冲区？(默认8kb)

C库函数封装了缓冲区，而Unix系统调用是没有缓冲区的。

因为硬盘读写速度相对于内存来说太太太慢了！！减少操作硬盘次数，提高操作文件效率。

- 什么时候缓存区数据写到硬盘上？
  1. 刷新缓冲区`fflush`
  2. 缓冲区满
  3. 正常关闭文件fclose、return、exit

C库函数：

`fopen` `fclose` `fread` `fwrite` `fgets` `fputs` `fscanf` `fprintf` `fseek` `fgetc` `fputc` `ftell` `feof` `flush` ...

###  文件描述符

![image-20210406223205443](C:\Users\volca\AppData\Roaming\Typora\typora-user-images\image-20210406223205443.png)

用户能打开的是3~1023，前三个是被默认打开的。虚拟地址空间0~4G。分为两个部分：

- 虚拟地址空间的0~3G：用户空间

  可执行文件被执行，给程序分配虚拟地址空间0~3G，可执行文件是ELF格式。`file app`

  **ELF包括bss 、data、text。**

  0-4k受保护地址

  程序先从main执行，代码段。**栈向下增长。**

  `new` `malloc` 堆向上增长。

  加载共享库，是哪有空找到哪里，使用相对地址。

  而静态库是放到到代码段中，放的是绝对地址。

  为什么要虚拟地址空间？
  
  - 方便编译器和操作系统安排程序的地址分布，程序可以使用一系列相邻的虚拟地址来访问物理内存种不相邻的大内存缓冲区。
  
  - 方便进程隔离
  
    不同进程使用的虚拟地址彼此隔离，一个进程的代码无法更改正由另一进程使用的物理内存
  
  - 方便OS使用你那可怜的内存

**虚拟地址空间** 

以32位主机来说

![image-20210406223455445](C:\Users\volca\AppData\Roaming\Typora\typora-user-images\image-20210406223455445.png)

`(void*)0`指向的就是受保护的地址。

***了解与位置有关的代码与位置无关的代码***

对于物理内存，实际上用了多少空间就少了多少。

### C库函数与系统函数的关系

![ image-20210407233429709](C:\Users\volca\AppData\Roaming\Typora\typora-user-images\image-20210407233429709.png)

------



#### open函数

Linux系统函数，`man man ` 九个章节，第二章系统函数，`man 章节号 函数名`，查询函数说明。

`int open(const char *pathname, int flags);`

`int open(const char *pathname, int flags, mode_t mode)`

返回值返回一个文件描述符，如果返回值为-1(errno 被设置)

`perror`可读取相应的错误信息。

open函数权限值的设置8进制数`0xxx`,且其真实权限要去与umask值取反按位与。`umask`在终端获得umask值。

打开方式:

	- 必选项 O_RDONLY, OWRONLY, ORDWR.
	- 可选项 O_CREAT ,O_TRUNC,O_EXCL,O_APPEND

创建文件+O_CREAT

open函数判断文件是否存在

`fd = open("hello.c",O_RDWR|O_CREAT|O_EXCL)`

#### lseek

lseek的扩展，将文件向后变大。

向后拓展2000byte。

```c
int ret = lseek(fd,2000,SEEK_END);
//实现文件拓展，需要最后进行一次写操作，不然没法完成
write(fd,"a",1);//随便写东西
```

产生的东西叫空洞，打印不出来的，但确实占用了空间，先给文件大小，给多线程写文件有方便。

#### 文件操作系统函数

- stat 获取文件属性信息

  传入参数，传出参数，下面的结构体类型为传出参数。

  ```c
  int stat(const char *pathname, struct stat *statbuf);
  int fstat(int fd, struct stat *statbuf);
  int lstat(const char *pathname, struct stat *statbuf);
  ```

  该结构体struct中的内容，每个位是什么意思？

  一般来说以f开头的函数，要传入fd,文件描述符。

  `lstat`读出软链接本身的链接的大小 "非穿透函数"，不跟踪

  `stat`独处的是链接到的函数，"穿透函数"，不跟踪

  例如`ls -l` 不穿透`rm`不追踪

  用stat实现`ls -l`时需注意这个。