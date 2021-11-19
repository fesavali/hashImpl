#include stdio.h
#include string.h
#include stdlib.h
#include stdbool.h

#define SIZE 100000

struct DataItem {
   int hashData;   
   int hashkey;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

  static inline get_##name(const ##name##_t *h, khashkey_t hashkey) \
    {                                                                   \
        if (h->n_buckets) {                                              \
            khint_t inc, k, i, last;                                    \
            k = __hash_func(hashkey); i = k % h->n_buckets;                  \
            inc = 1 + k % (h->n_buckets - 1); last = i;                  \
            while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], hashkey))) { \
                if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
                else i += inc;                                          \
                if (i == last) return h->n_buckets;                      \
            }                                                           \
            return __ac_iseither(h->flags, i)? h->n_buckets : i;      \
        } else return 0;                                                \
    }    
int hashCode(int hashkey) {
   return hashkey % SIZE;
}

struct DataItem *search(int hashkey) {
   //get the hash 
   int hashIndex = hashCode(hashkey);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->hashkey == hashkey)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int hashkey,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->hashkey = hashkey;

   //get the hash 
   int hashIndex = hashCode(hashkey);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->hashkey != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int hashkey = item->hashkey;

   //get the hash 
   int hashIndex = hashCode(hashkey);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->hashkey == hashkey) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->hashkey,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->hashkey = -1; 

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