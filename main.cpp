#include  <iostream>
#include <string>
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
    char B = s[1];
    cout << B << endl;
    cout << s[1] << endl;
    cout << s << endl;
    

    char *pc = &s[0];
    *pc = '0';
    cout << *pc;
    const char *cpc = nullptr;
    cpc = &s[1];
    cout << cpc;

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

    char cStr1[128] = "Adef";
    char cStr2[128] = "adef";

    cout << strcmp(cStr1, cStr2) << endl;

    t = "1";
    cout << s1 << " < " << t << endl;
    cout << (string("NBNU") < string("1")) << endl;
    cout << (s1 < t) << endl;
    cout << (s1 < "NTNU") << endl;
    cout << ("NTNU" < s1) << endl;

    string test("hello");
    test[2] = '\0';
    cout << test << endl;
    cout << test.size() << endl;

    string test2 = "a21111111111";
    // test2[2] = '\0';
    cout << "123 > " << test2 << endl;
    cout << (string("123") > test2) << endl;

    return 0;
}