# minishell
Unix project (Wethinkcode_) - You must program a mini UNIX command interpreter.

# General Instructions
1) This interpreter must display a prompt (a simple "$> " for example) and wait till
you type a command line, validated by pressing enter.
2) The command lines are simple, no pipes, no redirections or any other advanced
functions.
3) You must deal correctly with the PATH and the environment (copy of system char
**environ).
4) You must implement a series of builtins: echo, cd, setenv, unsetenv, env, exit.

# Allowed functions
- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit
