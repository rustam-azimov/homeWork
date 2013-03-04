#include "listArray.h"
#include "listPointer.h"

#include <iostream>

using namespace std;

void testAdd(int typeOfList) {
     if(typeOfList == 1) {
         cout << "test Add array\n";
          List *object = new ArrayList;
          for (int i = 1; i <= 28; i++) {
              object->addValueInPos(i, 70 - i);
          }
          cout << "Addition array:" << endl;
          object->print();
          object->addValueInPos(0, 1);
          cout << "Addition to the top element with value 0:" << endl;
          object->print();
          object->addValueInPos(100, 10000);
          cout << "Addition to the end element with value 100:" << endl;
          object->print();
          delete object;
     } else {
         cout << "test Add pointer list\n";
         List *object = new ListPointer;
         for (int i = 1; i <= 28; i++) {
             object->addValueInPos(i, 15);
         }
         cout << "Addition pointer list:" << endl;
         object->print();
         object->addValueInPos(0, 1);
         cout << "Addition to the top element with value 0:" << endl;
         object->print();
         object->addValueInPos(100, 10000);
         cout << "Addition to the end element with value 100:" << endl;
         object->print();
         delete object;
     }
}

void testRemove(int typeOfList) {
    if(typeOfList == 3) {
     cout << "test Remove array" << endl;
     List *object = new ListPointer;
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
    } else {
        cout << "test Remove pointer list" << endl;
        List *object = new ListPointer;
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
}

int main(){
    int a = 1;
    while (a) {
        cout << "What you want to test?" << endl
             <<"0 - exit." << endl
            <<"1 - addition to array." << endl
           << "2 - addition to pointer list." << endl
           << "3 - removal the array." << endl
           << "4 - removal the pointer list." << endl;

        cin >> a;
        if ((a == 1)||(a == 2))
            testAdd(a);
        if ((a == 3)||(a == 4))
            testRemove(a);
    }
return 0;
}
