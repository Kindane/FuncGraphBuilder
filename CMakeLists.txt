cmake_minimum_required(VERSION 3.16)

project(FunctionGraphicBuilder VERSION 0.1)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


add_executable(fgb quadratic.c dot.c)

target_link_libraries(fgb
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    m) # m is a math module. <math.h>
