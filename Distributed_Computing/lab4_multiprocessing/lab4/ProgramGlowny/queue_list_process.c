#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_list_process.h"

void qlist(queue *head) {
	queue *p;
	int i = 1;
	
	for (p = head; p != NULL; p = p->next) {
		DWORD res;
		GetExitCodeProcess(p->data->hProcess, &res);
		if (res != STILL_ACTIVE) {
			p = p->next;
			qremove(&head, i - 1);
			if (p == NULL) { break; }
		}
		else {
			printf("%d: ID=%d PRIO=%d\n", i++, p->data->dwProcessId, GetPriorityClass(p->data->hProcess));
		}
	}
}

void qpush(queue **phead, PROCESS_INFORMATION* data) {
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
	
	for (int i = 0; p->data->dwProcessId != k; i++) {
		p = p->next;
		
		if (p == NULL) {
			return 0;
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
	return 1;
}

PROCESS_INFORMATION* qget(queue* head, int id) {
	queue* p = head;
	while (p != NULL && p->data->dwProcessId != id) {
		p = p->next;
	}

	if (p == NULL) {
		return NULL;
	}
	return p->data;
}

PROCESS_INFORMATION* qgetat(queue* head, int k) {
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