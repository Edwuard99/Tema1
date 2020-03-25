#include <iostream>
#include <algorithm>
#include "MultimeDinamic.h"

MultimeDinamic :: MultimeDinamic() = default;
MultimeDinamic :: MultimeDinamic(int value){
    first = new Node(value);
    resetCurrent();
}
MultimeDinamic :: MultimeDinamic(MultimeDinamic &m){
    this->first = new Node(*m.first);
    this->resetCurrent();
    m.resetCurrent();
    m.getNextValue();
    while (m.getCurrent()) {
        this->addNode(m.getNextValue());
    }
    m.resetCurrent();
    this->resetCurrent();
}
MultimeDinamic :: MultimeDinamic(int v[], int size){
    resetCurrent();
    std :: sort(v, v+size);
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
MultimeDinamic :: ~MultimeDinamic(){
    resetCurrent();
    removeMultime(current);
    first = nullptr;
    current = nullptr;
}

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

MultimeDinamic& MultimeDinamic :: operator = (MultimeDinamic m) {
    this->first = new Node(*m.first);
    this->resetCurrent();
    m.resetCurrent();
    m.getNextValue();
    while (m.getCurrent()) {
            this->addNode(m.getNextValue());
    }
    m.resetCurrent();
    this->resetCurrent();
    return *this;
}

void MultimeDinamic :: printMultime() {
    resetCurrent();
    while(true){
        std :: cout << current->getValue() << ' ';
        if(current->getNext() == nullptr)
            break;
        current = current->getNext();
    }
    std :: cout << std :: endl;
    resetCurrent();
}

void MultimeDinamic :: removeMultime(Node* n){
    if(n->getNext() != nullptr){
        removeMultime(n->getNext());
    }
    delete n;
}

MultimeDinamic operator + (MultimeDinamic m1, MultimeDinamic m2){
    int last;
    int x1, x2;
    MultimeDinamic reuniune;
    x1 = m1.getFirst()->getValue();
    x2 = m2.getFirst()->getValue();
    if (x1 < x2){
        last = x1;
        reuniune = MultimeDinamic(last);
    }
    else{
        last = x2;
        reuniune = MultimeDinamic(last);
    }

    while((m1.getCurrent() != nullptr) || (m2.getCurrent() != nullptr)){
        if(x1 == last && m1.getCurrent())
            x1 = m1.getNextValue();
        if(x2 == last && m2.getCurrent())
            x2 = m2.getNextValue();
        if(x1 != last && x2 != last){
            if(x1 <= x2 && m1.getCurrent()){
                reuniune.addNode(x1);
                last = x1;
                x1 = m1.getNextValue();
            }
            else if(m2.getCurrent()){
                reuniune.addNode(x2);
                last = x2;
                x2 = m2.getNextValue();

            }
        }
    }

    if(x1 < x2){
        if(x1 != last)
            reuniune.addNode(x1);
        reuniune.addNode(x2);
    }
    else if(x1 > x2){
        if(x2 != last)
            reuniune.addNode(x2);
        reuniune.addNode(x1);
    } else if(x1 != last){
        reuniune.addNode(x1);
    }

    reuniune.resetCurrent();
    return reuniune;
}

MultimeDinamic operator * (MultimeDinamic m1, MultimeDinamic m2){
    bool initialized = false;
    int x1, x2;
    MultimeDinamic intersectie;
    x1 = m1.getNextValue();
    x2 = m2.getNextValue();

    while((m1.getCurrent() != nullptr ) && (m2.getCurrent() != nullptr)){
        if(x1 == x2){
            if(!initialized) {
                intersectie = MultimeDinamic(x1);
                initialized = true;
            }
            else {
                intersectie.addNode(x1);
            }
            x1 = m1.getNextValue();
            x2 = m2.getNextValue();
        }
        else if(x1 < x2){
            x1 = m1.getNextValue();
        }
        else if(x1 > x2){
            x2 = m2.getNextValue();
        }
    }
    if(m1.getCurrent())
        x1 = m1.getNextValue();
    if(m2.getCurrent())
        x2 = m2.getNextValue();

    if(x1 == x2)
        intersectie.addNode(x1);

    intersectie.resetCurrent();
    return intersectie;
}

MultimeDinamic operator - (MultimeDinamic m1, MultimeDinamic m2){
    bool initialized = false;
    int x1, x2;
    MultimeDinamic diferenta;
    MultimeDinamic multime = m1;
    MultimeDinamic intersectie = m1 * m2;
    x1 = multime.getNextValue();
    x2 = intersectie.getNextValue();

    while(multime.getCurrent() != nullptr){
        if(x1 == x2){
            x1 = multime.getNextValue();
            if(intersectie.getCurrent())
                x2 = intersectie.getNextValue();
        }
        if(x1 < x2){
            if(!initialized){
                diferenta = MultimeDinamic(x1);
                initialized = true;
            }
            else{
                diferenta.addNode(x1);
            }
            x1 = multime.getNextValue();
        }
        if(x1 > x2){
            if(!initialized){
                diferenta = MultimeDinamic(x2);
                initialized = true;
            }
            else{
                if(intersectie.getCurrent())
                    diferenta.addNode(x2);
                else
                    diferenta.addNode(x1);
            }
            if(intersectie.getCurrent())
                x2 = intersectie.getNextValue();
        }
    }

    diferenta.resetCurrent();
    return diferenta;
}
