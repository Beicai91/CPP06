#include <cstdlib>
#include <iostream>
#include <exception>

class Base
{
    public:
        virtual ~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base    *generate(void)
{
    std::srand(std::time(0)); //seed the Random Number Generator with current time so that rand() will not produce the same sequence of numbers every time we run the program
    Base    *objs[] = {new A, new B, new C};
    int random_num = std::rand() % 3;
    for (int i = 0; i < 3; ++i)
    {
        if (i != random_num)
            delete objs[i];
    }
    return (objs[random_num]);
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The actual type of p is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The actual type of p is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The actual type of p is C" << std::endl;
    else
        std::cout << "p points to an unknown type" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        A   &refA = dynamic_cast<A&>(p);
        (void)refA;
        std::cout << "The actual type of p is A" << std::endl;
    }
    catch (const std::exception &)
    {}

    try
    {
        B   &refB = dynamic_cast<B&>(p);
        (void)refB;
        std::cout << "The actual type of p is B" << std::endl;
    }
    catch (const std::exception &)
    {}

    try
    {
        C   &refC = dynamic_cast<C&>(p);
        (void)refC;
        std::cout << "The actual type of p is C" << std::endl;
    }
    catch (const std::exception &)
    {}
}

int main(void)
{
    Base    *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return (0); 
}