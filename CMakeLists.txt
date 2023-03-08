cmake_minimum_required(VERSION 3.22.0)
project(CircleDetector VERSION 0.1.1)

cmake_policy(SET CMP0074 NEW)
enable_testing()

if (MSVC)
    # 设置 msvc 输入代码编码格式为 utf-8
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt库
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Gui Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui Core)

# OpenCV库
set(OpenCV_DIR "D:/CPPLibs/opencv460/opencv/build/x64/vc17/lib") # 找到lib文件目录
find_package(OpenCV REQUIRED)	# 找到OpenCV库
include_directories(${OpenCV_INCLUDE_DIRS})

# Boost库
# set(Boost_ROOT "D:/CPPLibs/boost_1_80_0")
# find_package(Boost REQUIRED COMPONENTS)
# link_directories(${Boost_LIBRARY_DIRS})
# include_directories(${Boost_INCLUDE_DIRS})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/)

add_subdirectory(src)
include_directories(inc)
include_directories(inc/ui)
include_directories(inc/base)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CircleDetector
        MANUAL_FINALIZATION
        src/main.cpp
        inc/ui/MainWindow.hpp
        inc/base/Label.hpp
        inc/ui/ParametersDialog.hpp
        ${_UI_SOURCES}
        ${_BASE_SOURCES}
    )
endif()

target_link_libraries(CircleDetector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Core ${OpenCV_LIBRARIES})

set_target_properties(CircleDetector PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CircleDetector)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)