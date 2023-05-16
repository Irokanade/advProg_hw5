#include  <iostream>
#include "String.hpp"

using namespace std;

int main() {
    String myString("test1");
    String myString2;
    String myString3;

    char cStr1[12] = "helloo";

    myString3 = cStr1;

    myString2 = " michelle is the 2nd best ";

    cout << myString << endl;

    myString = "test2";

    cout << myString << " test test " << endl;

    // myString += " michelle is the best ";

    (myString = myString2)+=myString;

    cout << "front: " << myString << endl;

    cout << "[] operator: " << myString2[1] << endl;

    myString3 += " guys!";

    cout << "myString3: " << myString3 << endl;

    String myString4(myString2);

    cout << "myString4: " << myString2 << "." << endl;

    cout << "string size(): " << myString4.size() << endl;

    return 0;
}