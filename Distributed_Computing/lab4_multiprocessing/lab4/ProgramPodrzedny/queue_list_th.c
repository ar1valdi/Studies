#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_list_th.h"

void qlist(queue *head) {
	queue *p;
	int i = 1;
	
	for (p = head; p != NULL; p = p->next) {
		printf("%d: ID=%d PRIO=%d\n", i++, GetThreadId(*p->data), GetThreadPriority(*p->data));
	}
}

void qpush(queue **phead, HANDLE* data) {
	queue *p = *phead;

	queue* newNode = (queue*)malloc(sizeof(queue));
	if (newNode == NULL) { return; }

	if (p == NULL) {
		p = newNode;

		p->next = NULL;
		p->prev = NULL;
		p->data = data;
		*phead = p;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}

		newNode->prev = p;
		newNode->next = NULL;
		newNode->data = data;

		p->next = newNode;
		p = p->next;
	}
}

int qremove(queue **phead, int k) {
	queue* p = *phead;
	
	for (int i = 0; GetThreadId(*p->data) != k; i++) {
		p = p->next;
		
		if (p == NULL) {
			return 1;
		}
	}

	if (p->next != NULL) {
		p->next->prev = p->prev;
	}

	if (p->prev != NULL) {
		p->prev->next = p->next;
	} else {
		if (p->next == NULL) {
			*phead = NULL;
		} else {
			*phead = p->next;
		}
	}

	free(p->data);
	free(p);
	return 0;
}

HANDLE* qget(queue* head, int id) {
	queue* p = head;
	while (p != NULL && GetThreadId(*p->data) != id) {
		p = p->next;
	}

	if (p == NULL) {
		return NULL;
	}
	return p->data;
}

HANDLE* qgetat(queue* head, int k) {
	queue* p = head;
	for (int i = 0; i < k && p != NULL; i++) {
		p = p->next;
	}

	if (p == NULL) {
		return NULL;
	}
	return p->data;
}

void free_list(queue *phead) {
	while (phead != NULL) {
		queue* next = phead->next;
		free(phead->data);
		free(phead);
		phead = next;
	}
}