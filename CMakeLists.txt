cmake_minimum_required(VERSION 3.17)
project(cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(cryptography src/main.cpp src/field/BaseMathField.h src/field/ComplexField.h src/field/ComplexField.cpp src/field/IntegersModuloNField.h src/field/IntegersModuloNField.cpp src/field/RealField.h src/field/RealField.cpp src/number/RealNumber.cpp src/number/RealNumber.h src/number/ComplexNumber.cpp src/number/ComplexNumber.h src/math/FieldFactory.cpp src/math/FieldFactory.h src/number/BaseNumber.h src/number/IntegerModuloNNumber.cpp src/number/IntegerModuloNNumber.h src/number/RationalNumber.cpp src/number/RationalNumber.h src/field/RationalField.cpp src/field/RationalField.h src/math/MathUtils.cpp src/math/MathUtils.h src/math/FieldEquationsPrompter.cpp src/math/FieldEquationsPrompter.h src/exceptions/IncompatibleFieldsException.cpp src/exceptions/IncompatibleFieldsException.h src/exceptions/NotAFieldException.cpp src/exceptions/NotAFieldException.h src/MainLoop.cpp src/MainLoop.h src/field/FiniteField.cpp src/field/FiniteField.h src/number/FiniteFieldNumber.cpp src/number/FiniteFieldNumber.h)
