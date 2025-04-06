# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ExpenseTracker_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ExpenseTracker_autogen.dir/ParseCache.txt"
  "ExpenseTracker_autogen"
  )
endif()
