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

// define uniq with one parameter (intended as a Vector)
template <typename input,typename output = Vector<>> struct uniq;
// use partial specialisation matching for when the first two elements
// are the same
template <int First, int... Remaining,int ...result>
struct uniq<Vector<First, First, Remaining...>,Vector<result...>>{
    using type = typename uniq<Vector<First,Remaining...>,Vector<result...>>::type ;
};
// use partial specialisation matching for when the first two elements
// are not the same
template <int First, int... Remaining,int ...result>
struct uniq<Vector<First, Remaining...>,Vector<result...>>{
    using type = typename uniq<Vector<Remaining...>,Vector<result...,First>>::type ;
};
// support matching of special case when the Vector is empty
template <int ...result>
struct uniq<Vector<>,Vector<result...>>{
    using type = Vector<result...>;
};

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

void func(int & a){
    cout << 1 << endl;
}
void func(int && a){
    cout << 2 << endl;
}

template <typename T>
void test(T&& t){
    func(t);
    func(std::forward<T>(t));
}

int main(){

    return 0;
}