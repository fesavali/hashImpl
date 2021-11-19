#include "hashmap.h"
#include stdio.h
#include string.h
#include stdlib.h
#include stdbool.h
#include mlock.c

void hashmap_init(struct hashmap* map, 
		size_t(*hash)(struct hashmap*,void*), 
		void(*key_del)(void*),
		void(*val_del)(void*), 
		int(*cmp)(void*, void*),
		size_t size,
		size_t objsize) {

   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

}

void hashmap_insert(struct hashmap*, 
		void* key, 
		void* value) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;



}

void* hashmap_get(struct hashmap* map, 
		void* key) {
	 if (h->n_buckets) {                                              \
    khint_t inc, k, i, last;                                    \
    k = __hash_func(key); i = k % h->n_buckets;                  \
    inc = 1 + k % (h->n_buckets - 1); last = i;                  \
    while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], key))) { \
        if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
        else i += inc;                                          \
            if (i == last) return h->n_buckets;                      \
            }                                                           \
            return __ac_iseither(h->flags, i)? h->n_buckets : i;      \
        } else return 0;            
			

}

void* hashmap_get_entry(struct hashmap* map, 
		void* key) {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->hashkey,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");

}

void* hashmap_remove_value(struct hashmap* map, 
		void* key) {
 delete(item);
   item = search(37);
}

void* hashmap_remove_entry(struct hashmap* map, 
		void* key) {
delete(item);
   item = search(37);

}

size_t hashmap_size(struct hashmap* map) {
	  int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}


void hashmap_destroy(struct hashmap* map) {
    hashmap_destroy(item);
}
