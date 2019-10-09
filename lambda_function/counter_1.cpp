#include <vector>

int Count(vector<int>& numbers, bool(*filter)(int)) {
    int counter = 0;
    for (int x : numbers){
        if (filter(x)){
            counter++;
        }
    }
    return counter;
}

bool Odd(int x){
    return x % 2 == 1;
}

bool Even(int x){
    return x % 2 == 0;
}

int CountOdds(vector<int>& numbers){
    return Count(numbers, &Odd);
}

int CountEvens(vector<int>& numbers){
    return Count(numbers, &Even);
}