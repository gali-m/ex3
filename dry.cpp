#include <vector>
#include <iostream>
#include <memory>

// part a:

class BadInput : public std::exception {};

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if (start < 0 || start >= vec.size() || stop < 0 || stop > vec.size() || step <= 0)
    {
        throw BadInput();
    }

    std::vector<T> sliced = std::vector<T>();
    for (int i = start; i < stop; i += step)
    {
        sliced.push_back(vec[i]);
    }
    return sliced;
}

//part b:

class A 
{
public:
    std::vector<std::shared_ptr<int> > values;
    void add(int x)
    { 
        values.push_back(std::make_shared<int>(x)); 
    }
};


int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}