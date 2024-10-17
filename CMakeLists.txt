cmake_minimum_required(VERSION 3.16)

project(QProcess_QThread_QTimer_Demo LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(QProcess_QThread_QTimer_Demo
  main.cpp
  consumer.h consumer.cpp
  producer.h producer.cpp
  commander.h commander.cpp
)
target_link_libraries(QProcess_QThread_QTimer_Demo Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS QProcess_QThread_QTimer_Demo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
