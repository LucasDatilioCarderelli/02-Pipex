<div align="center">
	<a href="https://www.42sp.org.br/">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=200>
	</a>
<h1> Pipex </h1>
</div>

<h2 align="center">
	Project develop for <a href="https://github.com/LucasDatilioCarderelli/42Cursus"> 42Cursus </a>
</h2>

<p align="center">
  	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
	<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    	<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
	</a>
	<br>
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/02-Pipex?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/02-Pipex?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/02-Pipex?color=blue" />
</p>

<div align="center">
	<a href="https://github.com/LucasDatilioCarderelli/02-Pipex">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/pipex.png">
	</a>
</div>

---

## Summary

> This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

### Keywords
* ``Unix logic``

### Skills
* ``Imperative programming``
* ``Unix``

## How to run

```bash
$> make all && make bonus
```
```bash
$> ./pipex infile "grep a" "tr a b" outfile
```
#### it should be the same as:
```bash
$> < infile grep a | tr a b > outfile
```

## How it Works

### Fork
This function basically create a new process when it is called. Everything before the ``fork()`` is executed once, then it create new process, resulting 2 process, where the child process is always 0, here is an exemple;

```c
#include <unistd.h>

int	main(void){
	int id = fork();
	if (id == 0)
		printf("Hello, child process id: %d\n", id);
	else
		printf("Hello, parent process id: %d\n", id);
	return 0;
}
```
#### Output
```bash
Hello, child process id: 0
Hello, parent process id: 42
```

### Process ID's
There are another functions called ``getpid()`` that return the process id of the calling process, and the ``getppid()`` that thet return the parent process the current proccess. Every process has its parent process, in the case of child process, 0, its parent is 42, and the parent of the parent process it might be 41.

### Pipe
The ``pipe()`` will create two file descriptor, so we declare as ``int fd[2]``. One of them, ``fd[0]``, we will use to ``read()`` from a file, and the other, ``fd[1]``, we will ``write()``. Here is an exemple how its works:

```c
int main(void){
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0){
		close(fd[0]);
		int x = 42;
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
		printf("writed %d in child process\n", x);
	} else {
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("readed %d in parent process\n", y);
	}
}
```

#### Output
```bash
writed 42 in child process
readed 42 in parent process
```

As you see, we need to close four files descriptor, it's because the fds are inheriteded when we do fork, because that they are used to redirect the mensage between process from ``fd[1]`` to ``fd[0]``.

### Dup2
This function is a trick that allow us to print instead of the standart output (fd = 1), but to another file descriptor, printing in a file. It because when we use ``dup2()``, we are duplicating our fd to another fd, that is usually to the ``STDOUT`` or ``STDIN``, allowing to read from a file.

```c
int main(void){
	printf("before dup\n");
	int fd = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		return (1);
	int fd2 = dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("after dup\n");
	close(fd2);
	return (0);
}
```

#### Output - Terminal
```bash
before dup
```

#### Output - Outfile
```txt
1	after dup
2
```

As you see, before dup we print in the terminal, and after dup we print in the file, as we have 2 fds we need to close both.

### Exec

This family of functions are used to execute commands in the shell, once it is called without an error, the process is finished, if not, we return the error 127, command not found.

---

<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    <img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    <img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
</a>