#include "pubsub.h"
#include <stddef.h>
#include <stdlib.h>

static struct pubsub *_pb_first = NULL;
static struct pubsub *_pb_last = NULL;

void pb_publish(const int event){
	struct pubsub *scan;
	scan = _pb_first;
	
	do{	
		if (scan->event == event) scan->callback();		
		scan = scan->next;
	}while(scan != NULL);
}

void pb_subscribe(const int event, void (*callback)()){
	struct pubsub *new = malloc(sizeof(struct pubsub));
	
	new->event = event;
	new->callback = callback;
	new->next = NULL;
	
	if (_pb_first == NULL) _pb_first = new;
	if (_pb_last != NULL) _pb_last->next = new;
	_pb_last = new;

}

