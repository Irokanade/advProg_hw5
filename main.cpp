#include  <iostream>
#include "String.hpp"

using namespace std;

int main() {
    // String s, t("CSIE113"), u(t);
    

    String s("NTU"), t("NTNU");
    s = t;

    cout << s << endl;
    cout << t << endl;
    cout << s.size() << endl;

    cout << s[1] << endl;
    s[1] = 'B';
    cout << s[1] << endl;
    cout << s << endl;

    String s1;
    s1 = "hello";

    s.swap(s1);

    cout << s << ' ' << s1 << endl;

    s.clear();

    cout << s << endl;
    cout << s.size() << endl;

    // s = "hi";
    s = s1 + t;
    cout << s << endl;

    s = "NTNU " + s1;
    // String noStr = " 1123";
    // s += ((String("1123"))+=(s));
    s = " 1123hihihihihihihihih" + s + "4567hahahahahahahhahahahhaahhaa";
    cout << "s: " << s << endl;
    cout << s.size() << endl;
    cout << s1 << endl;

    s = "NTNU " + s1 +" hihihihihih" + s1 + s1 + s1 + s1;
    cout << s << endl;

    return 0;
}