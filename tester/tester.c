#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    FILE *file;
    char command[100];

    // Abrir o arquivo contendo a lista de comandos
    file = fopen("comandos.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo comandos.txt");
        return 1;
    }

    // Ler cada linha do arquivo e executar o comando correspondente
    while (fgets(command, sizeof(command), file) != NULL) {
        // Remover o caractere de nova linha (\n) da string do comando
        command[strcspn(command, "\n")] = '\0';

        // Criar um processo filho para executar o comando
        pid_t pid = fork();

        if (pid < 0) {
            perror("Erro ao criar o processo filho");
            return 1;
        } else if (pid == 0) {
            // Processo filho: executar o comando
			execlp("/home/pastilhex/Desktop/CommonCore42/42_minishell/minishell", "minishell", "-c", (char* const*)command, NULL);
            // execlp("minishell", "minishell", "-c", command, NULL);
            perror("Erro ao executar o comando");
            exit(1);
        } else {
            // Processo pai: aguardar o término do processo filho
            int status;
            waitpid(pid, &status, 0);

            // Verificar o código de saída do comando
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status == 0) {
                    printf("O comando '%s' foi executado com sucesso.\n", command);
                } else {
                    printf("Erro na execução do comando '%s'. Código de saída: %d\n", command, exit_status);
                }
            } else {
                printf("O comando '%s' foi encerrado anormalmente.\n", command);
            }
        }
    }

    // Fechar o arquivo
    fclose(file);

    return 0;
}