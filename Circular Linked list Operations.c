#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n      ) {
	NODE first = NULL, temp, last = NULL;
int x;

for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    temp = createNodeInCLL(x);

    if(first == NULL) {
        first = temp;
        last = temp;
        last->next = first;
    } else {
        last->next = temp;
        last = temp;
        last->next = first;
    }
}
return first;
// write your code here...


}

// Traverse CLL
void traverseListInCLL(NODE first    ) {
NODE temp = first;

if(first == NULL)
    return;

do {
    printf("%d -> ", temp->data);
    temp = temp->next;
} while(temp != first);

printf("\n");
// write your code here...


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE first, int pos, int x      ) {
	NODE temp = first, newNode, prev;
int count = 1;

newNode = createNodeInCLL(x);

if(pos == 1) {
    if(first == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    while(temp->next != first)
        temp = temp->next;

    newNode->next = first;
    temp->next = newNode;
    first = newNode;
    return first;
}

prev = first;
temp = first->next;

while(temp != first && count < pos-1) {
    prev = temp;
    temp = temp->next;
    count++;
}

if(count != pos-1) {
    printf("Position not found\n");
    return first;
}

newNode->next = temp;
prev->next = newNode;

return first;
//write your code here..


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE first, int pos ) {
	NODE temp = first, prev;
int count = 1;

if(first == NULL) {
    printf("CLL is empty\n");
    return first;
}

if(pos == 1) {
    while(temp->next != first)
        temp = temp->next;

    NODE del = first;

    if(first->next == first) {
        printf("Deleted element: %d\n", del->data);
        free(del);
        return NULL;
    }

    temp->next = first->next;
    first = first->next;
    printf("Deleted element: %d\n", del->data);
    free(del);
    return first;
}

prev = first;
temp = first->next;

while(temp != first && count < pos-1) {
    prev = temp;
    temp = temp->next;
    count++;
}

if(temp == first) {
    printf("Position not found\n");
    return first;
}

prev->next = temp->next;
printf("Deleted element: %d\n", temp->data);
free(temp);

return first;
	
	
}

// Reverse CLL
NODE reverseCLL(NODE first) {
	NODE prev = NULL, curr = first, next;

if(first == NULL || first->next == first)
    return first;

do {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
} while(curr != first);

first->next = prev;
first = prev;

return first;
//write your code here...


}

// Concatenate two CLLs
NODE concatCLL(NODE first,NODE second) {
NODE temp1 = first, temp2 = second;

if(first == NULL)
    return second;

if(second == NULL)
    return first;

while(temp1->next != first)
    temp1 = temp1->next;

while(temp2->next != second)
    temp2 = temp2->next;

temp1->next = second;
temp2->next = first;

return first;
//write your code here..



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
