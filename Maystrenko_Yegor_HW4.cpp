#include <iostream>
#include <chrono>
#include <random> 
#include <array>
#include <string>
#include <algorithm>

constexpr int kErrorExit{-1};
constexpr int kSuccessExit{0};
constexpr int karrsize{10};
constexpr int kstarr{5};

class Timer
{
public:
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }

    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

    long long elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};

long long bubblesort(const std::array<int,karrsize> &arr)
{
    std::array <int,karrsize>  arr_copy{};
    for (int i = 0; i < karrsize; ++i) {
        arr_copy[i] = arr[i];
    }
    Timer timer_bubble;
    timer_bubble.start();
    bool sorted = false;
    int *ptr = &arr_copy[0];
    while (!sorted)
    {
        sorted = true;
        for (int j = 0; j < ( arr_copy.size() - 1 ); j++)
        {
            if (*(ptr + j ) > *(ptr + j + 1))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
                sorted = false;
            }
        }
    }
    timer_bubble.stop();
    return timer_bubble.elapsedMilliseconds();
}


long long insertionSort(const std::array<int,karrsize> &arr)
{
    std::array <int,karrsize>  arr_copy{};
    for (int i = 0; i < karrsize; ++i) {
        arr_copy[i] = arr[i];
    }
    Timer timer_insert;
    timer_insert.start();
    int *ptr = &arr_copy[0];
    for(int j = 1; j < arr_copy.size(); j++)
    {
        int key = arr_copy[j];
        int i = j - 1;
        while( ( i >= 0 ) && ( *(ptr + i ) > key ) )
        {
            *(ptr + i + 1) = *(ptr + i);
            i = i - 1;
            *(ptr + i + 1) = key;
        }
    }
    timer_insert.stop();
    return timer_insert.elapsedMilliseconds();
}

void randominput(std::array<int,karrsize> &arr,int min,int max)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<signed> distrib(min, max);

    for(int & j : arr)
    {
        j =  distrib(gen);
    }
}


void userinput(std::array<int,karrsize> &arr, const std::string &line)
{
    std::cout << "Input" << line << "members please:" << std::endl;
    for (int & i : arr) {
        std::cin >> i;
    }
}

void results(long long bubble,long long insert )
{
    if ( bubble < insert )
    {
        std::cout << "Bubble sort is quicker than insert sort " << std::endl;
    }
    else
    {
        std::cout << "Insert sort is quicker than bubble sort " << std::endl;
    }
    std::cout << "Bubble sort time: " << bubble << std::endl;
    std::cout << "Insert sort time: " << insert << std::endl;
}

int sorting_performance()
{
    std::cout << "Hi, write r to fill the array by random method, or y by yourself" << std::endl;
    char question;
    std::cin >> question;

    std::array <int, karrsize> arr_both{};
    std::array <int, karrsize> arr_positive{};
    std::array <int, karrsize> arr_negative{};

    constexpr int max_pos{100};
    constexpr int min_neg{-100};
    constexpr int max_neg{-1};
    constexpr int min_pos{1};

    if ( question == 'r' )
    {
        randominput(arr_both,min_neg,max_pos);
        randominput(arr_positive,min_pos,max_pos);
        randominput(arr_negative,min_neg,max_neg);

    }
    else if ( question == 'y' )
    {
        userinput(arr_both," negative and positive array ");
        userinput(arr_positive," positive ");
        userinput(arr_negative, " negative ");
    }
    else
    {
        std::cout << "Input correct letter" << std::endl;
        return kErrorExit;
    }

    long long bubble_both = bubblesort(arr_both);
    long long insert_both = insertionSort(arr_both);
    results( bubble_both,insert_both );

    long long bubblesort_pos = bubblesort(arr_positive);
    long long insertionSort_pos = insertionSort(arr_positive);
    results( bubblesort_pos,insertionSort_pos );

    long long bubblesort_neg = bubblesort(arr_negative);
    long long insertionSort_neg = insertionSort(arr_negative);
    results( bubblesort_neg,insertionSort_neg );

    return kSuccessExit;
}

template<typename T>
bool cmp(T first, T second) {

    return first > second;
}

template<typename T>
void bubblesort_(  std::array<T,kstarr> &arr_copy)
{
    T temp{0};
    for (int i = 0; i < kstarr - 1; i++) {
        for (int j = 0; j < kstarr - i - 1; j++) {
            if (cmp( arr_copy[j], arr_copy[j + 1])) {
                temp = arr_copy[j];
                arr_copy[j] = arr_copy[j + 1];
                arr_copy[j + 1] = temp;
            }
        }
    }
}

void sorting_types()
{
        std::array <unsigned int, kstarr> uint_arr{3,2,4,1,6};
        std::array <double,kstarr> double_arr{1.3,3.5,6.4,7.4,3.9};
        std::array <char,kstarr> char_big{'C','L','Z','X','B'};
        std::array <char,kstarr> char_small{'c','l','z','x','b'};
        std::array <char,kstarr> char_numbers{'3','5','4','8','2'};

    bubblesort_<unsigned int>(uint_arr);
    bubblesort_(double_arr);
    bubblesort_(char_big);
    bubblesort_(char_small);
    bubblesort_(char_numbers);

    for (int i = 0; i < kstarr ; ++i) {
        std::cout << double_arr[i] << "  ";
    }
    std::cout << "\n";
    for (int i = 0; i < kstarr ; ++i) {
        std::cout << uint_arr[i] << " " ;
    }
    std::cout << "\n";
    for (int i = 0; i < kstarr ; ++i) {
        std::cout << char_big[i] << " " ;
    }
    std::cout << "\n";
    for (int i = 0; i < kstarr ; ++i) {
        std::cout << char_small[i] << " " ;
    }
    std::cout << "\n";
    for (int i = 0; i < kstarr ; ++i) {
        std::cout << char_numbers[i] << " " ;
    }
}
char afterw(char x)
{
    if( x == 'x')
    {
        x = 'a';
    }
    else if( x == 'y')
    {
        x = 'b';
    }
    else if( x == 'z')
    {
        x = 'c';
    }
    return x;
}

char befored(char x)
{
    if( x == 'a')
    {
        x = 'x';
    }
    else if( x == 'b')
    {
         x = 'y';
    }
    else if( x == 'c')
    {
        x = 'z';
    }
    return x;
}

void enigma ()
{
    constexpr int klinesize{16};
    constexpr int kalfsize{26};

    std::string line = "Yegor Maystrenko";

    std::cout <<  " Main massage: " << std::endl;
    for (char i : line) {
        std::cout << i << " " ;
    }
    std::cout << "\n";

    std::array <char,kalfsize> alfabet{};
    int pos{0};
    for (int i = 'a'; i <= 'z' ; ++i) {
        alfabet[pos] = i;
        pos++;
    }

    char space = ' ';
    std::array <char, klinesize> ch_line{};
    for (int i = 0; i < line.size(); ++i) {
        if ( line[i] != space)
        {
            ch_line[i] = line[i];
        }
    }

    std::array <char, klinesize> ch_linesecret{};
    for (int i = 0; i < ch_line.size(); ++i) { //шифрування
        for (int j = 0; j < alfabet.size(); ++j) {
            if( ch_line[i] == alfabet[j])
            {
                if(ch_line[i] < 'x')
                {
                    ch_linesecret[i] = alfabet[j+3];
                }
                else
                {
                    ch_linesecret[i] = afterw(alfabet[j]);
                }
            }
        }
    }
    std::cout <<  " Coding: " << std::endl;
    for (char i : ch_linesecret) {
        std::cout << i << " " ;
    }
    std::cout << "\n";
    for (int i = 0; i < ch_linesecret.size(); ++i) { //дешифрування
        for (int j = 0; j < alfabet.size(); ++j) {
            if( ch_linesecret[i] == alfabet[j])
            {
                if(ch_linesecret[i] < 'd')
                {
                    ch_line[i] = befored(alfabet[j]);
                }
                else
                {
                    ch_line[i] = alfabet[j-3];
                }
            }
        }
    }
    std::cout <<  " Decoding: " << std::endl;
    for (char i : ch_line) {
        std::cout << i << " " ;
    }
}

int main() {

    std::cout << "Input a number of task to do it" << std::endl;
    int task{};
    std::cin>>task;

    constexpr int firsttask{1};
    constexpr int secondttask{2};
    constexpr int thirdtask{3};

    switch(task)
    {
        case (firsttask):
        {
            sorting_performance();
            break;
        }
        case (secondttask):
        {
            sorting_types();
            break;
        }
        case (thirdtask):
        {
            enigma();
            break;
        }
        default:
        {
            std::cout << "There are only 3 tasks" << std::endl;
            return kErrorExit;
        }
    }

    return kSuccessExit;
}
