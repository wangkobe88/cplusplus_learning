#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int copy_string(){
    char s[] = "abcdefg";
    char b[4];
    strncpy(b, s + 2, 3);
    b[3] = '\0';
    cout << b << endl;

    string d(begin(s) + 2, begin(s) + 5);
    cout << d << endl;
}

int copy_string_memmove(){
    char a[10] = "abcdefg";
    memmove(a + 6, a + 5, strlen(a + 5) + 1);
    strncpy(a + 2, "XYZW", 4);

    char b[10] = "abcdefg";
    strncpy(b + 2, "UV", 2);
    memmove(b + 4, b + 5, strlen(b + 5) + 1);
    return 0;
}

int copy_string_replace(){
    string a = "abcdefg";
    a.replace(begin(a) + 2, begin(a) + 5, "XYZW");

    string b = "abcdefg";
    b.replace(begin(b) + 2, begin(b) + 5, "UV");
    return 0;
}

int strstr_cstring(){
    char s[] = "abcdefg";
    char* x = strstr(s, "cde"); // x == s + 2
    char* y = strstr(s, "CDE"); // y == nullptr
    return 0;
}

int find_string(){
    string s = "abcdefg";
    auto x = s.find("cde"); // x == 2
    auto y = s.find("CDE"); // y == string::npos
    return 0;
}

void replace(string& str, const string& toFind, const string& toReplace){
    while (true){
        auto pos = str.find(toFind);
        if (pos == string::npos){
            break;
        }
        str.replace(begin(str) + pos, begin(str) + pos + toFind.size(), toReplace);
    }
}

int main(){
    copy_string();
}