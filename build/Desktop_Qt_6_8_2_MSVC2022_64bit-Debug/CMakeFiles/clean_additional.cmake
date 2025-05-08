# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Bagaj_autogen"
  "CMakeFiles\\Bagaj_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Bagaj_autogen.dir\\ParseCache.txt"
  )
endif()
