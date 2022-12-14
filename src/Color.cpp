#include "Color.hpp"

#include "Utils.hpp"

using namespace std;

Color::Color()
    : red(0), green(0), blue(0), alpha(255)
{
}

Color::Color(int color_mask)
{
    this->red   = (color_mask >> 16) & 0xFF;
    this->green = (color_mask >>  8) & 0xFF;
    this->blue  =  color_mask        & 0xFF;
    this->alpha = 255;
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : red(r), green(g), blue(b), alpha(a)
{
}

Color::Color(const string& colorName)
{
    uint8_t r(0), g(0), b(0);

         if (colorName == "white")   { r = 255; g = 255; b = 255; }
    else if (colorName == "black")   { r = 0;   g = 0;   b = 0;   }
    else if (colorName == "red")     { r = 255; g = 0;   b = 0;   }
    else if (colorName == "green")   { r = 0;   g = 255; b = 0;   }
    else if (colorName == "blue")    { r = 0;   g = 0;   b = 255; }
    else if (colorName == "cyan")    { r = 0;   g = 255; b = 255; }
    else if (colorName == "yellow")  { r = 255; g = 255; b = 0;   }
    else if (colorName == "magenta") { r = 255; g = 0;   b = 255; }

    this->red   = r;
    this->blue  = b;
    this->green = g;
    this->alpha = 255;
}

Color Color::operator+(const Color& color) const
{
    int tmp  = 0;

    uint8_t tmpR = 0;
    tmp = this->red + color.red;
    if (tmp > 255) tmpR = 255;
    if (tmp < 0)   tmpR = 0;
    else tmpR = tmp;

    uint8_t tmpG = 0;
    tmp = this->green + color.green;
    if (tmp > 255) tmpG = 255;
    if (tmp < 0)   tmpG = 0;
    else tmpG = tmp;

    uint8_t tmpB = 0;
    tmp = this->blue + color.blue;
    if (tmp > 255) tmpB = 255;
    if (tmp < 0)   tmpB = 0;
    else tmpB = tmp;

    uint8_t tmpA = 0;
    tmp = this->alpha + color.alpha;
    if (tmp > 255) tmpA = 255;
    if (tmp < 0)   tmpA = 0;
    else tmpA = tmp;

    Color result(tmpR, tmpG, tmpB, tmpA);
    
    return result;
}

Color Color::operator-(const Color& color) const
{
    int tmp  = 0;

    uint8_t tmpR = 0;
    tmp = this->red - color.red;
    if (tmp > 255) tmpR = 255;
    else if (tmp < 0)   tmpR = 0;
    else tmpR = tmp;

    uint8_t tmpG = 0;
    tmp = this->green - color.green;
    if (tmp > 255) tmpG = 255;
    else if (tmp < 0)   tmpG = 0;
    else tmpG = tmp;

    uint8_t tmpB = 0;
    tmp = this->blue - color.blue;
    if (tmp > 255) tmpB = 255;
    else if (tmp < 0)   tmpB = 0;
    else tmpB = tmp;

    uint8_t tmpA = 0;
    tmp = this->alpha - color.alpha;
    if (tmp > 255) tmpA = 255;
    else if (tmp < 0)   tmpA = 0;
    else tmpA = tmp;

    Color result(tmpR, tmpG, tmpB, tmpA);

    return result;
}

bool Color::operator==(const Color& color) const
{
    return ((this->red   == color.red)   &&
            (this->green == color.green) &&
            (this->blue  == color.blue)  &&
            (this->alpha == color.alpha));
}

bool Color::operator!=(const Color& color) const
{
    return ((this->red   != color.red)   &&
            (this->green != color.green) &&
            (this->blue  != color.blue)  &&
            (this->alpha != color.alpha));
}

uint8_t Color::r() const
{
    return (this->red);
}

uint8_t Color::g() const
{
    return (this->green);
}

uint8_t Color::b() const
{
    return (this->blue);
}

uint8_t Color::a() const
{
    return (this->alpha);
}

void Color::randomize()
{
    this->red   = Utils::Random::between(0, 255);
    this->green = Utils::Random::between(0, 255);
    this->blue  = Utils::Random::between(0, 255);
}

void Color::randomizeAlpha()
{
    this->alpha = Utils::Random::between(0, 255);
}

void Color::invert(bool R, bool G, bool B)
{
    if (R) this->red   = (255 - this->red);
    if (G) this->green = (255 - this->green);
    if (B) this->blue  = (255 - this->blue);
}
