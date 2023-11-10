#include<iostream>
using namespace std;
void create();
void insert();
void deletion();
void search();
void display();
int b[20], n = 0, d, e, f, i;
int main()
{
    int c;
    char g = 'y';
    do
    {
        cout << "\n Main Menu";
        cout << "\n 1.Create \n 2.Delete \n 3.Search \n 4.Insert \n 5.Display \n 6.Exit";
        cout << "\n enter your choice\n";
        cin >> c;
        switch (c)
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
            exit(0);
            break;
        default:
            cout << "The given number is not between 1-6\n";
        }
        cout << "\nDo you want to continue? (y/n)\n";
        cin >> g;

    } while (g == 'y' || g == 'Y');
    return 0;
}
void create()
{
    cout << "\n Enter the number\n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
}
void deletion()
{
    cout << "Enter the value you want to delete \n";
    cin >> d;
    for (i = 0; i < n; i++)
    {
        if (b[i] == d)
        {
            for (int j = i; j < n - 1; j++)
            {
                b[j] = b[j + 1];
            }
            n--;
            i--; 
        }
    }
}
void search()
{
    cout << "Enter the value you want to search for \n";
    cin >> e;
    for (i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            cout << "Value found at position: " << i << "\n";
        }
    }
}
void insert()
{
    cout << "Enter how many numbers you want to insert \n";
    cin >> f;
    for (i = n; i < n + f; i++)
    {
        cin >> b[i];
    }
    n += f;
}
void display()
{
    cout << "\n\n\n";
    for (i = 0; i < n; i++)
    {
        cout << "\n\n\n" << b[i];
    }
}
