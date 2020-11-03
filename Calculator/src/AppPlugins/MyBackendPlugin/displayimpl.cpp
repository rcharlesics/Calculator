#include "displayimpl.h"
#include "backend_log.h"


DisplayImpl::DisplayImpl()
    : Calculator::Display()
{

    isAdd=false;
    isDiv=false;
    isMult=false;
    isSub=false;
    waitingSecond=false;
}

void DisplayImpl::digitclicked(const QString &digit)
{
    logInfo() << digit;
    int digitValue = digit.toInt();
    if (displayNums() == QStringLiteral("0") && digitValue == 0.0)
        return;
    else if (displayNums() == QStringLiteral("0") && digitValue != 0.0)
        setDisplayNums(digit);
    else
        setDisplayNums(displayNums()+digit);
}




void DisplayImpl::dotclicked()
{
    if (!displayNums().contains(QStringLiteral(".")))
    {
        logInfo() << "Does not contain .";
        setDisplayNums(displayNums()+QStringLiteral("."));
    }
    logInfo() << "Contains .";
}

void DisplayImpl::clearclicked()
{
    logInfo() << "Cleared everything.";
    setDisplayNums(QStringLiteral("0"));
    isAdd=false;
    isDiv=false;
    isMult=false;
    isSub=false;
    waitingSecond=false;
}

void DisplayImpl::ceclicked()
{
    logInfo() << "Cleared last used element.";
    setDisplayNums(QStringLiteral("0"));
}

void DisplayImpl::backclicked()
{
    if (displayNums().length() > 1 && displayNums() != QStringLiteral("0"))
    {
        logInfo() << "Backspaced once.";
        setDisplayNums(displayNums().remove(displayNums().length()-1,1));
    }
    else if (displayNums().length() == 1 && displayNums() != QStringLiteral("0"))
    {
        logInfo() << "Backspaced only digit.";
        setDisplayNums(QStringLiteral("0"));
    }

}

void DisplayImpl::multclicked()
{
    if (waitingSecond){
        if (isMult)
        {
            double res = firstOperand * displayNums().toDouble();
            setDisplayNums(QString::number(res));
            firstOperand = res;
            logInfo() << "hit mulitplied twice";
            return;
        }
        if (isAdd)
        {
            isAdd=false;
        }
        if (isSub)
        {
            isSub=false;
        }
        if (isDiv)
        {
            isDiv=false;
        }
    }
    firstOperand = displayNums().toDouble();
    setDisplayNums(QStringLiteral("0"));
    isMult=true;
    waitingSecond=true;
    logInfo() << "Ready to multiply";
}

void DisplayImpl::addclicked()
{
    if (waitingSecond){
        if (isMult)
        {
            isMult=false;
        }
        if (isAdd)
        {
            double res = firstOperand +displayNums().toDouble();
            setDisplayNums(QString::number(res));
            firstOperand = res;
            logInfo() << "hit added twice";
            return;

        }
        if (isSub)
        {
            isSub=false;
        }
        if (isDiv)
        {
            isDiv=false;
        }
    }
    firstOperand = displayNums().toDouble();
    setDisplayNums(QStringLiteral("0"));
    isAdd=true;
    waitingSecond=true;
    logInfo() << "Ready to add";
}

void DisplayImpl::subclicked()
{
    if (waitingSecond){
        if (isMult)
        {
            isMult=false;
        }
        if (isAdd)
        {
            isAdd=false;
        }
        if (isSub)
        {
            double res = firstOperand -displayNums().toDouble();
            setDisplayNums(QString::number(res));
            firstOperand = res;
            logInfo() << "hit subtracted";
            return;
        }
        if (isDiv)
        {
            isDiv=false;
        }
    }
    firstOperand = displayNums().toDouble();
    setDisplayNums(QStringLiteral("0"));
    isSub=true;
    waitingSecond=true;
    logInfo() << "Ready to subtract";
}

void DisplayImpl::divclicked()
{
    if (waitingSecond){
        if (isMult)
        {
            isMult=false;
        }
        if (isAdd)
        {
            isAdd=false;
        }
        if (isSub)
        {
            isSub=false;
        }
        if (isDiv)
        {
           double res = firstOperand / displayNums().toDouble();
           setDisplayNums(QString::number(res));
           firstOperand = res;
           logInfo() << "hit divided twice.";
           return;
        }
    }
    firstOperand = displayNums().toDouble();
    setDisplayNums(QStringLiteral("0"));
    isDiv=true;
    waitingSecond=true;
    logInfo() << "Ready to divide";
}

void DisplayImpl::negclicked()
{
    if (displayNums()!=QStringLiteral("0"))
    {
        setDisplayNums(QStringLiteral("-")+displayNums());
    }
    logInfo() << "Added negative signs";
}

void DisplayImpl::eqclicked()
{
    double secondOperand = displayNums().toDouble();
    if (isMult)
    {
        double res = firstOperand * secondOperand;
        setDisplayNums(QString::number(res));
        firstOperand=res;
        isMult=false;
        logInfo() << "Multiplied";
    }
    if (isAdd)
    {
        double res = firstOperand + secondOperand;
        setDisplayNums(QString::number(res));
        firstOperand=res;
        isAdd=false;
        logInfo() << "Added";
    }
    if (isSub)
    {
        double res = firstOperand - secondOperand;
        setDisplayNums(QString::number(res));
        firstOperand=res;
        isSub=false;
        logInfo() << "Subtracted";
    }
    if (isDiv)
    {
        isDiv=false;
        if (secondOperand == 0.0)
        {
            firstOperand = 0;
            setDisplayNums(QStringLiteral("ERROR"));
            return;
            logInfo() << "Divided by 0. Gave error.";

        }
        double res = firstOperand / secondOperand;
        firstOperand=res;
        setDisplayNums(QString::number(res));
        logInfo() << "Divided";
    }
}

void DisplayImpl::sqrtclicked()
{
    firstOperand = displayNums().toDouble();
    if (firstOperand<0){
        firstOperand=0;
        setDisplayNums(QStringLiteral("ERROR"));
        return;
    }
    double res = sqrt(firstOperand);
    setDisplayNums(QString::number(res));
    firstOperand=res;
}
