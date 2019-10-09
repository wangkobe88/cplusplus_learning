#include <vector>

template<typename U>
int Count(vector<int>& numbers, U filter){
    int counter = 0;
    for (int x : numbers){
        if (filter(x)){
            counter++;
        }
    }
    return counter;
}

int CountOdds(vector<int>& numbers){
    return Count(numbers, [](int x){ return x % 2 == 1; });
}

int CountEvens(vector<int>& numbers){
    return Count(numbers, [](int x){ return x % 2 == 0; });
}
