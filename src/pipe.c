// #include "../includes/minishell.h"
// #define READ_END    0    /* index pipe extremo escritura */
// #define WRITE_END   1

// //ls | grep h | grep o

// int main(int argc, char* argv[])   
// {
//     int fd1[2];
//     int status, pid;
	
//     pipe(fd1);                 /* comunica ls y grep */
	
//     pid = fork();     
//     if(pid == 0)              /* hijo 1*/
//     {      		
//         close(fd1[READ_END]);   /* cerrar extremo no necesario */
		
//         dup2(fd1[WRITE_END], STDOUT_FILENO); 
// 	    close(fd1[WRITE_END]);
//         execlp("/bin/ls", "ls", NULL);
//     }
//     else                          /* padre */
//     { 
// 	    close(fd1[WRITE_END]);    /* extremo no necesario ya */
//         dup2(fd1[READ_END], STDIN_FILENO);
// 	    close(fd1[READ_END]);
//         execlp("/bin/grep","grep", "bu",NULL);
		
//     }
//     wait(&status);
//     return(0); 	
// }

