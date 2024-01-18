#include "monty.h"
/**
 * stack_append - it attaches the last noce of the stack to the first one,
 * so it mkaes the first one the last node instead
 * @new_node: the first node of the stack to be attached to the last
*/
void stack_append(stack_t *new_node) /* changes what point to the first */
{
	stack_t *last_node = main_stack.top;

	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;
	new_node->next = NULL;
}
/**
 * monty_rotl - does the rotl function required in monty
 * @line_number: the number line where error occur
 * @stack: pointer to top of the stack
*/
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;
	(void) line_number;

	if (main_stack.top == NULL ||
	 ((main_stack.top != NULL) && (main_stack.top->next == NULL)))
		return;

	temp = main_stack.top->next;
	stack_append(main_stack.top);
	main_stack.top = temp;
	main_stack.top->prev = NULL;
}

