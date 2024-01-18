#include "monty.h"
/**
 * point_last_to_first - makes the last elemt in the stack the first
 * @top: the pointer to the top of the stack
*/
void point_last_to_first(stack_t **top)
{
	stack_t *last_node = *top;

	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *top;
	(*top)->prev = last_node;
	*top = last_node;
}
/**
 * monty_rotr - does the required required rotr function in monty
 * @line_number: the number line where error occur
 * @stack: pointer to top of the stack
*/
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) stack;
	(void) line_number;

	if (main_stack.top == NULL ||
	 ((main_stack.top != NULL) && (main_stack.top->next == NULL)))
		return;
	
	/* if they are 2 node only in the stack 
	if ((main_stack.top != NULL) &&
	 (main_stack.top->next != NULL) && (main_stack.top->next->next == NULL))
	{
		temp = main_stack.top;

		main_stack.top = main_stack.top->next;

		main_stack.top->next = temp;
		main_stack.top->prev = NULL;

		temp->prev = main_stack.top;
		temp->next = NULL;
		return;
	}
	*/
	point_last_to_first(&main_stack.top);
}
