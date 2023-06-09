#ifndef MONTY_H
#define MONTY_H

/* Including Standard Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of stacks (or queues)
 * @n : integer
 * @prev : points to the previous element of the stack (or queue)
 * @next : points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg : values / arguments
 * @file : pointer to the monty file
 * @content : pointer to the line by content in the monty file
 * @lifi : flag change stack <-> queue
 * Description : carries values through out the monty program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its functions
 * @opcode : the opcode
 * @f : function the help to handle the opcode
 *
 * Description : opcode and functions
 * for stack, queues, LIFO, FIFO ALX project
 */

typedef struct instruction_s
{
	char *opcode; /* points to the opcode */
	void (*f)(stack_t **stack, unsigned int line_number); /* function opcode */
} instruction_t;

/* reallocate memory */

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);

/* protype definition of functions */
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void _pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _rotl(stack_t **head, unsigned int counter);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);

#endif /* end of monty head file */
