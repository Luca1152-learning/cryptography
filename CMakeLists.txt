cmake_minimum_required(VERSION 3.17)
project(criptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(criptography src/main.cpp src/structure/BaseMathStructure.h src/structure/ComplexStructure.h src/structure/ComplexStructure.cpp src/structure/IntegerStructure.h src/structure/IntegerStructure.cpp src/structure/IntegerModuloNStructure.h src/structure/IntegerModuloNStructure.cpp src/structure/RealStructure.h src/structure/RealStructure.cpp src/number/RealNumber.cpp src/number/RealNumber.h src/number/ComplexNumber.cpp src/number/ComplexNumber.h src/number/IntegerNumber.cpp src/number/IntegerNumber.h src/structure/StructureFactory.cpp src/structure/StructureFactory.h src/number/SetType.h src/number/BaseNumber.h src/structure/BaseMathStructure.h src/number/IntegerModuloNNumber.cpp src/number/IntegerModuloNNumber.h src/number/NaturalNumber.cpp src/number/NaturalNumber.h src/number/RationalNumber.cpp src/number/RationalNumber.h src/structure/NaturalStructure.cpp src/structure/NaturalStructure.h src/structure/RationalStructure.cpp src/structure/RationalStructure.h src/structure/BaseMathStructure.cpp src/math/MathUtils.cpp src/math/MathUtils.h)
