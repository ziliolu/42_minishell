#include "../includes/minishell.h"
#include <unistd.h>

/**
 * RESUMO
 * 
 * - pipe e um mecanismo de comunicacao entre processos
 * - data written to the pipe by one process can be read by another process. 
 * - fd[0] e fd[1] comecam abertos. 
 * - necessario fechar o fd[0] para escrever no fd[1].
 * - necessario fechar o fd[1] para ler do fd[0].
 * - antes de sair os dois fd precisam estar fechados. 
 * 
 * 
 * - focar em entender melhor o dup e dup2
 * - execucao de um comando ja e classificada como processo ou necessrio o fork? 
 * -  
 * 
*/

// int main(int argc, char **argv, char **env)
// {
//     int fd[2];
//     int id;
//     int i;
//     int j;
    
//     i = 0;
//     j = 0;
//     pipe(fd);
//     printf("fd: %d %d\n", fd[0], fd[1]);
//     id = fork();

//     if(id == 0)
//     {
//         close(fd[0]);
//         printf("insira valor: ");
//         scanf("%d", &i);
//         write(fd[1], &i, sizeof(int));
//         close(fd[1]);
//     }
//     else
//     {
//         close(fd[1]);
//         read(fd[0], &j, sizeof(int));
//         close(fd[0]);
//         printf("mensagem recebida: %d\n", j);
//     }
//     return(0);
// }

/** echo hello | grep h | grep o
 * 
 * primeiro comando: echo hello
 * criacao do pipe (criacao de 2 processos)
 *  1. tratar a recepcao do comando 1 -> read 
 *  2. enviar atraves do write para o prox comando
*/
 
