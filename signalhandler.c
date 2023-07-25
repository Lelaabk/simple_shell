#include "main.h"

/**
 * signalhandler - handle signal.
 * @sig: input.
 */

void signalhandler(int sig)
{
	signal(sig, SIG_IGN);
	exit(0);
}
