#include <PyInterpreter.h>
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

void PyInterpreter::RunScript(std::string _scriptPath)
{
    py::scoped_interpreter guard{}; 
	py::module sys = py::module::import("sys");
	sys.attr("path").attr("insert")(1, "./Lib/site-packages");

    try
	{
		auto str = py::eval_file(_scriptPath.c_str());
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
}