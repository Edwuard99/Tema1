#include <iostream>
#include "MultimeDinamic.h"
using namespace std;

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

int main() {
    int v[] = {1, 2, 3, 6, 5, 4, 4, 3, 10, 11, 12, 15 ,17 ,12, 89, 90, 57, 69, 169};
    int u[] = {1, 2, 3, 3, 3, 9, 4, 10, 5, 17, 89, 89, 90, 91};
    int vsize = sizeof(v)/4;
    int usize = sizeof(u)/4;

    MultimeDinamic m1 =  MultimeDinamic(v, vsize);
    MultimeDinamic m2 =  MultimeDinamic(u, usize);

    MultimeDinamic reunion;
    MultimeDinamic intersection;
    MultimeDinamic diferenta;
    MultimeDinamic copiere;

    reunion = m1 + m2;
    intersection = m1 * m2;
    diferenta = m1 - m2;
    copiere = MultimeDinamic(m1);

    cout << "multimi" << endl;
    m1.printMultime();
    m2.printMultime();

    cout << "reuniune" << endl;
    reunion.printMultime();

    cout << "intersectie" << endl;
    intersection.printMultime();

    cout << "diferenta" << endl;
    diferenta.printMultime();

    cout << "copiere" << endl;
    copiere.printMultime();

    return 0;
}
