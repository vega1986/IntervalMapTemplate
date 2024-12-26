# CMakeList.txt: проект CMake для intervalMapExample; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required( VERSION 3.24 )

project( "intervalMapExample" )

# Добавьте источник в исполняемый файл этого проекта.
add_executable( intervalMapExample
                "intervalMapExample.cpp"
                "intervalMapExample.h"
                "interval_map.h"
                "interval.h"
                "testing.h"
                "testing.cpp" )

set_property( TARGET intervalMapExample PROPERTY CXX_STANDARD 20 )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
