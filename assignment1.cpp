#include<iostream>
#include<string>

using namespace std;


//understanding the implementation of stack Queue and Link List
// LinkedList --> set of nodes arranged in SEQUENTIAL manner
// Stack Queue --> FILO mechanism PUSH and Pop


struct Node{
    string data;
    Node *next;
};

void FuncAdd(Node *head); //option1
void FuncDelete(Node *head); //option 2
void FuncPrint(Node *head); //option 3
void prnMenu()
{
    cout << "*******************************************" << endl
         << "1. Insert  2. Delete   3. Print List   4. Quit Exe." << endl
         << "*******************************************" << endl
         << endl
         << "Select one of the four options to continue:" << endl;
}
//quitting program to be implemented within the main function - not sure if this would give the best time complexity

int main(){
    bool flag = false;
    int choice;
    int mode;

    Node *head = new Node;
    head->next = NULL;

    cout<<"Select Data Structure (1: Stack, Other: Linked List): ";
    cin>>mode;

        if (mode == 1);
            prnMenu();

                cin >> choice;
                switch (choice) {
                    case 1:
                        FuncAdd(head);
                        break;
                    case 2:
                        FuncDelete(head);
                        break;
                    case 3:
                        FuncPrint(head);
                        break;
                    case 4:
                        flag = true;
                        break;
        }
    }



void FuncAdd(Node *head) {
    bool quit = false;
    string temp;
    Node *current;

    while (!quit) {

        cout<< "Enter Data Storage Value:  ";
        cin >> temp;

            // Allocation Node -> pointers to be referred
            current = new Node;
            current->data = temp;
            current->next = head->next;
            head->next = current;
            cout<<temp<<" has been stored into the storage" << endl;
            break;
        }
    }

void FuncDelete(Node *head){
    string deletion;
    cout << "Which value do you want to eradicate? ";
    cin >> deletion;

    Node *prev = head;
    Node *current = head->next;

    while (current)
    {
        if (current->data == deletion){
            prev->next = current->next;
            delete current;
            cout<<deletion<<"   has been successfully deleted."<<endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    if (!current) {
        cout << "That value is not in the list. Failed to eradicate " << endl;
    }}

void FuncPrint(Node *head){
    if (!head)
    {
        cout << "Nothing is in the list." << endl;
        return;
    }

    Node *current = new Node;
    current->next = head;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}