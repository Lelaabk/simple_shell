#include "main.h"

/**
	* prompt - responsible for spawn prompt, respawn after each execution.
	* @arg: input arg.
	* Return: exit on failure.
*/

void prompt(void)
{
	char *buff = NULL;
	size_t buffsize = 0;
	pid_t ex_pid;
	int status = 0;
	char **cmd;

	for (;;)
	{
		printprompt("mega-team");
		fflush(stdin);
		if (getline(&buff, &buffsize, stdin) == -1)
		{
			_free(buff);
			exit(0);
		}
		cmd = removetokens(buff, "\n \t");

		ex_pid = fork();
		if (ex_pid == 0)
		{
			execute(cmd);
		}
		else
		{
			wait(&status);
			_freeptr(cmd);
			/*_free(buff);*/
		}
	}
}
