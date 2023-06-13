//Question:Create child and grandchild process and prints its pid and parent's pid

//Code:
#include<stdio.h>
#include<unistd.h>


int grandchild()
{
  pid_t  g_pid;
  g_pid=fork();

 if(g_pid<0)
  {
   printf("creation of grandchild process failed");
  }

  if(g_pid==0)
  {
    printf("this is grandchild process and its pid is:%d\n",getpid());
    printf("this is granchild process and its parent pid is:%d\n",getppid());
  }

}

int main()
{
  pid_t pid;
  pid=fork();


  if(pid<0)
  {
    printf("creation of child process failed");
  }

  else if(pid==0)
  {
    printf("this is child process and its pid is:%d\n",getpid());
    printf("this is child process and its parent pid is:%d\n",getppid());
    grandchild();
  }

  else
  {
  printf("this is parent process and its pid is:%d\n",getpid());
  }

}


//Output:
this is parent process and its pid is:648
this is child process and its pid is:649
this is child process and its parent pid is:648
this is grandchild process and its pid is:650
this is granchild process and its parent pid is:649

