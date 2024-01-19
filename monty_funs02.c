#include "monty.h"

/**
 * monty_mod - mods the top two elements of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *top, *secondtop;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	secondtop = (*stack)->next;
	if (top->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	mod = (secondtop->n) % (top->n);
	secondtop->n = mod;
	free(top);
	secondtop->prev = NULL;
	main_stack.top = secondtop;
}

/**
 * monty_pchar - prints the char at the top of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int chr;

	if ((*stack) == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	chr = (*stack)->n;
	if (chr < 0 || chr > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", chr);
}

/**
 * monty_pstr - prints the string starting at the top of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	int chr;
	stack_t *cursor = *stack;

	(void)line_number;
	if ((*stack) == NULL)
	{
		printf("\n");
		return;
	}
	while (cursor != NULL)
	{
		chr = cursor->n;
		if (chr < 0 || chr > 127 || chr == 0)
			break;
		printf("%c", chr);
		cursor = cursor->next;
	}
	printf("\n");
}
