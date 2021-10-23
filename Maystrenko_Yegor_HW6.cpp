#include <iostream>
#include <optional>
#include <vector>
#include <chrono>
#include <thread>
#include <string>

constexpr int kErrorExit{-1};
constexpr int kSuccessExit{0};

class stack
{
public:
    void capacity() const;
    bool print() const;
    bool add();
    bool delate();

private:
    std::vector<int> buff{};
    int top{0};
};

void stack::capacity() const
{
    std::cout << " Size of stack is:" << top << std::endl;
}

bool stack::print() const
{
    if (top == 0)
    {
        std::cout << " Stack is empty " << std::endl;
        return false;
    }
    else
    {
        std::cout << " Stack elements are: " << std::endl;
        for (int it : buff)
        {
            std::cout << ' ' << it;
        }
        std::cout << "\n";
    }
    return true;
}

bool stack::add()
{
    std::cout << " How many elements you want to add? " << std::endl;
    int number{};
    std::cin>>number;
    std::cout << " Input an element " << std::endl;
    for (int i = 0; i < number; ++i) {
        int stack_el;
        std::cin>>stack_el;
        top++;
        buff.push_back(stack_el);
    }
    return true;
}

bool stack::delate()
{
    if (top == 0)
    {
        std::cout << " Stack is empty " << std::endl;
        return false;
    }
    std::cout << " How mane elements you want to delate? For all elements input 0" << std::endl;
    int number{};
    std::cin >> number;
    if( number == 0)
    {
        for (int i = 0; i < buff.size(); ++i) {
            buff.pop_back();
        }
    }
    else
    {
        for (int i = 0; i < number; ++i) {
            buff.pop_back();
        }
    }
    return true;
}

void stackfunc()
{
    stack st;
    st.capacity();
    st.add();
    st.capacity();
    st.print();
    st.delate();
    st.print();
}

//class Singleton
//{
//
//protected:
//    Singleton(const std::string value): value_(value)
//    {
//    }
//
//    static Singleton* singleton_;
//    std::string value_;
//
//public:
//
//    Singleton(Singleton &other) = delete;
//    void operator=(const Singleton &) = delete;
//
//    static Singleton *GetInstance(const std::string& value);
//    /**
//     * Finally, any singleton should define some business logic, which can be
//     * executed on its instance.
//     */
//    void SomeBusinessLogic()
//    {
//        // ...
//    }
//
//    std::string value() const{
//        return value_;
//    }
//};
//
//Singleton* Singleton::singleton_= nullptr;;
//
///**
// * Static methods should be defined outside the class.
// */
//Singleton *Singleton::GetInstance(const std::string& value)
//{
//    /**
//     * This is a safer way to create an instance. instance = new Singleton is
//     * dangeruous in case two instance threads wants to access at the same time
//     */
//    if(singleton_==nullptr){
//        singleton_ = new Singleton(value);
//    }
//    return singleton_;
//}
//
//void ThreadFoo(){
//    // Following code emulates slow initialization.
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    Singleton* singleton = Singleton::GetInstance("FOO");
//    std::cout << singleton->value() << "\n";
//}
//
//void ThreadBar(){
//    // Following code emulates slow initialization.
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    Singleton* singleton = Singleton::GetInstance("BAR");
//    std::cout << singleton->value() << "\n";
//}
//
//
//
//void pattern()
//{
//    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
//              "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
//              "RESULT:\n";
//    std::thread t1(ThreadFoo);
//    std::thread t2(ThreadBar);
//    t1.join();
//    t2.join();
//}

int main() {

    std::cout << "Input a number of task to do it" << std::endl;
    int task{};
    std::cin>>task;

    constexpr int firsttask{1};
    constexpr int secondttask{2};

    switch(task)
    {
        case (firsttask):
        {
            stackfunc();
            break;
        }
        case (secondttask):
        {
//            pattern();
//            break;
        }
        default:
        {
            std::cout << "There are only 2 tasks" << std::endl;
            return kErrorExit;
        }
    }

    return kSuccessExit;
}
