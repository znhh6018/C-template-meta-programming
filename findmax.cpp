#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <map>
#include <type_traits>
using namespace std;

template <int... N>
struct Vector;

template<typename T>
struct findMax{};

template<int first,int... remains>
struct findMax<Vector<first,remains...>>{
    constexpr static int val = max(first,findMax<Vector<remains...>>::val);
};

template<int lastone>
struct findMax<Vector<lastone>>{
    constexpr static int val = lastone;
};

int main(){

    return 0;
}