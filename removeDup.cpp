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

int main(){

    return 0;
}