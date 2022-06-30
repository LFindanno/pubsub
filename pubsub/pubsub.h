#ifndef PUBSUB_H
#define PUBSUB_H

struct pubsub{
	int event;
	void (*callback)();
	struct pubsub *next;
};


void pb_publish(const int event);
void pb_subscribe(const int event, void (*callback)());


#endif
