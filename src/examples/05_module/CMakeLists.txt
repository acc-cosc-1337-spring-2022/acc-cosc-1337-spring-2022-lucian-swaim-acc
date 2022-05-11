add_library(ex_05_01_library "payroll.cpp" "payroll.h" "die.cpp" "die.h" "roll.cpp" "roll.h" "shooter.cpp" "shooter.h")
add_executable(ex_05_01_exe "main.cpp" "payroll.cpp" "die.cpp" "roll.cpp" "shooter.cpp")

