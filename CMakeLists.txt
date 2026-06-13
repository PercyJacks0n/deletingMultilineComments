cmake_minimum_required(VERSION 3.16)

project(deletingMultilineComments LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(deletingMultilineComments
  main.cpp
  ErrorType.h
  LocationFlagInCode.h
  Error.h
  error.cpp
  Functions.h
  checkCountArgs.cpp
  checkExtension.cpp
  readInputFile.cpp
  checkSizeOfFile.cpp
  checkPresenceOfDirective.cpp
  createOutputFile.cpp
  printErrorMessage.cpp
  isQuoteEscaped.cpp
  removeMultiLineComment.cpp
  findingEnteringOtherStatusFlags.cpp
  findingEndMultiLineComment.cpp
  writingOneLineComment.cpp
  writingStringConstant.cpp
  writingSymbolicConstant.cpp
  hasNoErrors.cpp

)

target_link_libraries(deletingMultilineComments Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS deletingMultilineComments
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)
################################################################################################
add_executable(test_isQuoteEscaped
    tests/test_isQuoteEscaped.cpp
    isQuoteEscaped.cpp
)

target_link_libraries(test_isQuoteEscaped Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_isQuoteEscaped PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#################################################################################################
add_executable(test_printErrorMessage
    tests/test_printErrorMessage.cpp
    printErrorMessage.cpp
    error.cpp
)

target_link_libraries(test_printErrorMessage Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_printErrorMessage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_hasNoErrors
    tests/test_hasNoErrors.cpp
    hasNoErrors.cpp
    printErrorMessage.cpp
    error.cpp
)

target_link_libraries(test_hasNoErrors Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_hasNoErrors PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
