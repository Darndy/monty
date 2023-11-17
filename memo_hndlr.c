#include "monty.h"
/**
 * free_2d - frees a 2d array
 * Return: nothing
*/
void free_2d(void)
{
    int i = 0;

    if (info.splitted_line == NULL)
        return;

    while (info.splitted_line[i] != NULL)
    {
        free(info.splitted_line[i]);
        info.splitted_line[i] = NULL;
        i++;
    }

    free(info.splitted_line);
    info.splitted_line = NULL;
}

/**
 * free_stack - frees doubly linked list
 * @head: ptr to head
 * Return: nothing
*/
void free_stack(stack_t **head)
{
    stack_t *current = *head;

    if (*head == NULL)
        return;

    do
    {
        current = current->next;
        free(current->prev);
        current->prev = NULL;
    } while (current->next != NULL);

    free(current);
    current = NULL;
}

/**
 * check_malloc - prints to stderr and exit by EXIT_FAILURE if malloc failed
 * @stack: space that doesn't allocated
 * Return: nothing
*/
void check_malloc(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_2d();
		if (info.monty_file)
			fclose(info.monty_file);
		exit(EXIT_FAILURE);
	}
}
