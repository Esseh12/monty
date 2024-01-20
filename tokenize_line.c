#include "monty.h"

/**
 * tokenize_line - tokenize a string
 * @string: the string to tokenize
 * @tokens: the array to save each tokens
 * Return: Nothing
 */
void tokenize_line(char *string, char **tokens)
{
	char *token;
	char *delim = " \n";
	int i = 0;

	token = strtok(string, delim);

	/* to to the end of array tokens */
	if (tokens != NULL)
	{
		while (tokens[i] != NULL)
		{
			if (tokens[i] == NULL)
				break;
			i++;
		}
	}
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
}
