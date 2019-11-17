/************** Data structure declarations ****************/
typedef struct nlist {   /* table entry: */
    struct nlist *next;  /* next entry in chain */
    char *name;          /* defined name */
    char *defn;          /* replacement text */
} entry;

/************** Operations on queue ************************/
/* hash: form hash value for string s */
unsigned hash(char *s);

/* strdup: make a duplicate of s */
char *strdupl(char *s);

/* lookup: look for s in hashtable */
entry *lookup(char *s);

/* install: put (name, defn) in hashtab */
entry *install(char *name, char *defn);
