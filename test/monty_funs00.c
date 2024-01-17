#include "monty.h"

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
