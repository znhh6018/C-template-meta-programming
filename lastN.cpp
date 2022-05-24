#include <iostream>
#include <type_traits>
using namespace std;

template <int... N>
struct Vector;

template<typename T,size_t lastN>
struct lastNN{};

template <int first,int... remains,size_t lastN>
struct lastNN<Vector<first, remains...>,lastN>{
    constexpr static int SIZE = 1 + sizeof...(remains);
    static_assert(lastN <= SIZE);
    using type = typename conditional<lastN == SIZE,
        Vector<first,remains...>,
        lastNN<Vector<remains...>,lastN>::type
    >::type;
};

int main(){
    static_assert(is_same_v<lastNN<Vector<1,2,3,4,5>,5>::type,Vector<1,2,3,4,5>>);
}