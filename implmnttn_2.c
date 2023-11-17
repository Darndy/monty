#include "monty.h"
/**
 * pint - monty pint implementation
 * @ stak
 *: top of the stak pointer
 *
 * @line_num: line_num
 * Return: to return nothin
*/
void pint(stack_t **stak, unsigned int line_num)
{
	stack_t *corent = *stak;

	if (corent == NULL)
		_perror(stak, line_num, "can't pint, stakempty");

	printf("%d\n", corent->n);
}
/**
 * swap - implementation of monty swap
 * @stak
 *: pointer to top of the stak
 *
 * @line_num: line_num
 * Return: to return nothin
*/
void swap(stack_t **stak, unsigned int line_num)
{
	stack_t *xekond;

	if (*stak == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't swap, staktoo short");

	xekond = (*stak)->next;
	if (xekond->next)
	{
		xekond->next->prev = (*stak);
		(*stak)->next = xekond->next;
	}
	else
		(*stak)->next = NULL;
	xekond->next = (*stak);
	xekond->prev = NULL;
	(*stak)->prev = xekond;
	(*stak) = xekond;
}
