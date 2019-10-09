#include <vector>

template<typename U>
int Count(vector<int>& numbers, U filter);

int CountGreaterThan(vector<int&> numbers, int y){
    return Count(numbers, [=](int x){ return x > y; });
}


template<typename U>
void Traverse(vector<int>& xs, U process){
    for (int x : xs){
        process(x);
    }
}

void CopyGreaterThan(vector<int>& a, vector<int>& b, int y){
    Traverse(a, [&, y](int x){
        if (x > y){
            b.push_back(x);
        }
    });
}