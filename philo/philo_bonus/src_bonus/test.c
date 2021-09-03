# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

void what_if(void)
{
	printf("%d\n", fork());
}

int main(int argc, char *argv[])
{
	pid_t pid;

	printf("%s\n", argv[1]);
	what_if();
	printf("test\n");
	pause();
	return (argc);
}