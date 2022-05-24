#include <iostream>
#include <type_traits>
using namespace std;

template <int... N>
struct Vector;

template <typename T,size_t pos1,size_t pos2>
struct Swap{};

template <int...Nums,size_t pos1,size_t pos2>
struct Swap<Vector<Nums...>,pos1,pos2>{
    constexpr static size_t N = sizeof...(Nums);
    static_assert(pos1 < N && pos2 < N);

};

int main(){
}