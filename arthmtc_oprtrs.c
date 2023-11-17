#include "monty.h"
/**
 * divi - implement monty division
 * @stak: pointer to stack top
 * @line_num: line number
 * Return: nothing
*/
void divi(stack_t **stak, unsigned int line_num)
{
	int div;

	if ((*stak) == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't div, stak too short");

	if ((*stak)->n == 0)
		_perror(stak, line_num, "division by zero");

	div = (*stak)->next->n / (*stak)->n;
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
	(*stak)->n = div;
}
/**
 * add - implement monty add
 * @stak: top of stack pointer
 * @line_num: line's number
 * Return: nothing
*/
void add(stack_t **stak, unsigned int line_num)
{
	int add;

	if ((*stak) == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't add, stak too short");

	add = (*stak)->n + (*stak)->next->n;
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
	(*stak)->n = add;
}
/**
 * mul - implementation of monty mul
 * @stak: ptr to stack top
 * @line_num: line number
 * Return: 0
*/
void mul(stack_t **stak, unsigned int line_num)
{
	int mul;

	if ((*stak) == NULL || (*stak)->next == NULL)
		_perror(stak, line_num, "can't mul, stak too short");

	mul = (*stak)->n * (*stak)->next->n;
	(*stak) = (*stak)->next;
	free((*stak)->prev);
	(*stak)->prev = NULL;
	(*stak)->n = mul;
}
