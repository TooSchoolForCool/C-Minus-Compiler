# A C-MINUS Compiler

This project is a compiler for **C-MINUS** language. Although C-MINUS is a super simple (trivial) language, it is a good start for newbie who tries to learning the principle and basic ideas of compiler implementation. 



## Introduction to C-MINUS

#### Lexical Definition

**Reserved word**

`else` `if` `int` `float` `return` `void` `while` 

*Note: case is SENSITIVE, all letter in reserved word should be in lower case.*

**Operators**

`+` `-` `*` `/` `<` `<=` `>` `>=` `==` `!=` `=` `;` `,` `(` `)` `[` `]` `{` `}` `/*` `*/`

**Identifier & Numbers**

ID = letter letter*

NUM = digit digit* .? digit*

letter = [a-zA-Z]

digit = [0-9]



## How to build

I wrote this project in MacOS, but it could be built in Linux or Windows as well. Only basic C/C++ libraries are used in this project.

For successfully build this project, the `make` tool and `g++` compiler should be installed. After these two tools have been installed, get into this project directory in your terminal (bash). Then use following command to build your compiler target.

```bash
make all
```

After that, you gonna find out a new executable file, called `cc` in your current directory, that is the C-MINUS compiler.

To clean the executable and all objects file, try following command

```shell
make clean
```

For more build detail, please read the Makefile in this project.