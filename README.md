# 0x19. C - Stacks, Queues - LIFO, FIFO
## Resources :books:

* [Google](https://intranet.hbtn.io/rltoken/56-bDz7IrFgcH02EkGkB3w)
* [How do I use extern to share variables between source files in C?](https://intranet.hbtn.io/rltoken/9neX6gaN6DoA-ow1INgZqw)

## Learning Objectives :bulb:
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Requirements :white_check_mark:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called monty.h
* Don’t forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

## More Info
### Data structures
Please use the following data structures for this project. Don’t forget to include them in your header file.
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
### Compilation & Output
* Your code will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
* Any output must be printed on stdout
* Any error message must be printed on stderr
  * **[Here is a link to a GitHub repository](https://github.com/sickill/stderred)** that could help you making sure your errors are printed on stderr
### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
#### The monty program

* Usage: `monty file`
  * where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  * where `<file>` is the name of the file
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  * where is the line number where the instruction appears.
  * Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
  * it executed properly every line of the file
  * it finds an error in the file
  * an error occured
* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
* You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

#### Usage
The usage for all the opcodes is only by typing its in the script name is:
* Uasage: `<opcode_name>`.
The only opcode that allows arguments is `push`
* Uasage: `push <int>`.
  * where `<int>` is an integer.
**Example:**
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```
## Tasks :page_with_curl:
### Mandatory
- [x] **[0. push, pall](./0-push_pall.c)** - Implement the `push` and `pall` opcodes. The opcode `push` pushes an element to the stack, and the opcode `pall` prints all the values on the stack, starting from the top of the stack.
- [x] **[1. pint](./1-pint.c)** - Implement the `pint` opcode. The opcode pint prints the value at the top of the stack, followed by a new line.
- [x] **[2. pop](./2-pop.c)** - Implement the `pop` opcode. The opcode pop removes the top element of the stack.
- [x] **[3. swap](./3-swap.c)** - Implement the `swap` opcode. The opcode swap swaps the top two elements of the stack.
- [x] **[4. add](./4-add.c)** - Implement the `add` opcode. The opcode add adds the top two elements of the stack.
- [x] **[5. nop](./5-nop.c)** - Implement the `nop` opcode. The opcode nop doesn’t do anything.
### Advance :muscle:
- [x] **[6. sub](./6-sub.c)** - Implement the `sub` opcode. The opcode sub subtracts the top element of the stack from the second top element of the stack.
- [x] **[7. div](./7-div.c)** - Implement the `div` opcode. The opcode div divides the second top element of the stack by the top element of the stack.
- [x] **[8. mul](./8-mul.c)** - Implement the `mul` opcode.The opcode mul multiplies the second top element of the stack with the top element of the stack.
- [x] **[9. mod](./9-mod.c)** - Implement the `mod` opcode. The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.
- [x] **[10. comments](./main.c)** - Every good language comes with the capability of commenting. When the first non-space character of a line is `#`, treat this line as a comment (don’t do anything).
- [x] **[11. pchar](./11-pchar.c)** - Implement the `pchar` opcode.The opcode pchar prints the char at the top of the stack, followed by a new line.
- [x] **[12. pstr](./12-pstr.c)** - Implement the `pstr` opcode.The opcode pstr prints the string starting at the top of the stack, followed by a new line.
- [x] **[13. rotl](./13-rotl.c)** - Implement the `rotl` opcode. The opcode rotl rotates the stack to the top.
- [x] **[14. rotr](./14-rotr.c)** - Implement the `rotr` opcode. The opcode rotr rotates the stack to the bottom.
- [x] **[15. stack, queue](./15-stack_queue.c)** - Implement the `stack` and `queue` opcodes. The opcode stack sets the format of the data to a stack (LIFO), the default behavior of the program, and the opcode queue sets the format of the data to a queue (FIFO).
- [x] **[16. Holberton](./bf/1000-holberton.bf)** - Write a Brainf\*ck script that prints `Holberton`, followed by a new line.
- [x] **[17. Add two digits](./bf/1001-add.bf)** - Add two digits given by the user.
- [x] **[18. Multiplication](./bf/1002-mul.bf)** - Multiply two digits given by the user.
- [x] **[19. Multiplication level up](./bf/1003-mul.bf)** - Multiply two digits given by the user.


## Author :pencil:
**Santiago Peña Mosquera** - twitter [@Santiag11470161](https://twitter.com/Santiag11470161) - LinkedIn [Santiago Peña Mosquera](https://www.linkedin.com/in/santiago-pe%C3%B1a-mosquera-abaa20196/)
