#include <Windows.h>

typedef struct queue queue;
struct queue {
	HANDLE *data;
	queue *next;
	queue *prev;
};

void
qpush(queue **phead, const HANDLE* data);

void
qlist(queue *head);

int
qremove(queue **phead, int k);

HANDLE*
qget(queue* head, int id);

HANDLE*
qgetat(queue* head, int k);

void
free_list(queue* phead);