cmake_minimum_required(VERSION 3.17)
project(cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(cryptography src/main.cpp src/structure/BaseMathField.h src/structure/ComplexField.h src/structure/ComplexField.cpp src/structure/IntegersModuloNField.h src/structure/IntegersModuloNField.cpp src/structure/RealField.h src/structure/RealField.cpp src/number/RealNumber.cpp src/number/RealNumber.h src/number/ComplexNumber.cpp src/number/ComplexNumber.h src/structure/FieldFactory.cpp src/structure/FieldFactory.h src/number/BaseNumber.h src/structure/BaseMathField.h src/number/IntegerModuloNNumber.cpp src/number/IntegerModuloNNumber.h src/number/RationalNumber.cpp src/number/RationalNumber.h src/structure/RationalField.cpp src/structure/RationalField.h src/structure/BaseMathField.cpp src/math/MathUtils.cpp src/math/MathUtils.h)
