#include "monty.h"
/**
 * make_array_of_strings - func
 * @command: command entered
 * Return: array of strings
 */
char **make_array_of_strings(char *command)
{
    char *token;
    char **tokens = malloc(BUFSIZ * sizeof(char *));
    int num_tokens = 0, i;

    token = strtok(command, " ");

    if (tokens == NULL || token == NULL)
        return NULL;

    for (; token != NULL; num_tokens++)
    {
        tokens[num_tokens] = malloc((strlen(token) + 1) * sizeof(char));
        if (tokens[num_tokens] == NULL)
        {
            for (i = 0; i < num_tokens; i++)
                free(tokens[i]);
            free(tokens);
            return NULL;
        }
        strcpy(tokens[num_tokens], token);
        token = strtok(NULL, " ");
    }

    tokens[num_tokens] = NULL;
    return tokens;
}

/**
 * error_instruction - when an unknown instruction
 * @stack: stack
 * @line: line_number
 * @instr: instruction
 * @buf: buffer
 * Return: nothing
*/
void error_instruction(stack_t **stack, int line, char *instr)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, instr);
	free_2d();
	free_stack(stack);
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}
/**
 * errno_fd - fd error
 * @str: filename
 * @stack: stack
 * Return: nothing
*/
void errno_fd(char *str, stack_t **stack)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	free_stack(stack);
	free_2d();
	if (info.monty_file)
		fclose(info.monty_file);
	exit(EXIT_FAILURE);
}
