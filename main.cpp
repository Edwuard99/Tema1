#include <iostream>
using namespace std;

class Nod{
    int value;
    Nod *next;
    //Nod *prev;

public: 
    Nod(int value){
        this->value = value;
        this->next = NULL;
    }

    void setValue(int value){
        this->value = value;
    }
    int getValue(){
        return this->value;
    }
    void setNext(Nod *next){
        this->next = next;
    }
    Nod *getNext(){
        return this->next;
    }
    /*void setPrev(Nod *prev){
        this->prev = prev;
    }
    Nod getPrev(){
        return *prev;
    }*/
};

class MultimeDinamic{
    Nod *first = NULL;
    Nod *current = NULL;

public:

    MultimeDinamic(int v[], int size){
        first = new Nod(v[0]);
        current = first;
        Nod *nou = NULL;
        for(int i = 1; i < size; i++){
            nou = new Nod(v[i]);
            current->setNext(nou);
            current = nou;
        }
    }

    void printMultime() {
        current = first;
        while(true){
            cout << current->getValue() << ' ';
            if(current->getNext() == NULL)
                break;
            current = current->getNext();
        }
    }


};

/*void printVector(int v[], int size){
    cout << sizeof(&v) << endl;
    for(int i = 0; i <= sizeof(v)/4; i++){
        cout << v[i] << ' ';
    }
}*/



int main() {
    /*Nod n1 = Nod(1);
    Nod n2 = Nod(2);
    Nod n3 = Nod(3);
    Nod n4 = Nod(4);
    Nod n5 = Nod(5);
    Nod n6 = Nod(6);

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);


    Nod current = n1;
    while(true){
        cout << current.getValue() << ' ';
        if(current.getNext() == NULL)
            break;
        current = *current.getNext();

    }*/

    int v[6] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(v)/4;

    MultimeDinamic m = MultimeDinamic(v, size);
    m.printMultime();


    //printVector(v);



    return 0;
}
