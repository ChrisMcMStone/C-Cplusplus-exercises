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

void pop(struct stack *curr) {

    if(curr->top == -1) {
        printf("Stack empty");
    } else {
        curr->top--;
    }
}

struct twoptr *top(struct stack *curr) {

    return curr->elements[curr->top];

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
        toXMLString(p->left, indent_level + 1);
        indent(indent_level+1);
        printf("%d\n", p->data);
        toXMLString(p->right, indent_level + 1);
        indent(indent_level);
        printf("%s\n", "</twoptr>");
    }
}

void toxml(struct twoptr *p) {
    toXMLString(p, 0);
}




void traverse(struct twoptr *curr) {

    struct stack *travStack = malloc(sizeof(struct stack));
    push(travStack, curr);
    while(travStack->top != 0) {
        if(top(travStack)->left != NULL) {
            push(travStack, top(travStack)->left);
        } else {
            printf("%d\n", top(travStack)->data);
        if(top(travStack)->right != NULL) {
            pop(travStack);
            push(travStack, top(travStack)->right);
        } else {
            pop(travStack);
        }
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

    //toxml(testxml4);

    traverse(testxml4);

    return 0;

}
