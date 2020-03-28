if [[ $# = 1 ]]
then
    rm -rf CMakeFiles/
    rm cmake_install.cmake  CMakeCache.txt executable Makefile
    clear
else
    rm -rf CMakeFiles/
    rm cmake_install.cmake  CMakeCache.txt executable Makefile
    cmake .
    make
    #clear
    ./executable
fi