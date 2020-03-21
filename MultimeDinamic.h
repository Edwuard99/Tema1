#include "Node.h"

#ifndef TEMA1_MULTIMEDINAMIC_H
#define TEMA1_MULTIMEDINAMIC_H

class MultimeDinamic{
    const Node *first = nullptr;
    Node *current = nullptr;

public:
    MultimeDinamic();
    explicit MultimeDinamic(int value);
    MultimeDinamic(MultimeDinamic &m);
    MultimeDinamic(int v[], int size);
    //~MultimeDinamic();

    Node* getFirst();
    Node* getCurrent();
    void resetCurrent();
    void addNode(int value);
    int getNextValue();

    void printMultime();

private:
    static void removeMultime(Node* n);
};

#endif //TEMA1_MULTIMEDINAMIC_H
