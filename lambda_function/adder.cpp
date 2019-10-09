
#include <iostream>
#include <functional>

using namespace std;

function<int(int)> Adder(int x) {
    return [=](int y){
        return x + y;
    };
}

function<int(int)> Compose(function<int(int)> f, function<int(int)> g){
    return[=](int y){ return f(g(y)); };
}

int main(){
    auto adder = Compose(Adder(1), Adder(2));
    cout << adder(3) << endl;
    return 0;
}

int main_2(){
    auto f = Adder(1);
    cout << f(2) << endl; // 输出3
    return 0;
}