#ifndef DisplayIMPL_H
#define DisplayIMPL_H

#include <Calculator/display.hpp>

class DisplayImpl : public Calculator::Display
{
    Q_OBJECT
public:
    explicit DisplayImpl();
    void digitoneclicked() override;
};

#endif // DisplayIMPL_H
