// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int numPipes = 3; // Number of pipes
//     int fd[numPipes][2]; // Array of pipe file descriptors
//     pid_t pid;

//     // Create the pipes
//     //numPipes = 2
//     for (int i = 0; i < numPipes; i++) {
//         if (pipe(fd[i]) == -1) {
//             perror("pipe");
//             exit(EXIT_FAILURE);
//         }
//     }

//     //ls | grep h | grep o

//     for (int i = 0; i < numPipes; i++) {
//         pid = fork();

//         if (pid == -1) {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         //fd[0][0]
//         //fd[0][1] 
//         if (pid == 0) {

//             //fd[0][0] X
//             //fd[0][1] X - GUARDA RESULTADO DO LS

//             i = 1
//             //fd[1][0]
//             //fd[1][1] 

//             //fd[0][0] X - vira o stdin do comando 2
//             //fd[0][1] X - GUARDA RESULTADO DO LS

//             // i = 0
//             // Child process: Execute command
//             if (i > 0) {
//                 close(fd[i - 1][1]);  // Close write end of the previous pipe
//                 dup2(fd[i - 1][0], STDIN_FILENO);  // Redirect stdin to the read end of the previous pipe
//                 close(fd[i - 1][0]);  // Close read end of the previous pipe
//             }

//             if (i < numPipes - 1) {
//                 close(fd[i][0]);  // Close read end of the current pipe
//                 dup2(fd[i][1], STDOUT_FILENO);  // Redirect stdout to the write end of the current pipe
//                 close(fd[i][1]);  // Close write end of the current pipe
//             }

//             // Execute the command
//             execlp("command", "command", NULL);
//             perror("exec command");
//             exit(EXIT_FAILURE);
//         }

//     }

//     // Close all pipe file descriptors in the parent process
//     for (int i = 0; i < numPipes; i++) {
//         close(fd[i][0]);
//         close(fd[i][1]);
//     }

//     // Wait for all child processes to complete
//     for (int i = 0; i < numPipes; i++) {
//         wait(NULL);
//     }

//     return 0;
// }



/* while IFS= read -r command; do
    # Executa o comando e redireciona a saída para a variável "output"
    output=$(./minishell -c "$command" 2>&1)

    # Verifica o código de saída do comando
    if [ $? -eq 0 ]; then
        # Comando executado com sucesso (código de saída zero)
        echo -e "\033[32m$command\033[0m"  # Exibe o comando em verde
    else
        # Comando com erro (código de saída diferente de zero)
        echo -e "\033[31m$command\033[0m"  # Exibe o comando em vermelho
    fi

    # Exibe a saída do comando
    # echo "$output"

    echo "----------------------------------------"
done < tester/comandos.txt */


