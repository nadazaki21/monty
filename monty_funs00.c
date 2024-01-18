#include "monty.h"

/**
 * monty_push - pushes a new stack_t node on top of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int n;
	char **argtokens = main_stack.argtokens;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)stack;
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free(main_stack.buffer);
		fclose(main_stack.fstream);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	if (argtokens[1] && string_digit(argtokens[1]) == 0)
		n = atoi(argtokens[1]);
	else
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free(main_stack.buffer);
		fclose(main_stack.fstream);
		free(new_node);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (main_stack.top == NULL)
	{
		new_node->next = NULL;
		main_stack.top = new_node;
	}
	else
	{
		(main_stack.top)->prev = new_node;
		new_node->next = main_stack.top;
		main_stack.top = new_node;
	}
}

/**
 * monty_pall - prints all elements of a stack starting from top.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor = main_stack.top;

	(void)stack;
	(void)line_number;
	while (cursor != NULL)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}

/**
 * monty_pint - prints the value at the top of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * monty_pop - removes the top element of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *cursor = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		exit(EXIT_FAILURE);
	}
	else
	{
		cursor = cursor->next;
		free(*stack);
		main_stack.top = cursor;
	}
}

/**
 * monty_swap - swaps the top 2 elements of a stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *oldtop, *newtop;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	oldtop = *stack;
	newtop = (*stack)->next;
	oldtop->next = newtop->next;
	oldtop->prev = newtop;
	newtop->next = oldtop;
	newtop->prev = NULL;
	main_stack.top = newtop;
}
