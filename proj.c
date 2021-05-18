#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 5
//Adam Murji, Blake Sutherland, Matthew Hussey, Christoper Coscarella
int buffer[SIZE] = {0};
sem_t empty, full;
int ext = 0;
pthread_mutex_t mutexLock;

int insert(int item, int location){ //insert item into buffer
	if (buffer[location] == 0){
		buffer[location] = item;
		printf("Producer produced %d\n", item);
	}
	else
		return -1;
	return 0;
}

int rem(int location){ //remove item from buffer
	int item = 0;
	if (buffer[location] == 0)
		return -1;
	else{
		
		item = buffer[location];
		buffer[location] = 0;
		printf("Consumer consumed %d\n", item);
	}
	return 0;
}

void *producer(void *param) { //producer thread
	int item = rand(); //generate value
	int result = 0;
	int location = 0;
	while (ext==0){
		sleep(rand()%6);
		pthread_mutex_lock (&mutexLock); //lock buffer
		result = insert(item, location);
		pthread_mutex_unlock (&mutexLock); //unlock
		if (result == -1)
			sem_wait(&full);
		else{
			location = (location+1) % SIZE;
			sem_post(&empty);
			item = rand();
		}
	}
	pthread_exit(&item);
	return NULL;
}

void *consumer(void *param){ //consumer thread
	
	int item;
	int result = 0;
	int location = 0;
	
	while(ext==0){
		sleep(rand()%10);
		pthread_mutex_lock (&mutexLock); //lock
		result = rem(location);
		pthread_mutex_unlock (&mutexLock); //unlock
		if (result == -1)
			sem_wait(&empty); //if no available resources, wait for signal
		else{
			location = (location+1) % SIZE;
			sem_post(&full); //signal that there's free space
		}
	}
	pthread_exit(&item);
	return NULL;
}



int main(int argc, char *argv[]){

	if (argc == 4){
		char *sPtr;
		int slpTime = strtol(argv[1],&sPtr, 10);
		int prdThrd = strtol(argv[2],&sPtr, 10);
		int comThrd = strtol(argv[3],&sPtr, 10);
		if (prdThrd < 1 || comThrd < 1){
			printf("There must be some number of threads\n");
			return 0;
		}
		if (slpTime < 1){
			printf("There must be a length of time");
			return 0;
		}
		int thrdTotal = prdThrd + comThrd; 
		sem_init(&empty, 0, 0);
		sem_init(&full, 0, SIZE);
		int s;
		pthread_t thread[thrdTotal];
		for (int i = 0 ; i < prdThrd; i++){
			s = pthread_create(&thread[i], NULL, producer, NULL);
}
		for (int i = prdThrd; i < thrdTotal; i++){
			s = pthread_create(&thread[i], NULL, consumer, NULL);
}
		sleep(slpTime);
		ext = 1;
		
		for(int v = 0; v < thrdTotal; v++){
			s = pthread_join(thread[v],NULL);
		}
		return 0;
	}
	else
		printf("Wrong number of command line entries\n");
}	
