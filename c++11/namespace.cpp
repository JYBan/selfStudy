/* Advanced namespace */

#include <string>
#include <iostream>

// 1. Instead of #define
namespace STATUS_OF_WORK {
    const std::string READY     ("READY");
    const std::string STARTED   ("STARTED");
    const std::string DONE      ("DONE");
}

// 2. Alias
namespace outer {
    namespace inner {
        const std::string STR ("Alias of nested namespace");
    }
}
namespace SOW = STATUS_OF_WORK;
namespace OUT_IN = outer::inner;


// 3. static class like namespace
namespace Animal {
    namespace { // This is private. It can't be reached outside of this file
        int private_var(0);
    }
    // This is public.
    int public_var(1);
    int GetPrivateVar(void) {
        return private_var;
    }
    void SetPrivateVar(int new_var);
}

// Function can be defined outside of namespace
void Animal::SetPrivateVar(int new_var) {
    private_var = new_var;
}

// 4. Inline namespace (c++11)
// 4.1 Inline namespace : Version control
namespace parent {
    namespace child_ver1 { // old one
        std::string msg("ver1");
    }
    // You can use inline namespace for version control. (Use inlined version as default)
    inline namespace child_ver2 { // default one
        // any var or func in inline namespace is considered as if it's in parent namespace
        std::string msg("ver2");
    }
    namespace child_ver3 { // new one
        std::string msg("ver3");
    }
}

// 4.2 What if there are more than one inline namespaces?
namespace parent2 {
    namespace child_ver1 {
        std::string msg("ver1");
    }
    inline namespace child_ver2 {
        std::string msg("ver2");
    }
    inline namespace child_ver3 {
        std::string msg("ver3");
    } 
}

// 4.3 Inline namespace : Packaging relative variables and functions (for readability)
namespace utility {
    inline namespace time {
        std::string PrintTime(void);
        int HourToMin(int hour);
        int MinToSec(int min);
    }
    inline namespace temperature {
        int FahrenheitToCelsius(int fahrenheit);
        int CelsiusToFahrenheit(int celsius) {
            return 33.8 * celsius;
        }
    }
}

// 5. Definitions of namespace can be scattered
namespace extended {
    int def_1(1);
}
namespace extended { // extension-namespace-definition
    int def_2(2);
}

// 6. Using namespace
// 6.1 Using namespace : using namespace in namespace
void f6(void) {
    std::cout << "function f6 is called" << std::endl; //844
}
namespace using_namespace1 {
    using ::f6;   // global f6 is now visible as ::using_namespace1::f6
    void g(void);
}
namespace using_namespace2 {
    using using_namespace1::g;   // using_namespace1:g is now visible as ::using_namespace2::g
}

// 6.2 Using namespace : overloading
namespace overloading1 {
    void f(int);
    void f(double);
}
namespace overloading2 {
    void f(int) { std::cout << "overloading2 f(int)" << std::endl; }
    void f(double) { std::cout << "overloading2 f(double)" << std::endl; }
    void f(char) { std::cout << "overloading2 f(char)" << std::endl; }
}

int main() {
    // 1.
    std::string now(STATUS_OF_WORK::READY);
    // 2.
    std::cout << OUT_IN::STR << std::endl;                      // "Alias of nested namespace"
    // 3.
    Animal::SetPrivateVar(3);
    std::cout << Animal::private_var << std::endl;              // 3    (outside of this file, it's compile error )
    std::cout << Animal::GetPrivateVar() << std::endl;          // 3
    // 4.1
    std::cout << parent::child_ver1::msg << std::endl;          // "ver1"   (specify version)
    std::cout << parent::child_ver2::msg << std::endl;          // "ver2"
    std::cout << parent::child_ver3::msg << std::endl;          // "ver3"
    std::cout << parent::msg << std::endl;                      // "ver2"   (use default version)
    // 4.2
    // std::cout << parent2::msg << std::endl;                  // Compile error. (ambiguous)
    std::cout << parent2::child_ver3::msg << std::endl;         // "ver3"
    // 4.3
    std::cout << utility::CelsiusToFahrenheit(25) << std::endl; // 844
    // 6.1
    using_namespace1::f6();                                      // "function f6 is called"
    // 6.2
    {
        using overloading1::f;     // introduces overloading1::f(int), overloading1::f(double)
        using overloading2::f;     // introduces overloading2::f(int), overloading2::f(double), and overloading2::f(char)
        f('h');                    // "overloading2 f(char)"        (calls C::f(char))
        // f(1);                   // Compile error.    (overloading1::f(int) or overloading2::f(int)?)
        // void f(int);            // Compile error.    (f(int) conflicts with overloading1::f(int) and overloading2::f(int))
    }  

}