# 6.1810: Operating System Engineering

[6.1810 home](https://pdos.csail.mit.edu/6.1810/2023/index.html)

[xv6 book](https://pdos.csail.mit.edu/6.828/2023/xv6/book-riscv-rev3.pdf)

- Progress:
  
  ![](https://geps.dev/progress/1)

  - [ ] Lab: Xv6 and Unix utilities
  
  - [ ] Lab: System calls

  - [ ] Lab: Page tables

  - [ ] Lab: Traps

  - [ ] Lab: Copy on-write

  - [ ] Lab: Multithreading

  - [ ] Lab: Network driver

  - [ ] Lab: Lock

  - [ ] Lab: File system

  - [ ] Lab: mmap

- Introduction and guidance

  [如何使用 WSL 在 Windows 上安装 Linux](https://learn.microsoft.com/zh-cn/windows/wsl/install)

  [Git for Computer Scientists](https://eagain.net/articles/git-for-computer-scientists/)

## Lab: Xv6 and Unix utilities
  - Boot xv6 (easy)

    clone实验源码:
    ```
    git clone git://g.csail.mit.edu/xv6-labs-2023
    cd xv6-labs-2023
    ```

    Build and run xv6:
    ```
    make qemu
    ```
  
  - sleep (easy)

    实现`sleep`命令, 暂停指定的ticks
  
  - pingpong (easy)
    
    实现`pingpong`命令, 通过两个管道实现父子进程间的通信
  
  - primes (moderate)/(hard)

    实现`primes`命令, 使用管道和埃氏筛法实现并发筛选质素
    
    ![](https://swtch.com/~rsc/thread/sieve.gif)
  
  ![](https://upload.wikimedia.org/wikipedia/commons/9/94/Animation_Sieve_of_Eratosth.gif)
  
  
  
  - find (moderate)
  
  - xargs (moderate)

## Lab: System calls

## Lab: Page tables

## Lab: Traps

## Lab: Copy on-write

## Lab: Multithreading

## Lab: Network driver

## Lab: Lock

## Lab: File system

## Lab: mmap
