
#include <iostream>
#include <functional>

using namespace std;

int main()
{
    //fib变量的类型auto需要通过编译确定，但是需要捕获自己，所以需要明确给一个类型
    function<int(int)> fib = [&fib](int i) -> int {
        if(i<2){
            return 1;
        } else {
            return fib(i-1) + fib(i-2);
        }
    };
    /*请在这里补充lambda表达式*/
    for (int i = 0; i < 10; i++)
    {
        cout << fib(i) << endl;
    }
    return 0;
}
