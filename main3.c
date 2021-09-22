#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next; //pointing to the next node of the list
} NodeT;

NodeT *init(const int n){ //const means it never changes, init creates node and assigns it to data (assigns nodes data fields to n)
    NodeT *node = (NodeT *)malloc(sizeof(NodeT));
    node->data = n;
    node->next = NULL; //assigning data is first or last element of list
    return node; //returned the pointer, possible because of malloc
}

NodeT *destroy(NodeT *node){ //if this was longer than main then delete after every loop
    NodeT *next = node->next; //takes next and reassigns to node, free parent and return child so we never lose whats next
    free(node);
    return next;
}

void append(NodeT **head, int new_data){ //create node we are adding to the end
    NodeT *node = init(new_data);

    NodeT *last = *head; //dereference head and set to last so we dont loss head

    if(*head == NULL){ //if the first one is nothing, make it node
        *head = node;
        return; //now have single element list
    }

    while(last->next != NULL){ //if passed a vaild node, make it the next one
        last = last->next;
    }
    last->next = node; //once there are no more nodes in list, take last one and make it node
}

void print(NodeT *head){ //prints whatever the data field of the node
    NodeT *tmp = head; //make temp a copy of head so dont lose it

    while (tmp->next != NULL){
        printf("%d", tmp->data); //making whrough the list again but printing it
        tmp = tmp->next;
    }
    printf("%d", tmp->data); //last print will never actually print, this one is needed
}

int main(void) { //
    NodeT *head = init(1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    print(head);
}