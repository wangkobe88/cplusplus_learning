

#include <iostream>
#include <functional>

using namespace std;
int main(){
    function<double(double)> inc = [](int x){ return 1 + x; };
    int(*square)(int) = [](int x){ return x * x; };
}