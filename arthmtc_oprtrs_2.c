#include "monty.h"
/**
 * mod - monty mod implementation
 * @stak: pointer to stack top
 * @line_num: line number
 * Return: nothing
*/
void mod(stack_t **stak, unsigned int line_num)
{
	int mod;

	if ((*stak) == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't mod, stak too short");

	if ((*stak)->n == 0)
		_perror(stak, line_num, "division by zero");

	mod = (*stak)->next->n % (*stak)->n;
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
	(*stak)->n = mod;
}
/**
 * sub - monty sub implementation
 * @stak: top of stack pointer
 * @line_num: line's number
 * Return: 0
*/
void sub(stack_t **stak, unsigned int line_num)
{
	int sub;

	if ((*stak) == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't sub, stak too short");

	sub = (*stak)->next->n - (*stak)->n;
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
	(*stak)->n = sub;
}
