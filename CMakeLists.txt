cmake_minimum_required(VERSION 3.3)
project(Auto_new)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h Controllers/Customers_Controller.cpp Controllers/Customers_Controller.h Controllers/Auto_Controller.cpp Controllers/Auto_Controller.h Controllers/Brand_directory_Controller.cpp Controllers/Brand_directory_Controller.h Models/Brand_directory_Model.cpp Models/Brand_directory_Model.h Models/Auto_Model.cpp Models/Auto_Model.h Models/Customers_Model.cpp Models/Customers_Model.h Controllers/Orders_Controller.cpp Controllers/Orders_Controller.h Models/Orders_Model.cpp Models/Orders_Model.h Controllers/Calculation_Controller.cpp Controllers/Calculation_Controller.h Models/Calculation_Model.cpp Models/Calculation_Model.h config.h Models/Main_Model.cpp Models/Main_Model.h)
add_executable(Auto_new ${SOURCE_FILES})
