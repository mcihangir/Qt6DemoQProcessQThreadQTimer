# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QProcess_QThread_QTimer_Demo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QProcess_QThread_QTimer_Demo_autogen.dir\\ParseCache.txt"
  "QProcess_QThread_QTimer_Demo_autogen"
  )
endif()
