#include <iostream>

using namespace std;

class Color{
    public:
        Color(unsigned char red, unsigned char green, unsigned char blue);
        Color(const Color& c);

        unsigned char red() const;
        unsigned char green() const;
        unsigned char blue() const;

        static const Color RED, GREEN, BLUE, BLACK, WHITE;


        bool equal_to(const Color& other) const;
        void invert();


    private:
        char r;
        char g;
        char b;



        
};