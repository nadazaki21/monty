#include "monty.h"
/**
 * init_main_stack - initializes the main_stack pointers to null.
 * @fstream: pointer to the file stream.
 *
 * Return: void.
 */

void init_main_stack(FILE *fstream)
{
	main_stack.top = NULL;
	main_stack.front = NULL;
	main_stack.rear = NULL;
	main_stack.fstream = fstream;
	main_stack.buffer = NULL;
	main_stack.argtokens = NULL;
}
/**
 * string_digit - checks if string has digits only or not
 * @string: the string to be checked
 * Return: 0 if all is diigts , -1 otherwise
*/
int string_digit(char *string)
{
	int i = 0;

	if (string[0] == '-')
		i++;
	for (; string[i] != '\0'; i++)
	{
		if (isdigit(string[i]) == 0)
			return (-1);
	}
	return (0);
}
/**
 * freedlist - frees the stack
 * @head: the head of the list
*/
void freedlist(stack_t *head)
{
	stack_t *cursor = head;

	while (cursor != NULL)
	{
		cursor = cursor->next;
		free(head);
		head = cursor;
	}
}
/**
 * free_push - frees the nesseccarry stuff to exit push
*/
void free_push(void)
{
	free(main_stack.buffer);
	fclose(main_stack.fstream);
	freedlist(main_stack.top);
}
/**
 * add_as_queue - adds new nodes to the end of queue
 * @line_number: the line number
*/
void add_as_queue(unsigned int line_number)
{
	stack_t *last_node, *new_node;
	char **argtokens = main_stack.argtokens;
	int n;

	new_node = malloc(sizeof(stack_t));
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
	if (main_stack.top == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		main_stack.top = new_node;
		return;
	}
	last_node = main_stack.top;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new_node->prev = last_node;
	new_node->next = NULL;
	last_node->next = new_node;
}
