#include "monty.h"
/**
* trim - removes the spaces around str
* @command: command
* Return: command
*/
char *trim(char *command)
{
char *end;

for (; isspace((unsigned char)*command); command++)
;

if (*command == 0)
return (command);

end = command + strlen(command) - 1;

for (; end > command && isspace((unsigned char)*end); end--)
;

*(end + 1) = '\0';
return (command);
}

/**
* is_opcode - checks if command given  is valid opcode
* @cmd: command to be checked
* Return: pointer to function
*/
void (*is_opcode(char *cmd))(stack_t **stack, unsigned int L)
{
int i;
instruction_t opcodes[] = {
{"pop", pop},
{"pint", pint},
{"pall", pall},
{"swap", swap},
{"nop", nop},
{"add", add},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{"stack", stack},
{"queue", queue},
{"sub", sub},
{"div", divi},
{"mod", mod},
{"mul", mul},
{NULL, NULL},
};

for (i = 0; opcodes[i].opcode != NULL; i++)
{
if (strcmp(cmd, opcodes[i].opcode) == 0)
return (opcodes[i].f);
}
return (NULL);
}
/**
* check_if_all_spaces - checks if the line contains only spaces
* @command: command str
* Return: 0 if all spaces, 1 if not all
*/
int check_if_all_spaces(char *command)
{
int cntr;
static size_t sp;

sp = 0;
cntr = 0;
if (command[cntr] == ' ')
{
while (command[sp])
if (isspace((unsigned char)command[sp]))
sp++;
else
break;
cntr++;
}
if (sp == strlen(command))
return (0);
return (1);
}
