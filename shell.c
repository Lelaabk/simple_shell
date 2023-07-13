#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARG 10

int main()
{
	char cmd[MAX_CMD_LEN];
	char *arg[MAX_ARG];
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		/* Remove trailing new line.*/
		cmd[strcspn(cmd, "\n")] = '\0';

		char *sign = strtok(cmd, " ");
		int arg_i = 0;

		while (sign != NULL && arg_i < MAX_ARG - 1)
		{
			arg[arg_i++] = sign;
			sign = strtok(NULL, " ");
		}
		arg[arg_i] = NULL;
		/*Create new process*/
		pid_t pidt = fork();

		if (pidt == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pidt == 0)
		{
			/*Child process*/
			execvp(arg[0], arg);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			/*Parent process*/
			waitpid(pidt, &status, 0);
			if (status != 0)
				printf("%s: No such file or directory\n", arg[0]);
		}
	}
	return (0);
}
