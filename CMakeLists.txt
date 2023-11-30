# Check cmake version meets our requirements
cmake_minimum_required(VERSION 3.3)

# Declare project, which will configure compiler for us
project(SNCuts)

#Finds ROOT and Falaise packages and defines cmake variables
find_package(Falaise REQUIRED)

include_directories(include ${Bayeux_INCLUDE_DIRS})


add_library(SNCuts SHARED src/SNCuts.cpp include/SNCuts.h)

target_link_libraries(SNCuts PUBLIC Falaise::FalaiseModule)  

install(TARGETS SNCuts DESTINATION ${CMAKE_INSTALL_PLUGINDIR})
