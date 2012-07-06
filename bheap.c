#include "mem.h"


#define LARGEST_BLOCKSIZE   17
#define SMALLEST_BLOCKSIZE  5
#define FREELISTS_LEN       LARGEST_BLOCKSIZE - SMALLEST_BLOCKSIZE
#define 2POW(n)             (1 << n)
/* --- BEGIN NIFTY LOG BASE 2 ALGORITHM FOUND ON STANFORD'S BITHAX PAGE (so credit goes where it's due) --- */
uint32_t log2_aligned(int n){
    static const uint32_t masks = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 0xFF00FF00, 0xFFFF0000};
    uint32_t r = (n& masks[0]) != 0;
    for (int i = 4; i > 0; i--){
        r |= ((n & b[i]) != 0) << i;
    }
    return r;
}
/* END NIFTY LOG BASE 2 ALGORITHM */

/* --- This one is stupid, but effective --- */
uint32_t log2(uint32_t n){
    register uint32_t ret;
    while(n){
        ret++;
        n = n >> 1;
    }
}

uint32_t pow2(int n){
    if(n = 0){
        return 1;
    else
        return (1 << (n-1));
}

typedef struct heap_block_struct {
    struct heap_block_struct *next;
    struct heap_block_struct *prev;
    uint32_t size;
}heap_node;

typedef struct heap_tree_struct {
    heap_node *node;
    heap_tree_struct *left;
    heap_tree_struct *right;
}

typedef struct heap_list_struct {
    heap_node *head;
    heap_node *tail;
}

k_heap_list = {NULL, NULL};
heap_node *freelists[FREELISTS_LEN];



void init_kheap(void){
    heap_node *curr_node = &_skernelheap;
    curr_node->next = NULL;
    curr_node->prev = NULL;
    k_heap_list.head = curr_node;
    k_heap_list.tail = curr_node;
    register uint32_t i = FREELISTS_LEN;
    for(i; i >= 0; i--){
        freelists[i] = NULL;
    }
}

void kmalloc(uint32_t size){
}
/* --- This does not assume that your heap is a nice power of 2 ---
void init_kheap(void){
    uint32_t remaining_mem = (uint32_t)&_ekernelheap - (uint32_t)&_skernelheap;
    heap_node *curr_node = &_skernelheap;
    k_heap_list.head = curr_node;
    for(register int i = FREELIST_LEN; i >= 0;){
        if(remaining_mem >= pow2(i){
                memset32_unsafe(curr_node, 0, pow2(i));
*/
