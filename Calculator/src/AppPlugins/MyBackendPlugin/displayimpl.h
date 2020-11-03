#ifndef DisplayIMPL_H
#define DisplayIMPL_H

#include <Calculator/display.hpp>


class DisplayImpl : public Calculator::Display
{
    Q_OBJECT
    double firstOperand;
    bool isNeg;
    bool isMult;
    bool isAdd;
    bool isSub;
    bool isDiv;
public:
    explicit DisplayImpl();
    void digitclicked(const QString &digit) override;
    void dotclicked() override;
    void clearclicked() override;
    void ceclicked() override;
    void backclicked() override;
    void multclicked() override;
    void addclicked() override;
    void subclicked() override;
    void divclicked() override;
    void negclicked() override;
    void eqclicked() override;
    void sqrtclicked() override;
};

#endif // DisplayIMPL_H
