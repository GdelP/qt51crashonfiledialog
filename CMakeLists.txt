project(qt5crash)
#setup qt
set(SDK_PATH "C:/Program Files/Microsoft SDKs/Windows/v7.1A/Lib/x64;C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Lib/x64;C:/Program Files/Microsoft SDKs/Windows/v7.1/Lib/x64;C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1/Lib/x64;C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/x64;C:/Program Files/Microsoft SDKs/Windows/v7.0A/Lib/x64")
set(QT_DIR_WIN "C:/Qt/Qt5.1.0/5.1.0/msvc2012_64_opengl/lib/cmake")
set(QT_DIR "${QT_DIR_WIN}")

set(QML_IMPORT_PATH ${QT_DIR}/../../imports)
set(QML2_IMPORT_PATH ${QML_IMPORT_PATH})
set(QT_ROOT ${QT_DIR})

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QT_DIR};${SDK_PATH}")


#project definition
include_directories(../kernel/include ../kernel/implementation ../SDK/include ${PUGI_SRC_DIR} ${OPENGL_INCLUDE_DIRS})

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)


QT5_ADD_RESOURCES(QTCRASH_Resources qresources.qrc)

add_executable(qtcrash main.cpp ${QTCRASH_Resources})
qt5_use_modules(qtcrash Gui Qml Quick OpenGL)
