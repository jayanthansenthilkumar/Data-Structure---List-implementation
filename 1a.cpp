#include <iostream>
using namespace std;

void create();
void insert();
void deletion();
void search();
void display();
int b[20], n = 0;  // Fixed-size array to hold elements
int main()
{
    int choice;
    char continueProgram = 'y';

    do
    {
        cout << "\n===== Main Menu =====";
        cout << "\n1. Create";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Insert";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);  // Terminates the program
            break;
        default:
            cout << "Invalid choice! Please select a valid option (1-6).\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueProgram;

    } while (continueProgram == 'y' || continueProgram == 'Y');

    return 0;
}

void create()
{
    cout << "\nEnter the number of elements: ";
    cin >> n;

    if (n > 20) {  // Limiting input size to prevent overflow
        cout << "Exceeded maximum array size (20)! Try again.\n";
        return;
    }

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << "Array created successfully!\n";
}

void deletion()
{
    if (n == 0) {
        cout << "Array is empty! No elements to delete.\n";
        return;
    }

    int valueToDelete;
    cout << "Enter the value you want to delete: ";
    cin >> valueToDelete;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == valueToDelete)
        {
            found = true;
            for (int j = i; j < n - 1; j++)  // Shifting elements
            {
                b[j] = b[j + 1];
            }
            n--;  // Reduce array size
            i--;  // Re-adjust the index since elements are shifted
            cout << "Value " << valueToDelete << " deleted successfully!\n";
        }
    }

    if (!found)
        cout << "Value not found!\n";
}

void search()
{
    if (n == 0) {
        cout << "Array is empty! No elements to search.\n";
        return;
    }

    int valueToSearch;
    cout << "Enter the value you want to search for: ";
    cin >> valueToSearch;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == valueToSearch)
        {
            cout << "Value found at index: " << i << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "Value not found!\n";
}

void insert()
{
    if (n >= 20) {
        cout << "Array is full! Cannot insert more elements.\n";
        return;
    }

    int numToInsert;
    cout << "Enter the number of elements you want to insert: ";
    cin >> numToInsert;

    if (n + numToInsert > 20) {
        cout << "Cannot insert. The array size will exceed 20.\n";
        return;
    }

    cout << "Enter the elements to insert:\n";
    for (int i = n; i < n + numToInsert; i++)
    {
        cin >> b[i];
    }

    n += numToInsert;
    cout << numToInsert << " elements inserted successfully!\n";
}

void display()
{
    if (n == 0) {
        cout << "Array is empty! No elements to display.\n";
        return;
    }

    cout << "\nArray elements are:\n";
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}
