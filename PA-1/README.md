## PA-1 File Managing System (Report)

kouylty.



此 PA 要求实现一个用户交互式的文件管理系统，主要功能包括创建与删除文件，读写文件，创建与删除目录，跳转工作目录，显示目录信息等。允许不同用户共享文件、操作目录。交互方式与 Linux 的终端类似。



#### 【工作环境】

Ubuntu 24.04



#### 【工作成果】

1. **成果总览**

   共实现了如下功能：

   ```
   create <filename...>      - Create one or more new files
   delete <filename...>      - Delete one or more files
   read <filename...>        - Read content from one or more files
   write <filename> <text>   - Write text to file
   mkdir <dirname...>        - Create one or more new directories
   rmdir [-r] <dirname>      - Remove directory (-r for recursive deletion)
   cd <path>                 - Change directory (supports relative/absolute paths)
   find [path...]            - List all contents under (current) directory
   ls [path...]              - List (current) directory contents
   pwd                       - Show current working directory
   whoami                    - Show current user name
   clear                     - clear current command line
   help                      - Show this help message
   exit                      - Logout current user
   quit                      - Exit program
   ```



2. **基础功能**

   按需求实现了如下命令，并类比 Linux 构建了详细的报错机制：

   ```create``` 命令：在当前工作目录下创建若干文件，对重名以及非法文件名（例如 ```..``` 和 ```/``` 等）进行报错。

   ```delete``` 命令：删除当前工作目录目录下的若干文件，报错包含：文件不存在，用户没有删除权限。

   ```mkdir``` 命令：与 Linux 类似，在当前工作目录下创建若干新目录，对重名以及非法目录名进行报错。

   ```rmdir``` 命令：与 Linux 类似，正常情况下删除指定的空目录，在 ```-r``` 选项下删除整个指定目录（包括其中的内容）。报错包含：目录不存在，目录非空，用户没有删除权限。

   ```read``` 命令：读取当前目录下指定文件中的内容并展示文件的基本信息，对文件不存在进行报错。

   ```write``` 命令：像指定文件中写入新内容（将 ```"\\n"``` 转译为换行符），对文件不存在进行报错。

   ```pwd``` 命令：与 Linux 一致，显示当前工作目录的绝对路径。

   ```whoami``` 命令：与 Linux 一致，显示当前用户的用户名。

   ```help``` 命令：打印用户交互指南。

   ```ls``` 命令：与 Linux 类似，显示当前工作目录下的内容。

   ```cd``` 命令：做到了与 Linux 一致，既实现了绝对路径跳转（例如 ```cd /home/kouylty```），也实现了间接路径跳转（例如 ```cd kouylty``` 以及 ```cd ./kouylty```）。实现了跳转到根目录（```cd``` 或 ```cd /```）和原地跳转（```cd .```）,还实现了跳转到上级目录和上级目录与新路径的结合（例如 ```cd ..``` 以及 ```cd ../kouylty```）。对路径不存在进行报错。

   基础功能展示如下：

   ```shell
   root@FileSimulator:/$ mkdir university
   root@FileSimulator:/$ cd ./university
   root@FileSimulator:/university$ mkdir china usa england japan
   root@FileSimulator:/university$ ls
   japan
   england
   usa
   china
   root@FileSimulator:/university$ rmdir japan
   root@FileSimulator:/university$ ls
   england
   usa
   china
   root@FileSimulator:/university$ cd china
   root@FileSimulator:/university/china$ create top5.txt
   root@FileSimulator:/university/china$ write top5.txt pku\\nthu\\nnju\\n
   root@FileSimulator:/university/china$ write top5.txt sjtu\\nzju\\n
   root@FileSimulator:/university/china$ read top5.txt
   [File: top5.txt] Size: 21 bytes
   pku
   thu
   nju
   sjtu
   zju
   
   root@FileSimulator:/university/china$ pwd
   /university/china
   root@FileSimulator:/university/china$ 
   ```

   对报错信息的处理如下（上述测试指令已完成）：

   ```shell
   root@FileSimulator:/university/china$ cd ./top5.txt
   cd: ./top5.txt: Not a directory.
   root@FileSimulator:/university/china$ cd ../usb
   cd: ../usb: No such file or directory
   root@FileSimulator:/university/china$ cd ..
   root@FileSimulator:/university$ mkdir
   mkdir: missing operand
   Try 'help' for more information.
   root@FileSimulator:/university$ mkdir .
   mkdir: cannot create directory '.': Illegal name
   root@FileSimulator:/university$ rmdir china
   rmdir: failed to remove 'china': Directory not empty
   root@FileSimulator:/university$ read top5.txt
   read: cannot open 'top5.txt': No such file or directory
   root@FileSimulator:/university$ mkdir china
   mkdir: cannot create directory 'china': File exists
   root@FileSimulator:/university$ create usa
   create: cannot create file 'usa': File exists
   root@FileSimulator:/university$ delete england
   delete: england: Not a file
   root@FileSimulator:/university$ 
   ```
   
   对不同用户实现文件共享的功能如下（已切换用户）：
   
   ```shell
   kouylty@FileSimulator:/university$ ls
   england
   usa
   china
   kouylty@FileSimulator:/university$ rmdir england
   rmdir: cannot remove 'england': Inaccessible to kouylty
   kouylty@FileSimulator:/university$ cd /university/china
   kouylty@FileSimulator:/university/china$ read top5.txt
   [File: top5.txt] Size: 21 bytes
   pku
   thu
   nju
   sjtu
   zju
   
   kouylty@FileSimulator:/university/china$ delete top5.txt
   delete: cannot delete 'top5.txt': Inaccessible to kouylty
   kouylty@FileSimulator:/university/china$ cd 
   kouylty@FileSimulator:/$ mkdir middleschool
   kouylty@FileSimulator:/$ ls
   middleschool
   university
   kouylty@FileSimulator:/$ whoami
   User: kouylty
   kouylty@FileSimulator:/$
   ```



3. **特殊功能**

   实现了 ```clear``` 命令，清空当前终端窗口的内容，代码如下：

   ```cpp
   fputs("\x1b[2J\x1b[H", stdout);
   fflush(stdout);
   ```

   此功能在 Linux 系统（ VT100 终端）下运行良好，但不保证在其他系统中运行的兼容性。



4. **附加的功能（额外的工作量）**

   扩充了 ```ls``` 命令的功能，做到了与 Linux 类似。实现了显示多个目录下的内容并加以区分，实现了绝对路径和间接路径的查找，并且实现了参数对目录和文件的同时兼容。

   新增了 ```find``` 命令，并做到与 Linux 一致，递归展开并显示指定目录下所有内容，同样实现了绝对路径和间接路径的查找，实现了参数对目录和文件的同时兼容。

   当然，这些附加功能对基础的语法和功能完全兼容，可在扩充版本上放心使用原先的基础命令。

   附加功能展示如下（上述测试指令已完成）：

   ```shell
   kouylty@FileSimulator:/$ find
   .
   ./middleschool
   ./university
   ./university/england
   ./university/usa
   ./university/china
   ./university/china/top5.txt
   kouylty@FileSimulator:/$ ls . university ../university/china/top5.txt
   .:
   middleschool
   university
   
   university:
   england
   usa
   china
   
   top5.txt
   kouylty@FileSimulator:/$
   ```

   

#### 【工作总结】

此 PA 大约花费三天时间，其中写代码加调试两天，测试和写报告一天。在这期间偶然读到一盏佳句，记录于此：

$\mathrm{The\ terbulence\ was\ purposeless,\ but\ in\ huge\ quantities\ of\ purposeless\ terbulence,\ purpose\ took\ shape.}$

最后的最后，请允许我提前祝绫十周年快乐。

用这双手　拨出残缺染了锈迹的弦音

都隐没于　淋漓的雨幕无声无息

曲终之时　你是否便会回应我的心音

将颤抖的双手牵起　迎来每个人的结局