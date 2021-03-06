# Simple Shell Project 

![shel_img](https://user-images.githubusercontent.com/22318580/129488019-133b1a6f-b149-4f71-8aaf-4f12a9a674c9.jpeg)

## Definition
Simple Shell A shell is a command line interface (CLI) program that takes commands from the keyboard and gives them to the operating system to perform.In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer’s role and particular operation. It is named a shell because it is the outermost layer around the operating system kernel.

## Requirements
* :white_check_mark: Allowed editors: vi, vim, emacs
* :white_check_mark:All your files will be compiled on Ubuntu 20.04 LTS using gcc, * :white_check_mark:using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* :white_check_mark:All your files should end with a new line
* :white_check_mark:A README.md file, at the root of the folder of the project is mandatory
* :white_check_mark:Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* :white_check_mark:Your shell should not have any memory leaks
* :white_check_mark:No more than 5 functions per file
* :white_check_mark:All your header files should be include guarded
* :white_check_mark:Use system calls only when you need to (why?)

## List of allowed functions and system calls
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `getsexit` (man 3 exit)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)


# shellby - Simple Shell :shell:

-access (man 2 access)
-chdir (man 2 chdir)
-close (man 2 close)
-closedir (man 3 closedir)
-execve (man 2 execve)
-exit (man 3 exit)
-_exit (man 2 _exit)
-fflush (man 3 fflush)
-fork (man 2 fork)
-free (man 3 free)
-getcwd (man 3 getcwd)
-getline (man 3 getline)
-getpid (man 2 getpid)
-isatty (man 3 isatty)
-kill (man 2 kill)
-malloc (man 3 malloc)
-open (man 2 open)
-opendir (man 3 opendir)
-perror (man 3 perror)
-read (man 2 read)
-readdir (man 3 readdir)
-signal (man 2 signal)
-stat (__xstat) (man 2 stat)
-lstat (__lxstat) (man 2 lstat)
-fstat (__fxstat) (man 2 fstat)
-strtok (man 3 strtok)
-wait (man 2 wait)
-waitpid (man 2 waitpid)
-wait3 (man 2 wait3)
-wait4 (man 2 wait4)
-write (man 2 write)

## Description :speech_balloon:

**Shellby** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

### Invocation :running:

Usage: **shellby** [filename]

To invoke **shellby**, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o shellby
./shellby
```

**Shellby** can be invoked both interactively and non-interactively. If **shellby** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'hello'" | ./shellby
'hello'
$
```

If **shellby** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **shellby** displays the prompt `$ ` when it is ready to read a command.

Example:
```
$./shellby
$
```

Alternatively, if command line arguments are supplied upon invocation, **shellby** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **Shellby** runs each of the commands contained in the file in order before exiting.

Example:
```
$ cat test
echo 'hello'
$ ./shellby test
'hello'
$
```

### Environment :deciduous_tree:

Upon invocation, **shellby** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./shellby
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./shellby
/home/vagrant/alx/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$ echo "echo $OLDPWD" | ./shellby
/home/vagrant/alx/printf
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```
$ echo "echo $PATH" | ./shellby
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
```

### Command Execution :hocho:

After receiving a command, **shellby** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **Shellby** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`\`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`\`), dot (`.`), nor builtin, **shellby** searches each element of the **PATH** environmental variable for a directory containing an executable file by that name.
3. If the first character of the command is a slash (`\`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

### Exit Status :wave:

**Shellby** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is `127`; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

### Signals :exclamation:

While running in interactive mode, **shellby** ignores the keyboard input `Ctrl+c`. Alternatively, an input of end-of-file (`Ctrl+d`) will exit the program.

User hits `Ctrl+d` in the third line.
```
$ ./shellby
$ ^C
$ ^C
$
```

### Variable Replacement :heavy_dollar_sign:

**Shellby** interprets the `$` character for variable replacement.

#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.

Example:
```
$ echo "echo $PWD" | ./shellby
/home/vagrant/alx/simple_shell
```

#### $?
`?` is substitued with the return value of the last program executed.

Example:
```
$ echo "echo $?" | ./shellby
0
```

#### $$
The second `$` is substitued with the current process ID.

Example:
```
$ echo "echo $$" | ./shellby
6494
```

### Comments :hash:

**Shellby** ignores all words and characters preceeded by a `#` character on a line.

Example:
```
$ echo "echo 'hello' #this will be ignored!" | ./shellby
'hello'
```

### Operators :guitar:

**Shellby** specially interprets the following operator characters:

#### ; - Command separator
Commands separated by a `;` are executed sequentially.

Example:
```
$ echo "echo 'hello' ; echo 'world'" | ./shellby
'hello'
'world'
```

#### && - AND logical operator
`command1 && command2`: `command2` is executed if, and only if, `command1` returns an exit status of zero.

Example:
```
$ echo "error! && echo 'hello'" | ./shellby
./shellby: 1: error!: not found
$ echo "echo 'all good' && echo 'hello'" | ./shellby
'all good'
'hello'
```

#### || - OR logical operator
`command1 || command2`: `command2` is executed if, and only if, `command1` returns a non-zero exit status.

Example:
```
$ echo "error! || echo 'but still runs'" | ./shellby
./shellby: 1: error!: not found
'but still runs'
```

The operators `&&` and `||` have equal precedence, followed by `;`.

### Shellby Builtin Commands :nut_and_bolt:

#### cd
  * Usage: `cd [DIRECTORY]`
  * Changes the current directory of the process to `DIRECTORY`.
  * If no argument is given, the command is interpreted as `cd $HOME`.
  * If the argument `-` is given, the command is interpreted as `cd $OLDPWD` and the pathname of the new working directory is printed to standad output.
  * If the argument, `--` is given, the command is interpreted as `cd $OLDPWD` but the pathname of the new working directory is not printed.
  * The environment variables `PWD` and `OLDPWD` are updated after a change of directory.

Example:
```
$ ./shellby
$ pwd
/home/vagrant/alx/simple_shell
$ cd ../
$ pwd
/home/vagrant/alx
$ cd -
$ pwd
/home/vagrant/alx/simple_shell
```

#### alias
  * Usage: `alias [NAME[='VALUE'] ...]`
  * Handles aliases.
  * `alias`: Prints a list of all aliases, one per line, in the form `NAME='VALUE'`.
  * `alias NAME [NAME2 ...]`: Prints the aliases `NAME`, `NAME2`, etc. one per line, in the form `NAME='VALUE'`.
  * `alias NAME='VALUE' [...]`: Defines an alias for each `NAME` whose `VALUE` is given. If `name` is already an alias, its value is replaced with `VALUE`.

Example:
```
$ ./shellby
$ alias show=ls
$ show
AUTHORS            builtins_help_2.c  errors.c         linkedlist.c        shell.h       test
README.md          env_builtins.c     getline.c        locate.c            shellby
alias_builtins.c   environ.c          helper.c         main.c              split.c
builtin.c          err_msgs1.c        helpers_2.c      man_1_simple_shell  str_funcs1.c
builtins_help_1.c  err_msgs2.c        input_helpers.c  proc_file_comm.c    str_funcs2.c
```

#### exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  * If no argument is given, the command is interpreted as `exit 0`.

Example:
```
$ ./shellby
$ exit
```

#### env
  * Usage: `env`
  * Prints the current environment.

Example:
```
$ ./shellby
$ env
NVM_DIR=/home/vagrant/.nvm
...
```

#### setenv
  * Usage: `setenv [VARIABLE] [VALUE]`
  * Initializes a new environment variable, or modifies an existing one.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./shellby
$ setenv NAME Poppy
$ echo $NAME
Poppy
```

#### unsetenv
  * Usage: `unsetenv [VARIABLE]`
  * Removes an environmental variable.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./shellby
$ setenv NAME Poppy
$ unsetenv NAME
$ echo $NAME

$
```

## Authors :black_nib:

* Abubakar Bangura 
* Victor Owiti
## License :lock:
## Acknowledgements :pray:

**Shellby** emulates basic functionality of the **sh** shell. This README borrows form the Linux man pages [sh(1)](https://linux.die.net/man/1/sh) and [dash(1)](https://linux.die.net/man/1/dash).

