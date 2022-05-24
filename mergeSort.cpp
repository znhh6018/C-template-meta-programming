#include <iostream>
#include <type_traits>
using namespace std;

template <int... N>
struct Vector;

// divide
template <typename T1,typename T2 = Vector<>>
struct divide{};

template <int first,int... p1,int... p2>
struct divide<Vector<first,p1...>,Vector<p2...>>{
    using type = typename conditional<(sizeof...(p1) + 1 > sizeof...(p2)),
                divide<Vector<p1...>,Vector<p2...,first>>::type,
                std::pair<Vector<first,p1...>,Vector<p2...>>
    >::type;
};

template <int... p2>
struct divide<Vector<>,Vector<p2...>>{
    using type = std::pair<Vector<>,Vector<p2...>>;
};

// merge
template <typename V1,typename V2, typename V3>
struct mergeVector{};

template <int V1First, int... V1Remains,int V2First,int... V2Remains,int... result>
struct mergeVector<Vector<V1First,V1Remains...>,Vector<V2First,V2Remains...>,Vector<result...>>{
    using type = typename conditional<V1First <= V2First,
                                      mergeVector<Vector<V1Remains...>,Vector<V2First,V2Remains...>,Vector<result..., V1First>>::type,
                                      mergeVector<Vector<V1First,V1Remains...>,Vector<V2Remains...>,Vector<result..., V2First>>::type
                            >::type;
};

template <int... V2Remains,int... result>
struct mergeVector<Vector<>,Vector<V2Remains...>,Vector<result...>>{
    using type = Vector<result...,V2Remains...>;
};

template <int... V1Remains,int... result>
struct mergeVector<Vector<V1Remains...>,Vector<>,Vector<result...>>{
    using type = Vector<result...,V1Remains...>;
};

// sort
template <typename T>
struct sort{};

template <int ...Nums>
struct sort<Vector<Nums...>>{
    using tmp = divide<Vector<Nums...>,Vector<>>::type;
    using res = mergeVector<sort< tmp::first_type>::res,sort< tmp::second_type>::res,Vector<>>::type;
};

template <int N>
struct sort<Vector<N>>{
    using res = Vector<N>;
};

template <>
struct sort<Vector<>>{
    using res = Vector<>;
};


int main(){
    static_assert(is_same_v<mergeVector<Vector<>,Vector<4,5,6,7>,Vector<>>::type,
                            Vector<4,5,6,7>
            >);
    static_assert(is_same_v<mergeVector<Vector<4,5,6,7>,Vector<1,2,3>,Vector<>>::type,
                            Vector<1,2,3,4,5,6,7>
            >);
    static_assert(is_same_v<divide<Vector<1,2>,Vector<>>::type,
                            pair<Vector<2>,Vector<1>>>);

    static_assert(is_same_v<sort<Vector<12,3,2,1,10,18>>::res,Vector<1,2,3,10,12,18>>);
    static_assert(is_same_v<sort<Vector<12>>::res,Vector<12>>);
    
    return 0;
}