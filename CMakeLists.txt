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
    unit_tests/test_isQuoteEscaped.cpp
    isQuoteEscaped.cpp
)

target_link_libraries(test_isQuoteEscaped Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_isQuoteEscaped PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#################################################################################################
add_executable(test_printErrorMessage
    unit_tests/test_printErrorMessage.cpp
    printErrorMessage.cpp
    error.cpp
)

target_link_libraries(test_printErrorMessage Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_printErrorMessage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_hasNoErrors
    unit_tests/test_hasNoErrors.cpp
    hasNoErrors.cpp
    printErrorMessage.cpp
    error.cpp
)

target_link_libraries(test_hasNoErrors Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_hasNoErrors PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_checkCountArgs
    unit_tests/test_checkCountArgs.cpp
    checkCountArgs.cpp
)

target_link_libraries(test_checkCountArgs Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_checkCountArgs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_checkExtension
    unit_tests/test_checkExtension.cpp
    checkExtension.cpp
)

target_link_libraries(test_checkExtension Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_checkExtension PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_readInputFile
    unit_tests/test_readInputFile.cpp
    readInputFile.cpp
)

target_link_libraries(test_readInputFile Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_readInputFile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_checkSizeOfFile
    unit_tests/test_checkSizeOfFile.cpp
    checkSizeOfFile.cpp
)

target_link_libraries(test_checkSizeOfFile Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_checkSizeOfFile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_checkPresenceOfDirective
    unit_tests/test_checkPresenceOfDirective.cpp
    checkPresenceOfDirective.cpp
)

target_link_libraries(test_checkPresenceOfDirective Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_checkPresenceOfDirective PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_createOutputFile
    unit_tests/test_createOutputFile.cpp
    createOutputFile.cpp
)

target_link_libraries(test_createOutputFile Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_createOutputFile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_generateErrorMessage
    unit_tests/test_errorMessage.cpp
    error.cpp
)

target_link_libraries(test_generateErrorMessage Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_generateErrorMessage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_writingStringConstant
    unit_tests/test_writingStringConstant.cpp
    writingStringConstant.cpp
    isQuoteEscaped.cpp
)

target_link_libraries(test_writingStringConstant Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_writingStringConstant PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_writingSymbolicConstant
    unit_tests/test_writingSymbolicConstant.cpp
    writingSymbolicConstant.cpp
    isQuoteEscaped.cpp
)

target_link_libraries(test_writingSymbolicConstant Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_writingSymbolicConstant PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_writingOneLineComment
    unit_tests/test_writingOneLineComment.cpp
    writingOneLineComment.cpp
)

target_link_libraries(test_writingOneLineComment Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_writingOneLineComment PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_findingEndMultiLineComment
    unit_tests/test_findingEndMultiLineComment.cpp
    findingEndMultiLineComment.cpp
)

target_link_libraries(test_findingEndMultiLineComment Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_findingEndMultiLineComment PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################
add_executable(test_findingEnteringOtherStatusFlags
    unit_tests/test_findingEnteringOtherStatusFlags.cpp
    findingEnteringOtherStatusFlags.cpp
    isQuoteEscaped.cpp
    checkPresenceOfDirective.cpp
)

target_link_libraries(test_findingEnteringOtherStatusFlags Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_findingEnteringOtherStatusFlags PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#################################################################################################

add_executable(test_removeMultiLineComment
    unit_tests/test_removeMultiLineComment.cpp
    removeMultiLineComment.cpp
    checkPresenceOfDirective.cpp
    findingEnteringOtherStatusFlags.cpp
    findingEndMultiLineComment.cpp
    writingOneLineComment.cpp
    writingStringConstant.cpp
    writingSymbolicConstant.cpp
    isQuoteEscaped.cpp
)

target_link_libraries(test_removeMultiLineComment Qt${QT_VERSION_MAJOR}::Test)
target_include_directories(test_removeMultiLineComment PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
