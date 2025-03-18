#include "C.hpp"
#include "B.hpp"
#include "A.hpp"

#include <ctime>
#include <exception>

Base* generate(void)
{
    Base *a[3] = {new A(), new B(), new C()} ;
    int range = 2 - 0 + 1;
    std::srand(std::time(0) ^ std::clock());
    int num = std::rand() % range + 0;
    for (int i = 0; i <= 2; i++)
        if (i != num)
            delete a[i];
    return a[num];
}

void identify(Base *p)
{
   if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A\n";
    if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B\n";
    if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C\n";
}

void identify(Base &p)
{
   try { 
        A & a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "A\n";
   } catch (std::exception &) {}
   try {
        B & b = dynamic_cast<B &>(p);
        (void) b;
        std::cout << "B\n";
   } catch (std::exception &) {}
    try {
        C & c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "C\n";
    } catch (std::exception &) {}
}
int main()
{
    Base *b1 = generate();
    Base *b2 = generate();
    Base *b3 = generate();
    std::cout << "Pointer tests:\n";
    identify(b1);
    identify(b2); 
    identify(b3);

    std::cout << "\nReference tests:\n";
    identify(*b1);
    identify(*b2);
    identify(*b3);

    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "\nKnown type tests:\n";
    identify(a);
    identify(b);
    identify(c);

    identify(*a);
    identify(*b);
    identify(*c);

    delete b1;
    delete b2;
    delete b3;
    delete a;
    delete b;
    delete c;

    return 0;
}