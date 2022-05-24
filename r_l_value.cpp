#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <map>
#include <type_traits>
using namespace std;


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