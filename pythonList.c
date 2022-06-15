#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    if(PythonListHead)
    {
        struct Node * temp = PythonListHead;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = create_node(x);
       
    }
    else
    {
        PythonListHead = malloc(sizeof(struct Node));
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int ct = 0;
    struct Node* temp = PythonListHead;
    if(ct == 0)
    {
        
        struct Node* temp = create_node(x);
        temp->next = PythonListHead;
        PythonListHead = temp;
        return;
        
    }
    struct Node* trav = PythonListHead;
    struct Node * prev = PythonListHead;
    while(ct < position)
    {
        if(trav)
        {
            prev = trav;
            trav = trav->next;
            
        }
        else
        {
            return;
        }
        ct++;
    }
    prev->next = create_node(x);
    prev = prev->next;
    prev->next = trav;
    return;
}


// Remove the item at the end of the list
void pop() {
    if(!PythonListHead)
    return;
    if(!PythonListHead->next)
    {
        delete_node(PythonListHead);
        PythonListHead = NULL;
        return;
    }
    struct Node *temp = PythonListHead;
    struct Node* prev = PythonListHead;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;   
    }
    // prev->temp->null
    free(temp);
    prev->next = NULL;
    return;

}


// Remove all items from the list
void clear() {
    struct Node *trav = PythonListHead;
    while(trav)
    {
        struct  Node*temp = trav;
        trav = trav->next;
        free(temp);
    }
    trav = NULL;
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node*temp = PythonListHead;
    int ct = 0;
    while(temp)
    {
        ct += temp->data == x;
        temp = temp->next;
    }

    return ct;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node * head = PythonListHead;
    while(PythonListHead->next)
    {
        struct Node*temp = PythonListHead->next;
        temp->next = head;
        head = temp;
        PythonListHead = PythonListHead->next;
    }
    PythonListHead = head;
    return;
}


// Return the number of elements in the list
int len() {
    // your code goes here
    int ct = 0;
    struct Node *temp = PythonListHead;
    while(temp)
    {
        temp =temp->next;
        ct++;
    }
    return ct;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    int ct = 0;
    struct Node * temp = PythonListHead;
    while(ct<position)
    {
        ct++;
        if(!temp)
        return;
        temp = temp->next;
    }
    if(!temp)
    return;
    temp->data = x;
    return;
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    int ct = 0;
    struct Node * temp = PythonListHead;
    while(ct < position)
    {
        if(!temp)
        return - 1;
        temp = temp->next;
        ct++;
    }
    if(!temp)
    return -1;
    return temp->data;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    if(position == 0)
    {
        if(PythonListHead)
        {
            struct Node * temp = PythonListHead;
            PythonListHead = PythonListHead->next;
            free(temp);
        }
        return;
    }
    struct Node * temp = PythonListHead;
    struct Node * prev = PythonListHead;
    int ct = 0;
    while(ct < position)
    {
        if(!temp)
        return;
        prev= temp;
        temp = temp->next;
        ct++;
    }
    if(!temp)
    return;
    prev->next= temp->next;
    free(temp);
    return;
}


// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
    // your code goes here
    return NULL;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {}


// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}