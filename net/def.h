#ifndef DEF_H
#define DEF_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct ListEntryStruct {
	void* value;
	struct ListEntryStruct* next;
	struct ListEntryStruct* prev;
} ListEntry;

typedef struct {
	ListEntry* first;
	int size;
} List;

void* ListGet(List* l, int index);
int ListFind(List* l, void* value);
int ListSize(List* l);
void ListAdd(List* l, void* value);
void ListRemove(List* l, int index);


#endif // DEF_H
