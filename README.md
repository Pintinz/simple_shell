Simple Shell
This is a simple shell program that allows the user to execute basic commands using a limited set of functions and system calls.

Allowed Functions and System Calls
The following functions and system calls are allowed in this program:

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait)


To use the shell, run the hsh executable. The shell will display a prompt and wait for the user to enter a command. The user can enter any command that is allowed by the list of functions and system calls below. Once the user has entered a command, the shell will execute it and display the output.



Here's a brief explanation of each of the allowed functions and system calls for this  simple shell:

access: checks if a process can access a file or directory.
chdir: changes the current working directory of the process.
close: closes a file descriptor.
closedir: closes a directory stream.
execve: executes a program.
exit: terminates the calling process.
_exit: terminates the calling process immediately without running any cleanup functions.
fflush: flushes the output buffer of a stream.
fork: creates a new process by duplicating the calling process.
free: deallocates memory previously allocated by malloc, calloc or realloc.
getcwd: gets the current working directory of the process.
getline: reads an entire line from a stream into a buffer.
getpid: gets the process ID of the calling process.
isatty: tests whether a file descriptor refers to a terminal.
kill: sends a signal to a process or a group of processes.
malloc: allocates a block of memory of a specified size.
open: opens a file or creates it if it doesn't exist.
opendir: opens a directory.
perror: prints an error message to standard error.
read: reads a specified number of bytes from a file descriptor into a buffer.
readdir: reads the next directory entry from a directory stream.
signal: sets a signal handler for a specific signal.
stat (__xstat): gets information about a file.
lstat (__lxstat): gets information about a symbolic link.
fstat (__fxstat): gets information about an open file.
strtok: breaks a string into a sequence of tokens.
wait: waits for a child process to terminate and returns its exit status.
waitpid: waits for a specific child process to terminate and returns its exit status.
wait3: waits for a child process to terminate and returns more information about its termination status.
wait4: waits for a specific child process to terminate and returns more information about its termination status.
write: writes a specified number of bytes from a buffer to a file descriptor.


The compilation command #{gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh}# compiles all the C source files in the current directory and generates an executable file named hsh, with warnings treated as errors (-Wall -Werror), additional warnings enabled (-Wextra), and strict standard compliance (-pedantic -std=gnu89).



