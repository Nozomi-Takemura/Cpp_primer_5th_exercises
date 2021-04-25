#include<iostream>
int &get(int *arry, int index) { return arry[index]; }
int main() {
    //int ia[10]={1,2,3,4,5,6,7,8,9};
    int ia[10];
    for (auto i : ia)
      std::cout << i << " ";
    std::cout << std::endl;
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
    for (auto i : ia)
      std::cout << ia[i] << " ";
    std::cout << std::endl;
}
