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
    ~MultimeDinamic();

    Node* getFirst();
    Node* getCurrent();
    void resetCurrent();
    void addNode(int value);
    int getNextValue();

    MultimeDinamic& operator = (MultimeDinamic m);

    void printMultime();

private:
    void removeMultime(Node* n);
};

MultimeDinamic operator + (MultimeDinamic m1, MultimeDinamic m2);
MultimeDinamic operator * (MultimeDinamic m1, MultimeDinamic m2);
MultimeDinamic operator - (MultimeDinamic m1, MultimeDinamic m2);

#endif //TEMA1_MULTIMEDINAMIC_H
