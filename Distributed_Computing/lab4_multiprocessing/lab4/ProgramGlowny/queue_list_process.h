#include <Windows.h>

typedef struct queue queue;
struct queue {
	PROCESS_INFORMATION *data;
	queue *next;
	queue *prev;
};

void
qpush(queue **phead, PROCESS_INFORMATION* data);

void
qlist(queue *head);

int
qremove(queue **phead, int k);

PROCESS_INFORMATION*
qget(queue* head, int id);

PROCESS_INFORMATION*
qgetat(queue* head, int k);

void
free_list(queue* phead);