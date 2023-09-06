// 27. Write a program to execute ls -Rl by the following system calls

// a. execl
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     execl("/bin/ls","ls","-ri",NULL);
//     perror("execl did not work");
//     exit(EXIT_FAILURE);
//     return 0;
// }


// b. execlp
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     execlp("/bin/ls","ls","-ri",NULL);
//     perror("execlp did not work");
//     exit(EXIT_FAILURE);
//     return 0;
// }


// c. execle
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     char* arr[] = {NULL};
//     execle("/bin/ls","ls","-ri",NULL,arr);
//     perror("execle did not work");
//     exit(EXIT_FAILURE);
//     return 0;
// }


// d. execv
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     char* arr[] = {"ls","-ri",NULL};
//     execv("/bin/ls",arr);
//     perror("execv did not work");
//     exit(EXIT_FAILURE);
//     return 0;
// }


// e. execvp
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    char* arr[] = {"ls","-ri",NULL};
    execvp("/bin/ls",arr);
    perror("execv did not work");
    exit(EXIT_FAILURE);
    return 0;
}