#ifndef COLOR_HPP
#define COLOR_HPP

class Color {
private:
    double R, G, B;

public:
    Color(); // constructor with no params
    Color(double R, double G, double B);

    // inline get methods
    double getR() const;
    double getG() const;
    double getB() const;

    // overload methods
    Color add(const Color& other) const;
    Color add(double value) const;
    Color operator+(const Color& other) const;
    Color operator+(double value) const;
    Color mult_scalar(double value) const;
    Color operator*(double value) const;

    void cap();
};

#endif
