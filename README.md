# Operating-System-LAB
A repo to keep track of my OS work

Demonstration of system calls
System Calls: 

a) fork() : [here](https://github.com/AayushTyagi1/Operating-System-LAB/blob/master/fork.c) Used to create new processes. The new process consists of a copy of the address space of the original process. System call returns zero in child process while it returns child process id in parent process. 

b) getpid() : [here](https://github.com/AayushTyagi1/Operating-System-LAB/blob/master/pid.c) Each process is identified by its id value. This function is used to get the id value of a particular process. 

c) getppid() : [here](https://github.com/AayushTyagi1/Operating-System-LAB/blob/master/ppid.c) Used to get particular process parent's id value. 

d) wait() : [here](https://github.com/AayushTyagi1/Operating-System-LAB/blob/master/wait.c) The parent waits for the child process to complete using the wait system call. The wait system call returns the process identifier of a terminated child, so that the parent can tell which of its possibly many children has terminated. 

e) exit() : [here](https://github.com/AayushTyagi1/Operating-System-LAB/blob/master/wait.c) A process terminates when it finishes executing its final statement and asks the operating system to delete it by using the exit system call. At that point, the process may return data (output) to its parent process (via the wait system call).
