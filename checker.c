#include "monty.h"
/**
 * isnum - check if the argument is integer
 * @num: number to be checked
 * Return: return 1 if is number, 0 otherwise
 */
int isnum(char *num)
{
    int z = 0;

    if (num == NULL || num[0] == '\0')
        return 0;

    if (num[0] == '-' && strlen(num) > 1)
        z++;

    for (; num[z] != '\0'; z++)
    {
        if (isdigit(num[z]) == 0)
            return 0;
    }

    return 1;
}
/**
 * is_comment - check if the line is comment
 * @line: line from buffer
 * Return: 1 if line the is comment, 0 otherwise
 */
int is_comment(char *line)
{
    int i = 0;

    do 
    {
        if (isspace(line[i]))
        {
            i++;
            continue;
        } 
        else if (line[i] == '#')
        {
            return 1;
        } else {
            return 0;
        }
        i++;
    } 
    while (line[i] != '\0');

    return 0;
}

