#include "monty.h"
/**
 * errno_argc - argc error
 * @stack: stack
 * Return: nothing
 * _perror: print to std output
*/
void errno_argc(stack_t **stack)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}
void _perror(stack_t **stack, unsigned int L, char *s)
{
	fprintf(stderr, "L%d: %s\n", L, s);
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		free(info.monty_file);
	exit(EXIT_FAILURE);
}
