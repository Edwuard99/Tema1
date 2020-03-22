#include <iostream>
#include "MultimeDinamic.h"
using namespace std;

int main() {
    int v[] = {1, 2, 3, 6, 5, 4, 4, 3, 10, 11, 12, 15 ,17 ,12, 89, 90, 57, 69, 169};
    int u[] = {1, 2, 3, 3, 3, 9, 4, 10, 5, 17, 89, 89, 90, 91, 169};
    int vsize = sizeof(v)/4;
    int usize = sizeof(u)/4;

    MultimeDinamic m1 = MultimeDinamic(v, vsize);
    MultimeDinamic m2 = MultimeDinamic(u, usize);

    MultimeDinamic reunion;
    MultimeDinamic intersection;
    MultimeDinamic diferenta;
    MultimeDinamic copiere;
    MultimeDinamic copiere2;

    cout << "multimi" << endl;
    m1.printMultime();
    m2.printMultime();

    reunion = m1 + m2;
    intersection = m1 * m2;
    diferenta = m1 - m2;
    copiere = m1;
    copiere2 = MultimeDinamic(m2);

    cout << "reuniune" << endl;
    reunion.printMultime();

    cout << "intersectie" << endl;
    intersection.printMultime();

    cout << "diferenta" << endl;
    diferenta.printMultime();

    cout << "copiere" << endl;
    copiere.printMultime();

    cout << "copiere2" << endl;
    copiere2.printMultime();

    return 0;
}