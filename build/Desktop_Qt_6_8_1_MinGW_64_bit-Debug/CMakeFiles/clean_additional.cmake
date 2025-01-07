# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NSE_DashBoard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NSE_DashBoard_autogen.dir\\ParseCache.txt"
  "NSE_DashBoard_autogen"
  )
endif()
