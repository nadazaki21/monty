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
 * string_digit - checks if all characters in a string represent digits.
 * @string: string to be checked.
 *
 * Return: -1 if not a digit, 0 if a digit.
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
 * freedlist - frees a doubly linked list from the head.
 * @head: pointer to the head/top of the doubly linked list.
 *
 * Return: void.
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
