#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node * next;

        Node() {
            data = 0;
            next = 0;
        }

        Node(int val,Node * ptr=0) {
            data = val;
            next = ptr;
        }
};

class linkedList {
    Node * head,* tail;
    public:
        linkedList()
        {
            head = tail = 0;
        }

        void insert_at_head(int data) {
            head = new Node (data,head);
            if(tail == 0) {
                tail = head;
            }
        }

        void insert_at_tail(int data) {
            if(tail == 0) {
                tail->next = new Node(data,tail);
                head = tail;
            }
            else {
                tail->next = new Node(data);
                tail = tail->next;
           }
        }

        void delete_at_head(int data) {
            if(head == tail)
            {
                delete head;
                head = tail = 0;
            }
            else {
                Node * temp;
                temp =  head;
                delete head;
                head = head->next;
            }
        }
 
        void delete_at_tail(int data) {
            if(head == tail) {
                delete tail;
                head = tail = 0;
            }
            else {
                Node * temp;
                temp = head;
                if(temp->next != tail) {
                    temp = temp->next;
                }
                delete temp->next;
                tail = temp;
            }
        }
        void search(int key){
            Node * temp = head;
            while(temp != 0){
                if(temp->data == key){
                    cout << "Search key is:"<< key << "\n";
                    return;
                    }
                else{
                    temp = temp->next;
                    }
                }
            }

        void printlist()
        {
            Node *temp = head;
            while (temp != 0)
            {
                cout << temp->data << "--->";
                temp = temp->next;
            }
        }
};

int main() {
    linkedList l1;
    l1.insert_at_head(5);
    l1.insert_at_head(3);
    l1.insert_at_tail(8);
    l1.delete_at_tail(8);
    l1.search(5);
    l1.printlist();
    cout<< "\n";
    return 0;
}

