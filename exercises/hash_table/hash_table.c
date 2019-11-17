#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

#define HASHSIZE 101

static entry *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

char *strdupl(char *s) {
    char *p;

    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

entry *lookup (char *s) {
    entry *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np; /* found */
        }
    }
    return NULL;      /* not found */
}

entry *install (char *name, char *defn) {
    entry *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (entry *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdupl(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else { /* already exists */
        free((void *)np->defn); /* free previous defn */
    }
    if ((np->defn = strdupl(defn)) == NULL) {
        return NULL;
    }
    return np;
}