#include <stdio.h>
#include <stdlib.h>

struct s {
    int data;
    struct s *p1;
    struct s *p2;
};


void freedl(struct s *p) {
    
    while(p != NULL) {
        struct s *next = p->p1;
        free(p);
        p = next;
    }
}

void freetree(struct s *p) {

    if(p == NULL) return;
    freetree(p->p1);
    freetree(p->p2);
    free(p);

}

void freegraph(struct s *p) {



}

struct s *appendItem(struct s *curr, int v) {

    struct s *item = malloc(sizeof(struct s));
    item->p1 = NULL;
    item->data = v;
    item->p2 = curr;
    curr->p1 = item;

    return item;

}

struct s *treeOrGraphGen(struct s *l, int d, struct s *r) {
    struct s *tree = malloc(sizeof(struct s));

    tree->p1 = l;
    tree->data = d;
    tree->p2 = r;

    return tree;
}

int main(int argc, char **argv) {

    struct s *HEAD = malloc(sizeof(struct s));
    HEAD->p1=NULL;
    HEAD->data=1;
    HEAD->p2=NULL;

    struct s *item2 = appendItem(HEAD, 2);
    struct s *item3 = appendItem(item2, 3);
    struct s *item4 = appendItem(item3, 4);

    freedl(HEAD);

    struct s *root= treeOrGraphGen(NULL, 1, NULL);
    struct s *node3= treeOrGraphGen(NULL, 3, NULL);
    struct s *node2= treeOrGraphGen(root, 2, node3);
    struct s *node5= treeOrGraphGen(NULL, 5, NULL);
    struct s *node7 = treeOrGraphGen(NULL, 7, NULL);
    struct s *node6 = treeOrGraphGen(node5, 6, node7);
    struct s *node4 = treeOrGraphGen(node2, 4, node6);

    freetree(node4);

    return 0;
}


