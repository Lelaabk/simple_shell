#include "main.h"

/**
	* execute - helper function do exeution.
	* @buff: input command to execute.
	* Return: if error -1.
*/

int execute(char **buff)
{
	/**
	*char *argv[2];
	*
	*argv[0] = buff;
	*argv[1] = NULL;
	*/


	execve(buff[0], buff, environ);
	perror(buff[0]);
	_freeptr(buff);
return (2);
}
