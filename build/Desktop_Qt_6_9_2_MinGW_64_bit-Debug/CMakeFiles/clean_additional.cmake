# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\deletingMultilineComments_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\deletingMultilineComments_autogen.dir\\ParseCache.txt"
  "deletingMultilineComments_autogen"
  )
endif()
