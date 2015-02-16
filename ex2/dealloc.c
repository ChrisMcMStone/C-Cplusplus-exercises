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
        free(p->node);
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


void appendNode(struct d *list, struct s *toAppend) {

    while(list->next != NULL) {
        list = list->next;
    }

    struct d *listnode = malloc(sizeof(struct d));
    listnode->node = toAppend;
    listnode->next = NULL;
    list->next=listnode;
}

int isEmpty(struct d *list) {
    if(list->next == NULL) return 1;
    return 0;
}

struct s * popItem(struct d *list) {
    if(list->next == NULL) {
        return NULL;
    } else {
        struct d *next = list->next;
        struct s *item = next->node;
        list->next = list->next->next;
        free(next);
        return item;
    }
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

void print_list(struct d *list) {
    int i;
    for(i = 0; list && i < 10; ++i) {
        list = list->next;
    }
    if(i == 10) printf("...");
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


    //Initialise explored set
    struct d *explore = malloc(sizeof(struct d));
    explore->next=NULL;
    explore->node=NULL;
    struct d *firstNodeExp = malloc(sizeof(struct d));
    firstNodeExp->node=p;
    firstNodeExp->next=NULL;
    explore->next=firstNodeExp;

    while(isEmpty(queue) == 0) {
        print_list(explore);
        print_list(queue);
        struct s *curr = popItem(queue);
        print_list(queue);
        if(curr->p1 && contains(explore, curr->p1) == 0) {
            appendNode(explore, curr->p1);
            appendNode(queue, curr->p1);
        }
        if(curr->p2 && contains(explore, curr->p2) == 0) {
            appendNode(explore, curr->p2);
            appendNode(queue, curr->p2);
        }
    }
    freedld(explore);
    free(queue);
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

void test_freegraph() {
    struct s *one   = malloc(sizeof *one);
    struct s *two   = malloc(sizeof *two);
    struct s *three = malloc(sizeof *three);
    struct s *four  = malloc(sizeof *four);
    struct s *five  = malloc(sizeof *five);
    struct s *six   = malloc(sizeof *six);

    one->data = 1;
    one->p1 = NULL;
    one->p2 = two;

    two->data = 2;
    two->p1 = three;
    two->p2 = four;

    three->data = 3;
    three->p1 = four;
    three->p2 = one;

    four->data = 4;
    four->p1 = four;
    four->p2 = six;

    five->data = 5;
    five->p1 = NULL;
    five->p2 = NULL;

    six->data = 6;
    six->p1 = five;
    six->p2 = one;

    freegraph(one);
}




int main(int argc, char **argv) {

    struct s *HEAD = malloc(sizeof(struct s));
    HEAD->p1=NULL;
    HEAD->data=1;
    HEAD->p2=NULL;

    struct s *item2 = appendItem(HEAD, 2);
    struct s *item3 = appendItem(HEAD, 3);
    struct s *item4 = appendItem(HEAD, 4);

    freedl(HEAD);

    struct s *root= treeOrGraphGen(NULL, 1, NULL);
    struct s *node3= treeOrGraphGen(NULL, 3, NULL);
    struct s *node2= treeOrGraphGen(root, 2, node3);
    struct s *node5= treeOrGraphGen(NULL, 5, NULL);
    struct s *node7 = treeOrGraphGen(NULL, 7, NULL);
    struct s *node6 = treeOrGraphGen(node5, 6, node7);
    struct s *node4 = treeOrGraphGen(node2, 4, node6);

    freetree(node4);

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

    test_freegraph();

    return 0;
}
