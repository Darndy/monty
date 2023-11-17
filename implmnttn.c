#include "monty.h"
/**
 * pop - implementation of monty pop
 * @stak
 *: pointer to top of the stak
 *
 * @line_num: line_num
 * Return: to return nothin
*/
void pop(stack_t **stak, unsigned int line_num)
{
	if (*stak == NULL)
		_perror(stak, line_num, "can't pop an empty stak");

	if ((*stak)->next == NULL)
	{
		free(*stak);
		*stak = NULL;
		return;
	}
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
}
/**
 * nop - implementation of monty nop
 * @stak
 *: pointer to top of the stak
 *
 * @line_num: line_num
 * Return: to return nothin
*/
void nop(stack_t **stak, unsigned int line_num)
{
	(void)line_num;
	(void) stak;
}
/**
 * pall - monty pall implementation
 * @stak
 *: top of the stak pointer
 *
 * @line_num: line_num
 * Return: to return nothin
*/
void pall(stack_t **stak, unsigned int line_num)
{
	stack_t *corent = *stak
;

	(void)line_num;
	while (corent != NULL)
	{
		printf("%d\n", corent->n);
		corent = corent->next;
	}
	fflush(NULL);
}
