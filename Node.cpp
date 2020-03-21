#include "Node.h"

Node :: Node(int value){
    setValue(value);
    setNext(nullptr);
}
void Node :: setValue(int value){
    this->value = value;
}
int Node :: getValue(){
    return this->value;
}
void Node :: setNext(Node *next){
    this->next = next;
}
Node* Node :: getNext(){
    return this->next;
}