#include "head.h"
/**
 * funcionpath - pointer at the path
 * @pathfinal: pointer string to path final
 * @path: pointer to the string path
 * @tam: integer for size tam
 * @comando: pointer to string
 * @environ: store the arguments
 * Return: 0 if not error
 */

int funcionpath(char *pathfinal, char *path,
int tam, char **comando, char **environ)
{
	int cont = 0;
	int igual = 5;

	if (path[5] == 46 && path[6] == 47)
		execve(comando[0], comando, environ);
	if (path[5] == 58)
	{
		execve(comando[0], comando, environ);
	}
	if (igual < tam)
	{
		while (igual < tam)
		{
			pathfinal[cont] = path[igual];
			igual++;
			cont++;
		}
	}
	else
		execve(comando[0], comando, environ);
	return (0);
}

/**
 * search_env - find the path
 * @argumentos: pointer to arguments string
 * @environ: pointer to storage enviroment variables
 * Return: return to counter
 */

int search_env(char **argumentos, char **environ)
{
	int cont = 0;

	if (argumentos)
	{
	}
	while (environ[cont])
	{
		if (comparar_env(environ[cont]) == 1)
		{
			break;
		}
		cont++;
	}
	return (cont);
}

/**
 * comparar_env - to compare string
 * @comando: double pointer to path string
 * Return: 1 if error
 */

int comparar_env(char *comando)
{
	int count = 0;
	char *path = "PATH=";
	int pat = tamanio(path);
	char *dospuntos = ":";

	if (path[0] == dospuntos[0])
		count++;
	if (path[0] == dospuntos[0])
		count++;
	while (path[count])
	{
		if (comando[count] != path[count])
			return (0);
		count++;
	}
	if (count == pat)
		return (1);

	return (1);
}

/**
 * SigintHandler - function for signal crtl + c
 * @sigint: function for signals
 */

void SigintHandler(int sigint)
{
	(void) sigint;
	signal(SIGINT, SigintHandler);
	_printf("\n$ ");
}
