#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct twoptr {
    struct twoptr *left;
    int data;
    struct twoptr *right;
};

struct stack {
    struct twoptr *elements[SIZE];
    int top;
};

void push(struct stack *curr, struct twoptr *elem) {

   if(curr->top > (SIZE - 1)) {
        printf("Stack overflow!!!\n");
   } else {
       curr->top++;
       curr->elements[curr->top] = elem;
    }
} 

struct twoptr *pop(struct stack *curr) {

    if(curr->top == -1) {
        printf("Stack empty");
    } else {
        struct twoptr *result = curr->elements[curr->top];
        curr->top--;
        return result;
    }
}


struct twoptr *tree_create(struct twoptr *l, int d, struct twoptr *r) {
    struct twoptr *tree = malloc(sizeof(struct twoptr));

    tree->left = l;
    tree->data = d;
    tree->right = r;

    return tree;
}


void indent(int indent_level) {
    char indentString[4 * indent_level + 1];

    int i;
    for(i = 0; i < indent_level*4; ++i) {
        indentString[i] = ' ';
    }
    indentString[4 * indent_level] = '\0';

    printf("%s", indentString);
}

void toXMLString(struct twoptr *p, int indent_level) {
    if(p != NULL) {
        indent(indent_level);
        printf("%s\n", "<twoptr>");
        printf("%d\n", p->data);
        indent(indent_level+1);
        toXMLString(p->left, indent_level + 1);
        toXMLString(p->right, indent_level + 1);
        indent(indent_level);
        printf("%s\n", "</twoptr>");
    }
}

void toxml(struct twoptr *p) {
    toXMLString(p, 0);
}

void traverse(struct twoptr *root) {

    struct stack *travStack = malloc(sizeof(struct stack));
    travStack->top = -1;
    struct twoptr *curr = root;
    while(travStack->top != -1 || curr != NULL) {
        if(curr != NULL) {
            push(travStack, curr);
            curr = curr->left;
        } else {
            curr = pop(travStack);
            printf("%d\n", curr->data);
            curr = curr->right;
        }
    }
}

int main() {


    struct twoptr *testxml1= tree_create(NULL, 1, NULL);
    struct twoptr *testxml3= tree_create(NULL, 3, NULL);
    struct twoptr *testxml2= tree_create(testxml1, 2, testxml3);
    struct twoptr *testxml5= tree_create(NULL, 5, NULL);
    struct twoptr *testxml7 = tree_create(NULL, 7, NULL);
    struct twoptr *testxml6 = tree_create(testxml5, 6, testxml7);
    struct twoptr *testxml4 = tree_create(testxml2, 4, testxml6);

    toxml(testxml4);

    traverse(testxml4);

    return 0;

}
