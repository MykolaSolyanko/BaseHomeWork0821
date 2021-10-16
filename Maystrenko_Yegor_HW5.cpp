#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <optional>
#include <array>
#include <cmath>

constexpr int kErrorExit{-1};
constexpr int kSuccessExit{0};

struct comp {
    int Data;
    comp *next;
};

bool add(comp **top) {
    std::cout << " How many elements you want to add? " << std::endl;
    int number;
    std::cin >> number;
    if(number <= 0)
    {
        return false;
    }
    for (int i = 0; i < number; ++i) {
        std::cout << " Input an element " << std::endl;
        int value;
        std::cin >> value;
        comp *q;
        q = new comp;
        q->Data = value;
        if (top == nullptr) {
            *top = q;
        }
        else
        {
            q->next = *top;
            *top = q;
        }
    }
    return true;
}

void delating(comp **top) {
    std::cout << " How many elements you want to delate? For all elements input 0 " << std::endl;
    int number;
    std::cin >> number;
    if ( number == 0)
    {
        comp *q = *top;
        while (q != nullptr) {

            *top = q->next;
            free(q);
            q = q->next;
        }
    }
    else
    {
        for (int i = 0; i < number; ++i) {
            comp *q = *top;
            *top = q->next;
            free(q);
        }
    }
}

void find(comp *top)
{
    std::cout << " What value do you want to search? " << std::endl;
    int value;
    int check{0};
    std::cin >> value;
    comp *q = top;
    while (q) {
        if ( q->Data == value )
        {
            std::cout << " Stack has this element " << std::endl;
            check++;
            break;
        }
        q = q->next;
    }
    if ( check == 0)
    {
        std::cout << " Stack doesn't have this element " << std::endl;
    }
}

bool print(comp *top) {
    comp *q = top;
    if ( q == nullptr )
    {
        std::cout << " Stack is empty " << std::endl;
        return false;
    }
    else
    {
        while (q) {
            std::cout << q->Data << std::endl ;
            q = q->next;
        }
    }
    return true;
}

void sum_empty(comp *top) {
    comp *q = top;
    int Sum{0};
    while (q != nullptr) {
       Sum++;
        q = q->next;
    }
    if ( Sum == 0)
    {
        std::cout << " Stack is empty " << std::endl;
    }
    else
    {
        std::cout << " In stack: " << Sum << " elements " << std::endl;
    }
}


void stackfunc()
{
    comp *stek = nullptr;
    sum_empty(stek);
    add(&stek);
    print(stek);
    delating(&stek);
    print(stek);
    sum_empty(stek);
    find(stek);
}

//struct points
//{
//    int start{};
//    int stop{};
//};
//
//void magic(std::string &line,int start, int stop)
//{
//    int Sum{0};
//    for (int i = start; i <= stop; ++i) {
//         Sum += pow(i,3);
//    }
//    if( (Sum/2) ==  )
//    {
//
//    }
//}
//
//bool reverse()
//{
//    points p;
//    std::cout << "Input a sting of digits" << std::endl;
//    std::string line;
//    std::cin>> line;
//    std::cout << "Input a parts number" << std::endl;
//    int parts{};
//    std::cin>> parts;
//    if ( (line.length() == 0) || (parts <= 0) )
//    {
//        std::cout << " Empty" << std::endl;
//        return false;
//    }
//    else if((parts > line.length()))
//    {
//        std::cout << "" << std::endl;
//        return false;
//    }
//    p.start = 0;
//    p.stop = parts;
//   magic(line,p.start,p.stop);
//
//return true;
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
            //reverse();
            break;
        }
        default:
        {
            std::cout << "There are only 2 tasks" << std::endl;
            return kErrorExit;
        }
    }
    return kSuccessExit;
}
