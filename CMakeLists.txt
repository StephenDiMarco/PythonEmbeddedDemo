cmake_minimum_required(VERSION 2.8.2)
project(ngs-plugin)

# General build configuration
set(CMAKE_CXX_FLAGS -std=c++0x)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(include)


file(GLOB main_SRC src/*.cpp)
add_executable(${PROJECT_NAME} ${main_SRC})
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})
