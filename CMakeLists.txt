cmake_minimum_required(VERSION 3.5)

project(mandelbrot_set
    VERSION 0.1
    LANGUAGES CXX
    )

find_package(Qt5 5.9 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE
    main.cpp
    main_window.hpp
    main_window.cpp
    main_window.ui
    mandelbrot_view.hpp
    mandelbrot_view.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOUIC ON
    AUTOMOC ON
    AUTORCC ON

    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_LANGUAGE_EXTENSIONS OFF

    MACOSX_BUNDLE_GUI_IDENTIFIER ${PROJECT_NAME}.gekus.ru
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
