#include <stdio.h>
#include <stdlib.h>

struct s {
    int data;
    struct s *p1;
    struct s *p2;
};

struct d {

    struct s *node;
    struct d *next;

};

void freedl(struct s *p) {

    //Move to front of list
    while(p->p2 != NULL) {
        p = p->p1;
    }

    while(p != NULL) {
        struct s *next = p->p1;
        free(p);
        p = next;
    }
}

void freedld(struct d *p) {

    while(p != NULL) {
        struct d *n= p->next;
        free(p);
        p = n;
    }
}

void freetree(struct s *p) {

    if(p == NULL) return;
    freetree(p->p1);
    freetree(p->p2);
    free(p);

}

int sizeS(struct d *list) {

    int i = 0;
    while(list != NULL) {
        i++;
        list=list->next;
    }
    return i;
}


void appendNode(struct d *list, struct d *toAppend) {

    while(list->next != NULL) {
        list = list->next;
    }

    list->next=toAppend;
}

int isEmpty(struct d *list) {
    if(list->next == NULL) return 1;
    return 0;
}

struct d *popItem(struct d *list) {

    struct d *temp = list->next;
    if(list->next->next != NULL) list->next=list->next->next;
    return temp;

}


int contains(struct d *list, struct s *searchNode) {

    while(list->next != NULL) {
        if(list->next->node == searchNode) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}


void freegraph(struct s *p) {

    //Initialise queue
    struct d *queue = malloc(sizeof(struct d));
    queue->next=NULL;
    queue->node=NULL;
    struct d *firstNode = malloc(sizeof(struct d));
    firstNode->node=p;
    firstNode->next=NULL;
    queue->next=firstNode;


        printf("made it here");
    //Initialise explored set
    struct d *explore = malloc(sizeof(struct d));
    explore->next=NULL;
    explore->node=NULL;
    struct d *firstNodeExp = malloc(sizeof(struct d));
    firstNodeExp->node=p;
    firstNodeExp->next=NULL;
    explore->next=firstNodeExp;

    while(isEmpty(queue) == 0) {
        printf("no it pop");
        struct d *curr = popItem(queue);
        struct d *next1 = malloc(sizeof(struct s));
        next1->node=curr->node->p1;
        next1->next=NULL;
        struct d *next2 = malloc(sizeof(struct s));
        next2->node=curr->node->p2;
        next2->next=NULL;
        printf("made it here");
        if(contains(explore, next1->node) == 0) {
            appendNode(explore, next1);
            appendNode(queue, next1);
        }
        if(contains(explore, next2->node) == 0) {
            appendNode(explore, next2);
            appendNode(queue, next2);
        }
        free(curr);
    }

    printf("made it end");

    free(queue);
    struct d *oldExplore=explore;
    explore=explore->next;
    while(explore != NULL) {
        free(explore->node);
        explore=explore->next;
    }
    freedld(explore);

}

struct s *treeOrGraphGen(struct s *l, int d, struct s *r) {
    struct s *tree = malloc(sizeof(struct s));

    tree->p1 = l;
    tree->data = d;
    tree->p2 = r;

    return tree;
}

struct s *appendItem(struct s *curr, int v) {

    while(curr->p1 != NULL) {   //Move current pointer to end of the list
        curr = curr->p1;
    }

    struct s *item = malloc(sizeof(struct s));
    item->p1 = NULL;
    item->data = v;
    item->p2 = curr;
    curr->p1 = item;

    return item;

}

int main(int argc, char **argv) {

    /*
     *    struct s *HEAD = malloc(sizeof(struct s));
     *    HEAD->p1=NULL;
     *    HEAD->data=1;
     *    HEAD->p2=NULL;
     *
     *    struct s *item2 = appendItem(HEAD, 2);
     *    struct s *item3 = appendItem(HEAD, 3);
     *    struct s *item4 = appendItem(HEAD, 4);
     *
     *    freedl(HEAD);
     *
     *    struct s *root= treeOrGraphGen(NULL, 1, NULL);
     *    struct s *node3= treeOrGraphGen(NULL, 3, NULL);
     *    struct s *node2= treeOrGraphGen(root, 2, node3);
     *    struct s *node5= treeOrGraphGen(NULL, 5, NULL);
     *    struct s *node7 = treeOrGraphGen(NULL, 7, NULL);
     *    struct s *node6 = treeOrGraphGen(node5, 6, node7);
     *    struct s *node4 = treeOrGraphGen(node2, 4, node6);
     *
     *    freetree(node4);
     */

    printf("hello");
    struct s *vertex1 = malloc(sizeof(struct s));
    vertex1->data = 1;
    struct s *vertex2 = malloc(sizeof(struct s));
    vertex2->data = 2;
    struct s *vertex3 = malloc(sizeof(struct s));
    vertex3->data = 3;
    struct s *vertex4 = malloc(sizeof(struct s));
    vertex4->data = 4;

    vertex1->p1=vertex3;
    vertex1->p2=vertex4;

    vertex2->p1=vertex4;
    vertex2->p2=NULL;

    vertex3->p1=vertex4;
    vertex3->p2=vertex2;

    vertex4->p1=vertex1;
    vertex4->p2=NULL;

    
    freegraph(vertex1);

    return 0;
}


