#include "displayimpl.h"
#include "backend_log.h"

DisplayImpl::DisplayImpl()
    : Calculator::Display()
{}

void DisplayImpl::digitoneclicked()
{
    logInfo() << "One clicked";
}

