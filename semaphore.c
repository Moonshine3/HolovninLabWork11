
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/Holovnin"

int main(int argc, char **argv){
        sem_t *sem;
        if(argc != 2){
                if((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED){
                        fprintf(stderr, "Holovnin sem_open error");
                        return 1;
                }
                printf("Holovnin sem_open. Holovnin semaphore is taken.\n Waiting for it to be dropped.\n");
                if(sem_wait(sem)<0)
                        fprintf(stderr, "Holovnin sem_wait error");
                if(sem_close(sem)<0)
                        fprintf(stderr, "Holovnin sem_close error");
                return 0;
        }
        else{
                printf("Dropping Holovnin semaphore\n");
                if((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED){
                        fprintf(stderr, "Holovnin sem_open error");
                        return 1;
                }
                sem_post(sem);
                printf("Holovnin sem_post. Holovnin semaphore dropped.\n");
                return 0;
        }
}

