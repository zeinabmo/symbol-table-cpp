
#include <iostream>
#include <string>
using namespace std;

const int tablesize = 3;
// یک ساختار به نام node
struct node
{
    string name;
    string type;
    node *next;
};

// ساخت ارایه hashtable، که اشاره گر به سه ادرس هست neme, type, next
node *hashtable[tablesize] = {nullptr, nullptr, nullptr};

// تابع هش که هش هر اسم رو برمیگردونه
int hashfunction(string name)
{
    return name.length() % tablesize;
}

// تابع
node *searchoneline(node *current, string name)
{
    while (current != nullptr)
    {
        if (current->name == name)
            return current;
        current = current->next;
    }
    return nullptr;
}

node *lookup(string name)
{
    return searchoneline(hashtable[hashfunction(name)], name);
}

bool insert(string name, string type)
{
    if (lookup(name) != nullptr)
        return false;

    int index = hashfunction(name);
    node *newnode = new node{name, type, hashtable[index]};
    hashtable[index] = newnode;
    return true;
}

node *deleteentry(string name)
{
    int index = hashfunction(name);
    node *current = hashtable[index];
    node *previous = nullptr;

    while (current != nullptr && current->name != name)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
        return nullptr;

    if (previous == nullptr)
        hashtable[index] = current->next;
    else
        previous->next = current->next;

    current->next = nullptr;
    return current;
}

void display()
{
    for (int i = 0; i < tablesize; i++)
    {
        cout << "Bucket " << i << ": ";
        node *current = hashtable[i];

        if (current == nullptr)
            cout << "Empty";

        while (current != nullptr)
        {
            cout << current->name << " (" << current->type << ")";
            current = current->next;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << '\n';
    }
}

void clearTable()
{
    for (int i = 0; i < tablesize; i++)
    {
        node *current = hashtable[i];
        while (current != nullptr)
        {
            node *temp = current;
            current = current->next;
            delete temp;
        }
        hashtable[i] = nullptr;
    }
}

void menu()
{
    cout << "\n===== SYMBOL TABLE =====\n"
         << "1. Insert\n2. Lookup\n"
         << "3. Delete\n4. Display\n0. Exit\n"
         << "Choose an operation: ";
}

int main()
{
    int choice = -1;
    string name, type;

    do
    {
        menu();

        if (!(cin >> choice))
        {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter type : ";
            cin >> type;
            cout << (insert(name, type) ? "Inserted successfully.\n" : "Variable already exists.\n");
            break;

        case 2:
        {
            cout << "Enter name: ";
            cin >> name;
            node *result = lookup(name);
            if (result != nullptr)
                cout << result->name << " : " << result->type << '\n';
            else
                cout << "Variable not found.\n";
            break;
        }

        case 3:
        {
            cout << "Enter name: ";
            cin >> name;
            node *removed = deleteentry(name);
            if (removed != nullptr)
            {
                cout << "Deleted: " << removed->name << '\n';
                delete removed;
            }
            else
            {
                cout << "Variable not found.\n";
            }
            break;
        }

        case 4:
            display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Choose a number from 0 to 4.\n";
        }
    } while (choice != 0);

    clearTable();
    return 0;
}
