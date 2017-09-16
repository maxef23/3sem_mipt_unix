#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <signal.h>

int main() {
   char val[100];
   scanf("%s", val);
   pid_t pid = fork();
   if (pid < 0) {
         printf("fork() error\n");
         return -1;
   }
   if (pid) {
         int status;
         wait(&status);
      } else {
         execlp("gcc", "gcc", val, "-o", "./a.out");
         exit(1);
      }
   pid = fork();      
   if (pid < 0) {       
      printf("fork() error\n");       
      return -1;     
   }      
   if (pid){      
      int status = 0;       
      waitpid(pid, &status, 0);       
      printf("Ret code: %d\n", WEXITSTATUS(status));      
   } else {         
      execvp("./a.out", NULL);     
   }
}


