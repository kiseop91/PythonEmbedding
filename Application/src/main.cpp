
#include <iostream>
#include <PyInterpreter.h>

int main()
{
    PyInterpreter py;
    py.RunScript("../../../../Application/pythonScripts/sample.py");
}