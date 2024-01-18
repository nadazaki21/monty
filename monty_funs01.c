#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *top, *secondtop;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	secondtop = (*stack)->next;
	sum = (top->n) + (secondtop->n);
	secondtop->n = sum;
	free(top);
	secondtop->prev = NULL;
	main_stack.top = secondtop;
}

/**
 * monty_nop - doesn't do anything.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}

/**
 * monty_sub - subtract the top two elements of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	int sub;
	stack_t *top, *secondtop;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		fclose(main_stack.fstream);
		free(main_stack.buffer);
		freedlist(main_stack.top);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	secondtop = (*stack)->next;
	sub = (secondtop->n) - (top->n);
	secondtop->n = sub;
	free(top);
	secondtop->prev = NULL;
	main_stack.top = secondtop;
}

/**
 * monty_div - divides the top two elements of the stack.
 * @stack: pointer to the top pointer of the stack.
 * @line_number: the current line number of the push OP code.
 *
 * Return: void.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *top, *secondtop;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
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
	div = (secondtop->n) / (top->n);
      	secondtop->n = div;
	free(top);
	secondtop->prev = NULL;
	main_stack.top = secondtop;
}
