#include "displayimpl.h"
#include "backend_log.h"


DisplayImpl::DisplayImpl()
    : Calculator::Display()
{
    secOperand = false;
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
    logInfo() << "Cleared what it is on the screen currently.";
    setDisplayNums(QStringLiteral("0"));
}

void DisplayImpl::ceclicked()
{
    logInfo() << "Cleared everything.";
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
