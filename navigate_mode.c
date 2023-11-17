#include "monty.h"
/**
 * queue - switch to FIFO STYLE
 * @stak: pointer to  stack top
 * @L: line number
 * Return: 0
 */
void queue(stack_t **stak, unsigned int L)
{
	(void)stak;
	(void)L;
	info.mode = "queue";
}

/**
 * stack - switch to LIFO STYLE
 * @stack: pointer to the queue front
 * @L: line number
 * Return: 0
 */
void stack(stack_t **stak, unsigned int L)
{
	(void)stak;
	(void)L;
	info.mode = "stack";
}
