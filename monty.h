#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct stack_pointers - has all the program's stack pointer data.
 * for reference throughout the program.
 * @top: pointer to the top element of the stack.
 * @front: pointer to the front element of a queue.
 * @rear: pointer to the rear element of a queue.
 * @fstream: pointer to open FILE stream.
 * @buffer: pointer to the current read line string.
 * @argtokens: pointer to the argtokens string array.
 *
 * Description: all pointers needed to handle the stacks, queues,
 * LIFO, and FIFO operations.
 */
typedef struct stack_pointers
{
	stack_t *top;
	stack_t *front;
	stack_t *rear;
	FILE *fstream;
	char *buffer;
	char **argtokens;
} stack_pointers;

/** global variable **/
extern stack_pointers main_stack;

/** function declarations **/
FILE *start_stream(char *filename);
void init_argtokens(char **argtokens);
void execute_op(int linenumber);
void tokenize_line(char *buffer, char **argtokens);
void init_main_stack(FILE *fstream);
void (*get_op_fun(char **))(stack_t **, unsigned int line_number);
int string_digit(char *string);
void freedlist(stack_t *head);

/** monty OP functions **/

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);



#endif
