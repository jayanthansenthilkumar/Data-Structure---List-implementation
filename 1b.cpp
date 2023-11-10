#include <iostream>
#include <cstdlib>
using namespace std;
struct node 
{
    int element;
    struct node*next;
}*list=NULL,*p;
struct node* find(int);
struct node* findprevious(int);
void insert(int X);
void deletion(int X);
void display();
int main() 
{
    int data, ch;
    cout << "1.Insert\n2.Deletion\n3.Display\n4.Exit";
    do 
	{
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) 
		{
        case 1:
            cout << "Enter the element to insert: ";
            cin >> data;
            insert(data);
            break;
        case 2:
            cout << "Enter the element to delete: ";
            cin >> data;
            deletion(data);
            break;
        case 3:
        	cout<<"Entered Elements : ";
			display();
            break;
        case 4:
        	cout << "Exiting Successfully";
            exit(0);
        }
    } while (ch < 4);
    return 0;
}
void insert(int X) 
{
    struct node* newnode;
    int pos;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->element = X;
    if (list == NULL) 
	{
        list = newnode;
        newnode->next = NULL;
    }
    else 
	{
        cout << "\nEnter the value after which the element to be inserted: ";
        cin >> pos;
        p = find(pos);
        newnode->next = p->next;
        p->next = newnode;
    }
}
struct node* find(int s) 
{
    p = list;
    while (p != NULL && p->element != s)
        p = p->next;
    return p;
}
void deletion(int X) 
{
    struct node* temp;
    p = findprevious(X);
    if (p->next != NULL) 
	{
        temp = p->next;
        p->next = temp->next;
        cout << "\nThe deleted element is: " << temp->element;
        free(temp);
    }
    else
        cout << "\nElement not found in the list";
}
struct node* findprevious(int s) 
{
    p = list;
    while (p->next != NULL && p->next->element != s)
        p = p->next;
    return p;
}
void display() 
{
    if (list == NULL)
        cout << "List is empty";
    else {
        p = list;
        cout << "\nThe contents of the list are:\n";
        while (p != NULL) {
            cout << p->element << " ";
            p = p->next;
        }
    }
}
