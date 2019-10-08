#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//g++ -std=c++11 array_vector.cpp
//MSDN: https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?redirectedfrom=MSDN&view=vs-2019
//cppreference: https://en.cppreference.com/w/cpp/container/vector

int use_array()
{
    int a[10];
    int b[10] = {0};
    int c[] = {1, 2, 3, 4, 5};
    int x = c[2];
    c[3] = x;
    return 0;
}


int use_vector()
{
    vector<int> a(10);               // int a[10];
    vector<int> b(10, 0);            // int b[10] = {0};
    vector<int> c = {1, 2, 3, 4, 5}; // int c[] = {1, 2, 3, 4, 5};
    int x = c[2];                    // int x = c[2];
    c[3] = x;                        // c[3] = x;
    return 0;
}

int sum_array(){
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        sum += a[i];
    }
    return sum;
}

int sum_vector(){
    vector<int> a = {1, 2, 3, 4, 5};
    int sum = 0;
    for(auto x : a)
    {
        sum += x;
    }
    return sum;
}

bool find_b_in_a_array(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int* it = nullptr;
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        for (int j = 0; j < sizeof(b) / sizeof(*b); j++)
        {
            if (a[i] == b[j])
            {
                it = &a[i];
                break;
            }
        }
    }
    bool found = (it != nullptr);
    return found;
}

bool find_b_in_a_vector(){
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 4, 5, 6, 7};
    auto it = find_first_of(begin(a), end(a), begin(b), end(b));
    bool found = (it != end(a));
    return found;
}

#include <stdlib.h>

int compare(const void* x, const void* y){
    return *reinterpret_cast<const int*>(y) - *reinterpret_cast<const int*>(x);
}

int sort_array(){
    int a[] = { 2, 4, 5, 3, 1 };
    qsort(
            a,
            sizeof(a) / sizeof(*a),
            sizeof(*a),
            &compare
    );
}

int sort_vector()
{
    vector<int> a = { 2, 4, 5, 3, 1 };
    sort(
            begin(a),
            end(a),
            [](int x, int y){ return x >= y; }
    );
}

int main() {
    return 0;
}