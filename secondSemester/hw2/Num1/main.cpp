#include "listArray.h"

#include <iostream>


void testAdd() {
     cout << "test Add\n";
     List *object = new ArrayList;
     for (int i = 1; i <= 70; i++) {
         object->addValueInPos(i, 71 - i);
     }
     object->print();
     object->addValueInPos(100, 10000);
     object->print();
     delete object;
}

void testRemove() {
     cout << "test Remove" << endl;
     List *object = new ArrayList;
     for (int i = 1; i <= 70; i++) {
         object->addValueInPos(i, 71 - i);
     }
     cout << "Remove even:" << endl;
     for (int i = 2; i <= 70; i+= 2) {
         object->removeValue(71 - i);
     }
     object->print();
     cout << "Adding to end:" << endl;
     for (int i = 1; i < 20; i++) {
         object->addValueInPos((70 + i), 100);
     }
     object->print();
     cout << "Remove odd:" << endl;
     for (int i = 3; i <= 90; i+= 2) {
         object->removeValue(91 - i);
     }
     object->print();
     delete object;
}

int main(){
    testAdd();
    testRemove();
    cin.get();
return 0;
}
