#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    int value{};
    Node *next{};

public: 
    explicit Node(int value){
        setValue(value);
        setNext(nullptr);
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
};

class MultimeDinamic{
    const Node *first = nullptr;
    Node *current = nullptr;

public:
    MultimeDinamic(){}
    MultimeDinamic(int value){
        first = new Node(value);
        resetCurrent();
    }

    MultimeDinamic(MultimeDinamic &m){
        this->first = new Node(*m.first);
        resetCurrent();
        m.current = const_cast<Node *>(m.first);
        m.current = m.current->getNext();
        while(true){
            Node *nou = new Node(m.current->getValue());
            current->setNext(nou);
            if(m.current->getNext() == nullptr)
                break;
            current = current->getNext();
            m.current = m.current->getNext();
        }
        resetCurrent();
    }

    MultimeDinamic(int v[], int size){
        resetCurrent();
        sort(v, v+size);
        int last = v[0];
        first = new Node(v[0]);
        current = const_cast<Node *>(first);
        for(int i = 1; i < size; i++){
            if(v[i] != last)
                addNode(v[i]);
            last = v[i];
        }
        resetCurrent();
    }

    ~MultimeDinamic(){
        resetCurrent();
        removeMultime(current);
        first = nullptr;
        current = nullptr;
        //printMultime();
    }

    void resetCurrent(){
        current = const_cast<Node *>(first);
    }

    int getCurrentValue(){
        int rez = current->getValue();
        current = current->getNext();
        return rez;
    }
    void addNode(int value){
        Node *nou = new Node(value);
        current->setNext(nou);
        current = current->getNext();
    }

    Node* getFirst(){
        return const_cast<Node *>(first);
    }

    Node* getCurrent(){
        return current;
    }

    void printMultime() {
        resetCurrent();
        while(true){
            cout << current->getValue() << ' ';
            if(current->getNext() == nullptr)
                break;
            current = current->getNext();
        }
        cout << endl;
        resetCurrent();
    }


private:

    static void removeMultime(Node* n){
        if(n->getNext() != nullptr){
            removeMultime(n->getNext());
        }
        delete n;
    }
};



/*void printVector(int v[], int size){
    cout << sizeof(&v) << endl;
    for(int i = 0; ; i++){
        cout << *v << ' ';
        v++;
    }
}*/

MultimeDinamic* reuniune (MultimeDinamic m1, MultimeDinamic m2){
    int last;
    int x1, x2;
    MultimeDinamic *reuniune;
    x1 = m1.getFirst()->getValue();
    x2 = m2.getFirst()->getValue();
    if (x1 < x2){
        last = x1;
        reuniune = new MultimeDinamic(last);
    }
    else{
        last = x2;
        reuniune = new MultimeDinamic(last);
    }

    while((m1.getCurrent() != nullptr) || (m2.getCurrent() != nullptr)){
        if(x1 == last && m1.getCurrent())
            x1 = m1.getCurrentValue();
        if(x2 == last && m2.getCurrent())
            x2 = m2.getCurrentValue();
        if(x1 != last && x2 != last){
            if(x1 <= x2 && m1.getCurrent()){
                reuniune->addNode(x1);
                last = x1;
                x1 = m1.getCurrentValue();
            }
            else if(m2.getCurrent()){
                reuniune->addNode(x2);
                last = x2;
                x2 = m2.getCurrentValue();

            }
        }
    }

    if(x1 < x2){
        if(x1 != last)
            reuniune->addNode(x1);
        reuniune->addNode(x2);
    }
    else if(x1 > x2){
        if(x2 != last)
            reuniune->addNode(x2);
        reuniune->addNode(x1);
    } else if(x1 != last){
        reuniune->addNode(x1);
    }

    return reuniune;
}

MultimeDinamic* intersectie(MultimeDinamic m1, MultimeDinamic m2){
    bool initialized = false;
    int x1, x2;
    MultimeDinamic *intersectie;
    x1 = m1.getCurrentValue();
    x2 = m2.getCurrentValue();

    while((m1.getCurrent() != nullptr ) && (m2.getCurrent() != nullptr)){
        if(x1 == x2){
            if(initialized == false) {
                intersectie = new MultimeDinamic(x1);
                initialized = true;
            }
            else {
                intersectie->addNode(x1);
            }
            x1 = m1.getCurrentValue();
            x2 = m2.getCurrentValue();
        }
        if(x1 < x2){
            x1 = m1.getCurrentValue();
        }
        if(x1 > x2){
            x2 = m2.getCurrentValue();
        }
    }
    if(x1 == x2)
        intersectie->addNode(x1);

    return intersectie;
}




/*MultimeDinamic operator + (MultimeDinamic m1, MultimeDinamic m2){
    int last;
    int x1, x2;
    MultimeDinamic *reuniune;
    if (m1.getFirst()->getValue() < m2.getFirst()->getValue()){
        last = m1.getFirst()->getValue();
        reuniune = new MultimeDinamic(last);
    }
    else{
        last = m2.getFirst()->getValue();
        reuniune = new MultimeDinamic(last);
    }

    while((m1.getCurrent()->getNext() != nullptr) && (m2.getCurrent()->getNext() != nullptr)){
        if(x1 == last)
            x1 = m1.getCurrentValue();
        if(x2 == last)
            x2 = m2.getCurrentValue();
        if(x1 != last && x2 != last){
            if(x1 <= x2){
                reuniune->addNode(x1);
                last = x1;
                x1 = m1.getCurrentValue();
            }
            else{
                reuniune->addNode(x2);
                last = x2;
                x2 = m2.getCurrentValue();
            }
        }
    }

    return *reuniune;
}*/


int main() {
    int v[] = {1, 2, 3, 6, 5, 4, 4, 3, 10, 11, 12, 15 ,17 ,12, 89};
    int u[] = {2, 3, 3, 3, 9, 4, 10, 5, 17, 89, 89};
    int vsize = sizeof(v)/4;
    int usize = sizeof(u)/4;

    MultimeDinamic *m1 = new MultimeDinamic(v, vsize);
    MultimeDinamic *m2 = new MultimeDinamic(u, usize);

    MultimeDinamic *reunion = new MultimeDinamic();
    MultimeDinamic *intersection = new MultimeDinamic();

    reunion = reuniune(*m1, *m2);
    intersection = intersectie(*m1, *m2);

    cout << "multimi" << endl;
    m1->printMultime();
    m2->printMultime();

    cout << "reuniune" << endl;
    reunion->printMultime();

    cout << "intersectie" << endl;
    intersection->printMultime();






    //printVector(v);

    return 0;
}
