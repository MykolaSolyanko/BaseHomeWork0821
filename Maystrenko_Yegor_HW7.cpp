#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual void  calc_square() const
    {
        std::cout << " " << std::endl;
    }
    virtual void draw() const
    {
        std::cout << " " << std::endl;
    }
};

class square : public Shape
{
public:
    void  calc_square() const override
    {
        auto Square =  pow(A,2);
        std::cout << " Square: " << Square << std::endl;
    }
    void draw() const override
    {
        std::cout << " square " << std::endl;
    }
private:
    int A{10};
};

class rectangular : public Shape
{
public:
    void  calc_square()  const override
    {
    auto Square =  ( A * B ) ;
    std::cout << " Square: " << Square << std::endl;
    }
    void draw() const override
    {
        std::cout << " rectangular " << std::endl;
    }
private:
    int A{10};
    int B{20};
};

class triangle : public Shape
{
public:
    void  calc_square() const override
    {
        auto Square =  static_cast<float>( A + B ) * corner;
        std::cout << " Square: " << Square << std::endl;
    }
    void draw() const override
    {
        std::cout << " triangle " << std::endl;
    }
private:
    int A{10};
    int B{20};
    float corner{0.5};
};

void function(Shape& shape)
{
    shape.calc_square();
    shape.draw();
}

int main() {
    triangle tr;
    rectangular rc;
    square sq;
    function(tr);
    function(rc);
    function(sq);
    return 0;
}
