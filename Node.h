#ifndef TEMA1_NODE_H
#define TEMA1_NODE_H
class Node{
    int value{};
    Node *next{};

public:
    explicit Node(int value);

    void setValue(int value);
    int getValue();
    void setNext(Node *next);
    Node *getNext();
};
#endif //TEMA1_NODE_H
