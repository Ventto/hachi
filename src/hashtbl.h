#ifndef HASHTBL
#define HASHTBL

#define LINE_MAX    1000

/* FIXME: Use custom made implementation for wordcounting 
   instead of the generic one ? */ 

typedef struct list_collisions {
    char label[LINE_MAX];
    void *data;
    struct list_collisions *next;
} list_collisions;

typedef struct {
    int size;
    list_collisions **table;
} hashtbl;

hashtbl *hashtbl_init(const int size);
int hashtbl_add(hashtbl *tbl, const char *label, const void *data,
                const size_t sdata);
int hashtbl_delete(hashtbl *tbl, const char *label);
void* hashtbl_find(hashtbl *tbl, const char *label);
void hashtbl_print(const hashtbl *tbl);
void hashtbl_destroy(hashtbl *tbl);

#endif
