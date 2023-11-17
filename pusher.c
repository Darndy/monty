#include "monty.h"
/**
 * call_push - helper function to call push
 * @stack: pointer to the first node
 * @L: line number
 * @num: number to push
 * Return: nothing
 */
void call_push(stack_t **stack, unsigned int L, char *num)
{
	stack_t *reccent = *stack;
	int number;

	if (isnum(num) == 0)
		_perror(stack, L, "usage: push integer");

	number = atoi(num);
	if (strcmp(info.mode, "stack") == 0)
	{
		push(stack, L);
		(*stack)->n = number;
	}
	else
	{
		push(stack, L);
		if (reccent)
		{
			while (reccent->next)
				reccent = reccent->next;
			reccent->n = number;
		}
		else
			(*stack)->n = number;
	}
}
/**
 * push - implements monty push
 * @stack: pointer to stack top
 * pshd_node: pushed node
 * @line_number: line_number
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *pshd_node;

	(void)line_number;
	pshd_node = malloc(sizeof(stack_t));
	check_malloc(pshd_node);
	pshd_node->n = 0;
	pshd_node->next = NULL;
	pshd_node->prev = NULL;
	if (*stack != NULL)
	{
		pshd_node->next = *stack;
		(*stack)->prev = pshd_node;
	}
	*stack = pshd_node;
}

/**
 * push_q - push in queue
 * @stack: pointer to the front
 * @L: line number
 * Return: nothing
 */
void push_q(stack_t **stack, unsigned int L)
{
	stack_t *pshd_node, *reccent = (*stack);

	(void)L;
	pshd_node = malloc(sizeof(stack_t));
	check_malloc(pshd_node);
	pshd_node->n = 0;
	pshd_node->next = NULL;
	pshd_node->prev = NULL;
	if ((*stack) == NULL)
		*stack = pshd_node;
	else
	{
		while (reccent->next)
			reccent = reccent->next;
		reccent->next = pshd_node;
		pshd_node->prev = reccent;
	}
}
