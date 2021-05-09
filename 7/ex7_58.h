#include<vector>
class Example {
public:
    static constexpr double rate = 6.5; //should be static double rate; 
    static  constexpr int vecSize = 20; // should be static constexpr int vecSize = 20;
    std::vector<double> vec{20};
    static const int arr[vecSize];
};
