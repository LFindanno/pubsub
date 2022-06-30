#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>

#include "pubsub.h"
#include "events.h"

void call();
void call2();

void *forever();


int main(){
	pthread_t thread1;
	int tret1;
	
	tret1 = pthread_create( &thread1, NULL, forever, NULL);
	
	pb_subscribe(FIRST_EVENT, call);
	sleep(5);
	pb_subscribe(FIRST_EVENT, call2);
	pb_publish(FIRST_EVENT);
	tret1 = pthread_cancel(thread1);
	exit(0);
}

void call(){
	printf("first\n");
}


void call2(){
	printf("second\n");
}

void *forever(){
	sleep(2);
	printf("forever ");
	pb_publish(FIRST_EVENT);
	for(;;);
}
