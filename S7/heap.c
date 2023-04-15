#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *vec; 
    int size;
    int capacity;
 
    int type; // Tipul heap-ului, camp optional
}Heap;

Heap* create(int capacitate)
{
	Heap *h = (Heap *) malloc(sizeof(Heap));
 
	if (h == NULL)
	{
		printf("Nu s-a putut aloca spatiu");
		return;
	}
	h->size = 0; // Initial heap-ul este gol
	h->capacity = capacitate;
 
	h->vec = (int*) calloc(capacitate, sizeof(int));
	if (h->vec == NULL)
	{
		printf("Nu s-a putut aloca spatiu");
		return;
	}
 
	return h;
 
}

void populateHeap(Heap *h, int *buf, int n)
{
	if(h == NULL || buf == NULL || n ==0) 
		return;
 
	while(n > h->capacity)
		resize(h);
 
	int i = 0;
	for( i = 0; i < n; i++)
		h->vec[i] = buf[i];
	h->size = n;
 
	for(i = (n-1)/2; i >= 0; i--)
		heapify(h, i);
 
}

void insert(Heap *h, int x)
{
	int i;
	if(h->capacity == h->size)
		resize(h);
	i = h->size;
	h->size++;
 
 
	while(i >= 0 && x > h->vec[parent(h,i)])
	{
		h->vec[i] = h->vec[parent(h,i)];
		i = parent(h,i);
	}
	h->vec[i] = x;
}