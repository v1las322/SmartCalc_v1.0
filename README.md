Calculator Program Description
The calculator program is developed in C language of C11 standard using gcc compiler. The program code is located in the src folder and is built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests, gcov_report. The GUI implementation is based on Qt.

A mode "calculator" is provided:
The calculation is done after you complete entering the calculating expression and press the = symbol.
Calculating arbitrary bracketed arithmetic expressions in infix notation.
Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable x as a number.
Plotting a graph of a function given by an expression in infix notation with the variable x (with coordinate axes, mark of the used scale and an adaptive grid).
The scope of definition and the scope of function values are limited to at least numbers from -1000000 to 1000000.
Users can enter up to 255 characters.
Bracketed arithmetic expressions in infix notation support the following arithmetic operations and mathematical functions: cos(x), sin(x), tan(x), acos(x), asin(x), atan(x), sqrt(x), ln(x), log(x).
