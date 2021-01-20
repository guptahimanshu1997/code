#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<math.h>
#define r 10
typedef struct node {
	int data;
	struct node  *next;
	struct node  *prev;
} NODE;

typedef struct deque {
	int count;
	NODE *head;
} DEQUE;


DEQUE *createDeque(void) {
	NODE *np;
	DEQUE *bins;
	bins = malloc (sizeof (DEQUE));
	np = malloc (sizeof (NODE));
	assert (bins != NULL && np != NULL);
	bins -> head = np;
	np -> next = np;
	np -> prev = np;
	bins -> count = 0;
	return (bins);
}




int numItems (DEQUE *bins) {
	return (bins -> count);
}


void addFirst (DEQUE *bins, int x) {
	NODE *np;
	np = malloc (sizeof (NODE));
	assert  (np != NULL);
	np -> data = x;
	np -> next = bins -> head -> next;
	np -> prev = np -> next -> prev;
	np -> next -> prev = np;
	bins -> head -> next = np;
	bins -> count++;
}


void addLast (DEQUE *bins, int x) {
	NODE *np;
	np = malloc (sizeof (NODE));
	assert (np != NULL);
	np -> data = x;
	np -> next = bins -> head;
	np -> prev = bins -> head -> prev;
	np -> prev -> next = np;
	bins -> head -> prev = np;
	bins -> count++;
}


int removeFirst (DEQUE *bins) {
	int x;
	assert (bins != NULL && bins -> count != 0);
	bins -> head -> next = bins -> head -> next -> next;
	x = bins -> head -> next -> prev -> data;
	free (bins -> head -> next -> prev);
	bins -> head -> next -> prev = bins -> head;
	bins -> count--;
	return (x);
}


int removeLast (DEQUE *bins) {
	int x;
	assert (bins != NULL && bins -> count != 0);
	bins -> head -> prev = bins -> head -> prev -> prev;
	x = bins -> head -> prev -> next -> data;
	free (bins -> head -> prev -> next);
	bins -> head -> prev -> next = bins -> head;
	bins -> count--;
	return (x);
}


int getFirst (DEQUE *bins) {
	return (bins -> head -> next -> data);
}


int getLast (DEQUE *bins) {
	return (bins -> head -> prev -> data);
}


int  main (void) {
	int i,j,k,x,y,z;
	int num;
	int max = 0;


	DEQUE *toBeSorted;
	toBeSorted = createDeque();


	int n;
	scanf("%d",&n);
	int a[n];
	int p;
	for(p=0;p<n;p++)
    {
        scanf("%d",&a[p]);
    }


        if(n==0||a[0]<=0)
        {
            printf("INVALID INPUT");
        }


     else{

    for(p=0;p<n;p++)
    {
        addLast(toBeSorted,a[p]);
    }

    for(p=0;p<n;p++)
    {
        if(a[p]<0)
        {
            printf("INVALID INPUT");
            return 0;
        }
    }


	DEQUE *bins[r];
	for (i = 0; i < r; i++) {
		bins[i] = createDeque();
	}


	int atTheEnd = 0;
	i = 0;





	while (!atTheEnd) {
		atTheEnd = 1;
		while(numItems(toBeSorted) != 0) {
			z = removeFirst(toBeSorted);
			y = (z / ((int)pow(10,i))) % 10;
			addLast(bins[y], z);

			if ((z / ((int)pow(10,i))) > 0) {
				atTheEnd = 0;
			}
		}


		for (j = 0; j < r; j++) {
			while (numItems(bins[j]) != 0) {
				z = removeFirst(bins[j]);
				addLast(toBeSorted,z);
			}
		}

		i++;
	}
	for (i = 0; i < numItems(toBeSorted); i++) {
		k = removeFirst(toBeSorted);
		printf ("%d ", k);
		addLast(toBeSorted,k);
	}
	}
}
