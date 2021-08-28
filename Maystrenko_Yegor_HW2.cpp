#include <iostream>

constexpr int kErrorExit{-1};
constexpr int kSuccessExit{0};

void tree ( )
{
    std::cout << "Please input a tree high" << std::endl;
    int amount;
    std::cin >> amount;
    if ( amount % 2 == 0)
    {
        amount = amount + 1;
    }

    char space {' '};
    char star {'*'};
    int starcounter{1};
    int spacecounter{( amount - 1 ) / 2};

    while ( starcounter != amount + 2 )
    {
        for (int i = 0; i < spacecounter ; ++i)
        {
            std::cout << space;
        }
        for (int i = 0; i < starcounter; ++i)
        {
            std::cout << star ;
        }
        std::cout << '\n';
        starcounter = starcounter + 2;
        spacecounter--;
    }
}

 int32_t reverse ()
 {
     std::cout << "Please input a number to reverse it" << std::endl;
     int32_t number;
     std::cin >> number;
     if ( number == 0 )
     {
         std::cout << "Please enter a correct number" << std::endl;
         return  kErrorExit;
     }

     int check{0};
     if ( number < 0 )
     {
         check++;
         number = number * (-1);
     }

     int32_t newnumber{0};
     while (number != 0) {
         newnumber = (newnumber*10) + (number%10);
         number = number/10;
     }
     if ( check > 0)
     {
         newnumber = newnumber * (-1);
     }
     return newnumber ;
 }

 int division( )
 {
     std::cout << "Please input a number to find best divisor" << std::endl;
     int number;
     std::cin >> number;
     if ( number <= 0 )
     {
         std::cout << "Please enter a positive number" << std::endl;
         return  kErrorExit;
     }

     int size{0};
     int arr[size]{};
     int position{0};
     for (int i = 1; i <=number; ++i)
     {
         if ( (number % i) == 0)
         {
             arr[position] = i;
             position++;
             size++;
         }
     }

     int Sum{0};
     while ( number != 0 )
     {
         Sum += number % 10;
         number /= 10;
     }

     int bestdiv{0};
     for (int i = 0; i <= 10 ; ++i)
     {
         if ( Sum < arr[i] )
         {
             bestdiv = arr[i];
             break;
         }
     }
     return bestdiv;
 }

 int oddsum ()
 {
     std::cout << "How many elements do you want to input? Range [1...50]" << std::endl;
     int kSize{0};
     std::cin >> kSize;
     if ( (kSize > 50) || (kSize <= 1) )
     {
         std::cout << "Please enter a correct range elemnt" << std::endl;
         return  kErrorExit;
     }

     std::cout << "Input these elements " << std::endl;
     int Arr[kSize];
     for (int i = 0; i < kSize; ++i)
     {
         int element{};
         std::cin >> element;
         if ( (element <= -60) || (element >= 90) )
         {
             std::cout << "Please enter a correct range elemnt" << std::endl;
             return  kErrorExit;
         }
         Arr[i] = element;
     }

     int oddSum{0};
     for (int i = 0; i < kSize; ++i)
     {

         if ( Arr[i] % 2 != 0 )
         {
             oddSum += Arr[i];
         }
     }
     return oddSum;
 }

 void ticket ()
 {
     std::cout << "Please enter a six-digit number " << std::endl;
     long sixnumber{};
     std::cin >> sixnumber;

     int check{0};
     while (sixnumber != 0) {
         check++;
         sixnumber /= 10;
     }
     if ( check != 6 )
     {
         std::cout << "Please enter correct six-digit number" << std::endl;
         system("pause");
         ticket();
         //return  kErrorExit;
     }

     int secondSum{0};
     int firstSum{0};
     int counter{0};
     while ( sixnumber != 0 )
     {
         if ( counter >= 3 )
         {
             firstSum += sixnumber % 10;
         }
         else
         {
             secondSum += sixnumber % 10;

         }
         counter++;
         sixnumber /= 10;
     }

     if ( secondSum == firstSum )
     {
         std::cout << "It's a happy ticket!" << std::endl;
     }
     else
     {
         std::cout << "It's not a happy ticket!" << std::endl;
     }
 }

 void sum_average (int &Sum, double &Average)
{
    std::cout << "Please enter a number " << std::endl;
    long number{};
    std::cin >> number ;

    if ( number <= 0 ) {
        std::cout << "Please enter a number what will be above zero" << std::endl;
        system("pause");
        exit(0);
    }

    int numcounter{0};
    while ( number != 0 )
    {
        Sum += number % 10;
        number /= 10;
        numcounter++;
    }

    Average = Sum / numcounter;
}

int main() {

//    int Sum{0};
//    double Average{0};
//    sum_average(Sum,Average);  // Використовую посилання, оскільки повернути 2 значення функція не може
//    std::cout << "Average of elements " << Average << std::endl;
//    std::cout << "Sum of elements " << Sum << std::endl;
//
//    std::cout << oddsum() << std::endl; // сума непарних елементів
//    ticket(); // щасливий квиточок
//    std::cout << oddsum() << std::endl; // сума непарних елементів
//    std::cout << reverse() << std::endl; // реверс числа
//    std::cout << division() << std::endl; // найкращий дільник
//    tree(); // ялинка


    return kSuccessExit;
}
