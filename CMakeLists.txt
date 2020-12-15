CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(QHex LANGUAGES CXX)

FIND_PACKAGE(Qt5Widgets REQUIRED)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

ADD_LIBRARY(QHexWidget
        src/chunks.cpp
        src/commands.cpp
        src/qhexedit.cpp
        )
TARGET_INCLUDE_DIRECTORIES(QHexWidget PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        )
TARGET_LINK_LIBRARIES(QHexWidget PRIVATE Qt5::Widgets)
TARGET_LINK_LIBRARIES(QHexWidget PRIVATE Qt5::Core)
TARGET_LINK_LIBRARIES(QHexWidget PRIVATE Qt5::Gui)

ADD_EXECUTABLE(QHex
        example/main.cpp
        example/mainwindow.cpp
        example/optionsdialog.cpp
        example/searchdialog.cpp
        )
TARGET_LINK_LIBRARIES(QHex PRIVATE QHexWidget)
TARGET_LINK_LIBRARIES(QHex PRIVATE Qt5::Widgets)
TARGET_LINK_LIBRARIES(QHex PRIVATE Qt5::Core)
TARGET_LINK_LIBRARIES(QHex PRIVATE Qt5::Gui)

FILE(COPY example/images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images)
FILE(COPY example/translations/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/translations)