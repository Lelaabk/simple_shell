#include "main.h"

/**
	* main - runs as the shell engine.
	* @argc: args number.
	* @argv: args values.
	*Return: return 0 on EOF detected.
*/

int main(int argc, char *argv[])
{
	char *buff = NULL;
	size_t buffsize = 0;
	char **cmd = NULL;
	int status = 0;
	pid_t ex_pid;
	char **ptr;

	signal(SIGINT, signalhandler);
	if (isatty(0) == 0)
	{
		while ((getline(&buff, &buffsize, stdin)) != -1)
		{
		cmd = removetokens(buff, "\t \n");
		ptr = input_checker(cmd, buff, argv[0]);
		if (ptr == NULL)
		{
			_freeptr(ptr);
			break;
		}

		if (_strcmp(ptr[0], "cd") == 0)
		{
			_freeptr(ptr);
			continue;
		}
		ex_pid = fork();
		if (ex_pid == 0 && argc != 0)
			execute(ptr);
		else
		{
			wait(&status);
			_freeptr(ptr);
		}
		}
	}
	else
	{
		prompt(argv[0]);
	}
return (WIFEXITED(status) ? WEXITSTATUS(status) : 0);
}
