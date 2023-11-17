#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define _POSIX_C_SOURCE 200809L

/**
 * struct info_s - struct information about the code format
 * @mode: program mode stack and queue
 * @LINE: line number
 * @monty_file: monty file
 * @splitted_line: line holding command
 *
 * Description: mode and line number
 */
struct info_s
{
        char *mode;
        char **splitted_line;
        FILE *monty_file;
        int LINE;
};
extern struct info_s info;

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void pall(stack_t **stak, unsigned int line_num);
void free_stack(stack_t **head);
void push(stack_t **stack, unsigned int line_number);
void call_push(stack_t **, unsigned int line_number, char *);
void check_malloc(stack_t *stack);
void pint(stack_t **stak, unsigned int line_num);
void nop(stack_t **stak, unsigned int line_num);
void free_2d(void);
void pop(stack_t **stak, unsigned int line_num);
void swap(stack_t **stak, unsigned int line_num);
void add(stack_t **stak, unsigned int line_num);
char *trim(char *command);
int check_if_all_spaces(char *command);
int is_comment(char *line);
void (*is_opcode(char *))(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
int isnum(char *);
void divi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void rotr(stack_t **, unsigned int);
void stack(stack_t **stak, unsigned int);
void queue(stack_t **stak, unsigned int);
void mul(stack_t **stack, unsigned int line_number);
char **make_array_of_strings(char *command);
void error_instruction(stack_t **stack, int line, char *instr);
void errno_argc(stack_t **stack);
void errno_fd(char *str, stack_t **stack);
void _perror(stack_t **, unsigned int, char *);
void sub(stack_t **stack, unsigned int line_number);
#endif
