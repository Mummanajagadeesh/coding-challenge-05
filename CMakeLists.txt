cmake_minimum_required(VERSION 3.16)
project(describe_object LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(describe_object
    src/main.cpp
    src/object/ObjectFactory.cpp
    src/object/ObjectRegistry.cpp
    src/objects/Circle.cpp
    src/objects/Square.cpp
    src/objects/Rectangle.cpp
)

target_include_directories(describe_object
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(describe_object_tests
    tests/test_objects.cpp
    src/object/ObjectFactory.cpp
    src/object/ObjectRegistry.cpp
    src/objects/Circle.cpp
    src/objects/Square.cpp
    src/objects/Rectangle.cpp
)

target_include_directories(describe_object_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
