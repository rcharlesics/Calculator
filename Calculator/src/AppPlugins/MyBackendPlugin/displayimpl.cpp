#include "displayimpl.h"

DisplayImpl::DisplayImpl()
    : Calculator::Display()
{}

void DisplayImpl::digitoneclicked()
{
    qDebug() << "One clicked";
}

