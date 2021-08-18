#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

char quitarsalto(char *linea);
extern char **environ;
int tamanio(char *linea);
int guardarargumentos(char *linea, char *argumentos[]);
int numerotokens(char *linea, char *separador);
void _path(char **argumentos, char **environ, int numtokens, int cont);
int comparar_envi(char *comando);
int concadenar(char *path, char **comando, char **environ, int cont);
int separarpath(char *pathfinal, char *comando, char **paths);
void guardarargumentos2(char *linea, char *argumentos[], char *comando);
int funcionpath(char *pathfinal, char *path,
int tam, char **comando, char **environ);
int search_env(char **argumentos, char **environ);
int comparar_env(char *comando);
void SigintHandler(int sigint);
void funcionmain(pid_t pid, char **argumentos,
int num, char *linea, char **environ, int cont);
int main(void);
int comparar(char *linea);
int _free(char **token, int tam);
int _withformat(char c, int count, va_list valist);
int _printf(const char *format, ...);
int print_number(int n);
int _printstring(char *s);
int _putchar(char c);
int __withformat(char c, int count, va_list valist);
int __printf(const char *format, ...);
int __printstring(char *s);
int __putchar(char c);
int penv(char **environ, char *comando);
#endif
