#include "MultimeDinamic.h"
#include <iostream>
#include <algorithm>
using namespace std;

MultimeDinamic :: MultimeDinamic() = default;
MultimeDinamic :: MultimeDinamic(int value){
    first = new Node(value);
    resetCurrent();
}
MultimeDinamic :: MultimeDinamic(MultimeDinamic &m){
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
MultimeDinamic :: MultimeDinamic(int v[], int size){
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
/*MultimeDinamic :: ~MultimeDinamic(){
    resetCurrent();
    removeMultime(current);
    first = nullptr;
    current = nullptr;
}*/

Node* MultimeDinamic :: getFirst(){
    return const_cast<Node *>(first);
}
Node* MultimeDinamic :: getCurrent(){
    return current;
}
void MultimeDinamic :: resetCurrent(){
    current = const_cast<Node *>(first);
}
void MultimeDinamic :: addNode(int value){
    Node *nou = new Node(value);
    current->setNext(nou);
    current = current->getNext();
}
int MultimeDinamic :: getNextValue(){
    int rez = current->getValue();
    current = current->getNext();
    return rez;
}

void MultimeDinamic :: printMultime() {
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

void MultimeDinamic :: removeMultime(Node* n){
    if(n->getNext() != nullptr){
        removeMultime(n->getNext());
    }
    delete n;
}
