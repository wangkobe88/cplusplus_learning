#include <iostream>
#include <string>
#include <regex>

using namespace std;
//https://docs.microsoft.com/en-us/cpp/standard-library/regex-typedefs?view=vs-2017&redirectedfrom=MSDN
//https://docs.microsoft.com/en-us/cpp/standard-library/regular-expressions-cpp?redirectedfrom=MSDN&view=vs-2019
//
int main() {
    string line;
    regex email(R"(\w+@(\w+\.)+\w+)");
    while (getline(cin, line)) {
        smatch matches;
        auto current = cbegin(line);
        auto last = cend(line);
        while(current != last) {
            if(regex_search(current, last, matches, email)){
                ssub_match match = matches[0];
                current = match.second;
                cout << match.str() << endl;
            } else {
                break;
            }
        }
    }
    return 0;
}