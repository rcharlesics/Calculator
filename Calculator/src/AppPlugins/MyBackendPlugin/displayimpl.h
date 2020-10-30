#ifndef DisplayIMPL_H
#define DisplayIMPL_H

#include <Calculator/display.hpp>


class DisplayImpl : public Calculator::Display
{
    Q_OBJECT
    bool secOperand;
public:
    explicit DisplayImpl();
    void digitclicked(const QString &digit) override;
    void dotclicked() override;
    void clearclicked() override;
    void ceclicked() override;
    void backclicked() override;
};

#endif // DisplayIMPL_H
