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

`-I` 指定头文件路径

`-D`编译的时候指定宏，控制log输出

`-O[1|2|3]`制定优化方案

`-Wall` 警告信息

`-g` 添加调试信息(供gdb使用)

`-c` 只编译子程序

`-o` 指定生成文件名字

**gcc 工作流程**

1. 预处理 `gcc -E`
2. 编译 `gcc -S`
3. 汇编 `gcc -c`
4. 链接 无参数

### 静态库(使用C++ 时用g++而非gcc)

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

`gcc main.c -Iinclude -L libpath -l MyCaclc -o sum`对第二条命令的解析 `-L`对应库文件夹`-l`库文件名(掐头去尾！！！去掉头部lib尾部.a) <u>没有顺序之分</u>

### 静态库的优缺点

使用静态库时，打包的最小单位就是`.o` ，用到哪个打包哪个。

静态库的优点：

- 发布程序的时候，不需要提供对应的库
- 库的加载速度快、

静态库的缺点：

- 会把库打包到程序中，导致软件的体积大
- 库发生了改变，应用程序需要重新编译

### 共享库

对应于windows中的`dll`

- 命名规则

  1. 生成与位置无关的`.o` 

     ```bash
     gcc -fPIC -c *.c -Iinclude#生成与位置无关的.o
     ```

     ![Screenshot from 2021-04-04 22-45-06](/home/pc330/Pictures/Screenshot from 2021-04-04 22-45-06.png)

  2. 将`.o` 打包为共享库(动态库)

     ```bash
     gcc -shared -o libxxx.so *.o -Iinclude
     ```

     如何使用动态库

     ```bash
     gcc main.c lib/libxxx.so -o app(.out) -Iinclude #方式1
     gcc main.c -Iinclude -L./lib -l(libxxx.so只保留xxx部分) -o app
     ```

     `ldd+a.out`查看可执行文件在执行时所依赖的所有共享库。

     动态链接器`ld-x86_64.so.2`会自动调用，根据某个环境变量区查找

     ```bash
     echo $PATH
     ```

     `/lib`Linux系统在执行过程中用到的库

     

     - 可以将上述`libxxx.so`拷贝进入/lib后，程序即可正常运行『但上述方法不可在实际中使用！！！』

     - 经典方法(需掌握)

       1. 找到动态链接器的配置文件`/etc/ld.so.conf`
       2. 动态库的路径写到配置文件中
       3. 更新 `sudo ldconfig -v`

     - 配置`LD_LIBRARY_PATH` 环境变量，赋值。这种方法使得程序先在该环境变量中搜索库。(临时)。当把当前bash关掉后，失效。『开发过程中测试使用』

     - 实现永久设置：实现当前用户的bash设置，编辑`.bashrc` 终端启动的时候会读取`.bahsrc`

       添加`export LD_LIBRARY_PATH=xxxx/lib(绝对路径)` `source .bashrc`生效或者重启终端。

       ```bash
       export LD_LIBRARY_PATH=./lib
       ```

        

       ```bash
       sudo cp ./lib/libxxx.so /lib
       ```

  

  *程序启动之后才进行加载动态库(使用相对地址)*

  ### 动态库的优缺点

  优点：

  - 执行程序小
  - 动态库更新不需要重新编译程序(前提是接口没变)

  缺点：

  - 发布程序的时候，需要将动态库提供给用户
  - 动态库没有被打包到应用程序中，加载速度相对慢

  

  

  

