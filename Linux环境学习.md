### `which`命令

查看使用的命令路径在哪一个，只能查外部命令，内建命令查不了

`which cp`

### 查看和修改文件权限`chmod`

- 查看当前登陆用户`whoami`

- 文字设定法 `chmod [who][+|-|=][mode]`

  who:

  ​	文件所有者 u

  ​	文件所属组 g

  ​	其他人 o

  ​	所有人 a(默认)

  `=`就是覆盖

- 数字设定法（常用简单）

  `r`=4,`w`=2,`x`=1,`-`=0

  怎么使用数字设定法修改权限,假如现在是减少其组的执行条件？

  `chmod -001 filename`

  

  

### 改变文件所有者和所有组`chown` `chgrp`

假设现在有三个组G1，G2，G3，有一文件file1，G1中有一用户user1,他有一文件为file1,该文件属于user1，但该文件可以是属于G2这个组的。

`sudo chown newOwner filename` 修改所有者

`sudo chown newOwner:newGroup filename` 修改所有者+所有组

`sudo chgrp newGroup filename` 修改组

### 文件的查找和检索

查找某个目录下是否有该文件

- 按名字区查找

  `find dir -name +"filename"`

  按照通配符去查找

  `*`所有字符(通配多个)

  `?`某个字符

- 按文件大小进行查找

  `find Dir -size +10k` 大于10k 小于10k用小于 （小写的k)

  `find Dir -size +10M`找到在某个文件夹下的大于10M的（大写M）

  `find Dir -size +10M -size -100M` 找到某个范围内的文件

- 根据文件类型

  |    类型    |        符号        |
  | :--------: | :----------------: |
  |  普通文件  | `-`|`-f(搜索使用)` |
  |    目录    |        `-d`        |
  |  链接符号  |        `-l`        |
  |   块设备   |        `-b`        |
  |  字符设备  |        `-c`        |
  | socket文件 |        `-s`        |
  |  管道文件  |        `-p`        |

  

`find Dir -type  f/d/l/b...`

- 按照文件内容进行查找

  `grep -r "content" Dir` 文件放后面

### 安装软件

- 在线安装`apt-get`

  `sudo apt-get install software` 安装

  `sudo apt-get remove software`卸载

  `sudo apt-get update` 更新软件**列表**（<u>从官方服务器更新</u>）

  `sudo apt-get clean`清理下在在`/var/cache/apt/archives`目录下的`.deb` 文件

- `.deb`安装包

  `sudo dpkg -i pakage` 安装

  `sudo dpkg -r  software-name` 卸载

- 源码安装

  1. 解压缩源代码包
  2. 进入到安装目录 `cd di`
  3. 检测文件是否缺失，创建Makefile，检测编译环境：`./configure`
  4. 编译源码，生成库和可执行程序:make
  5. 把库和可执行程序，安装到系统目录下：`sudo make install`
  6. 删除和卸载软件:`sudo make distclean`
  7. 上述安装步骤不是绝对的，具体可见附带的README文件


###  磁盘管理

- 挂载`mount` 

  1. 系统默认挂载目录`/media`

  2. 手动挂目录`/mnt`

  3. 挂载方式

     `mount deviceName /mnt` 用`sudo fdisk -l`找到名称

     `cp`进行文件复制

     `umount /mnt`解除挂载

  4. 如果不挂载在/mnt目录中会怎么样？

     会覆盖该目录下文件（暂时覆盖）

### 压缩包管理

- 屌丝版

  1. `gzip`  .gz格式的压缩包 不会打包压缩，不会保留原文件`gunzip`解压缩，不能压缩目录
  2. `bzip2` 语法和`gzip`一样，不能压缩目录， `-k`保留原文件

- 高富帅版

  1. `tar`

     参数c|x|v|f..

     c 创建

     x 释放

     v显示提示信息

     f 指定要所文件名字

     z 使用`gzip`方式要所文件 .gz

     j 使用`bzip2 `的方式压缩文件 .bz2

     **压缩**  `tar zcvf  xxxx.tar.gz **``tar jcvf xxx.tar.bz2 **`

     **解压缩** `tar jxvf 压缩包名字（解压到当前目录）` .tar.bz2

     `tar jxvf xxx.tar.bz -C Dir` 指定目录 `-C`

- rar  必须手动安装

### 进程管理`ps`

- `who`当前用户

- `ps -a`查看所有用户`ps -au`列出有终端的（与用户交互）

-  `ps -aux`查看没有终端的应用程序(一般使用)

- 对`ps -aux`的输出进行过滤？使用管道！！！查找(`find` or `grep`) `grep`查找文件里的内容

  **注意：最后一行结果不是查询的结果，而是`grep`命令本身！！！**

- 杀死进程`kill -9 pid` 

  `kill -l`获取信号，用`SIGKILL`

- `env`查看当前环境变量

- `top` 相当于任务管理器

### 网络管理

- `ifconfig` 
- `nslookup` 查找对应域名对应的IP

### 用户管理



### ftp服务器搭建vsftpd



### nfs服务器搭建

###  VIM

三种工作模式

- 命令模式
- 编辑模式
- 末行模式

### gcc

`-I` 头文件路径

`-D`编译的时候指定宏

`-O[0|1|2|3]`制定优化方案

`-Wall` 警告信息

`-g` 添加调试信息(供gdb使用)

`-c` 只编译子程序

`-o` 指定生成文件名字

### 静态库

源代码就是核心技术，将源代码生成库和头文件。

- 命名规则

  lib+库的名字+`.a` eg `libmytest.a`

- 制作步骤

  生成对应的`.o`文件。 如何由`.c` 生成`.o`  gcc中的`-c`参数

  将生成的`.o`文件打包：`ar rcs +xxx.a+生成的所有的.o` 

- 发布和使用静态库

  发布静态库

  头文件

`gcc main.c lib/libmytest.a -o sum -Iinclude`

`gcc main.c -Iinclude -L lib -l MyCaclc -o sum`对第二条命令的解析 `-L`对应库文件夹`-l`库文件名(掐头去尾！！！去掉头部lib尾部.a) <u>没有顺序之分</u>