#include <vector>

int Count(vector<int>& numbers, bool(*filter)(int, void*), void* context){
    int counter = 0;
    for (int x : numbers){
        if (filter(x, context)){
            counter++;
        }
    }
    return counter;
}

bool GreaterThan(int x, void* context){
    return x > *reinterpret_cast<int*>(context);
}

int CountGreaterThan(vector<int>& numbers, int y){
    return Count(numbers, &GreaterThan, &y);
}

bool Odd(int x, void*){
    return x % 2 == 1;
}

bool Even(int x, void*){
    return x % 2 == 0;
}

int CountOdds(vector<int>& numbers){
    return Count(numbers, &Odd, nullptr);
}

int CountEvens(vector<int>& numbers){
    return Count(numbers, &Even, nullptr);
}