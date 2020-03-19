#include <iostream>
using namespace std;

class Node{
    int value;
    Node *next;
    //Node *prev;

public: 
    Node(int value){
        this->value = value;
        this->next = NULL;
    }

    void setValue(int value){
        this->value = value;
    }
    int getValue(){
        return this->value;
    }
    void setNext(Node *next){
        this->next = next;
    }
    Node *getNext(){
        return this->next;
    }
    /*void setPrev(Node *prev){
        this->prev = prev;
    }
    Node getPrev(){
        return *prev;
    }*/
};

class MultimeDinamic{
    const Node *first = NULL;
    Node *current = NULL;

public:
    MultimeDinamic(int value){
        first = new Node(value);
        current = const_cast<Node *>(first);
    }
    MultimeDinamic(MultimeDinamic &m){
        this->first = new Node(*m.first);
        this->current = const_cast<Node *>(first);
        m.current = const_cast<Node *>(m.first);
        m.current = m.current->getNext();
        while(true){
            Node *nou = new Node(m.current->getValue());
            current->setNext(nou);
            if(m.current->getNext() == NULL)
                break;
            current = current->getNext();
            m.current = m.current->getNext();

        }
    }

    MultimeDinamic(int v[], int size){
        first = new Node(v[0]);
        addVector(v++, size--);
    }

    ~MultimeDinamic(){
        current = const_cast<Node *>(first);
        removeMultime(current);
        first = NULL;
        current = NULL;
        printMultime();
    }
    void addNode(int value){
        Node *nou = new Node(value);
        current->setNext(nou);
        current = current->getNext();

    }

    void removeMultime(Node* n){
        if(n->getNext() != NULL){
            removeMultime(n->getNext());
        }
        delete n;
    }


    void addVector(int v[], int size){
        //first = new Node(v[0]);
        current = const_cast<Node *>(first);
        for(int i = 0; i < size; i++){
            addNode(v[i]);
        }
    }

    void printMultime() {
        current = const_cast<Node *>(first);
        while(true){
            cout << current->getValue() << ' ';
            if(current->getNext() == NULL)
                break;
            current = current->getNext();
        }
        cout << endl;
    }

};

MultimeDinamic operator + (MultimeDinamic m1, MultimeDinamic m2){
    MultimeDinamic reuniune = new MultimeDinamic;
}

/*void printVector(int v[], int size){
    cout << sizeof(&v) << endl;
    for(int i = 0; ; i++){
        cout << *v << ' ';
        v++;
    }
}*/



int main() {
    int v[6] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(v)/4;

    MultimeDinamic m = MultimeDinamic(v, size);

    m.printMultime();
    m.addNode(8);
    m.printMultime();


    //printVector(v);



    return 0;
}
