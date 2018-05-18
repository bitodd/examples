#!/bin/bash
#following is the file types
#.APS .C .H .Inc .Log .TDF .TFD .TSE .a .app .bak .bat .bsc .c .cpp .doc .dsp .dsw .fusion .h .idb .inc .lib .lst .mak .mk .obj .pch .pdb .plg .rc .s .sbr .sh .sln .sx .sx6 .sx7 .txt .vcproj 

PWD=`pwd`
DIR=$1


COMM_LIB=${PWD}/$DIR

echo ${COMM_LIB}
find ${COMM_LIB}  -name "*.H" >>cscope.files
find ${COMM_LIB}  -name "*.h" >>cscope.files
find ${COMM_LIB}  -name "*.c" >>cscope.files
find ${COMM_LIB}  -name "*.cc" >>cscope.files
find ${COMM_LIB}  -name "*.cpp" >>cscope.files
find ${COMM_LIB}  -name "*.hpp" >>cscope.files
find ${COMM_LIB}  -name "*.inc" >>cscope.files
find ${COMM_LIB}  -name "*.rc" >>cscope.files

find ${COMM_LIB}  -name "makefile.*" >>cscope.files
find ${COMM_LIB}  -name "Makefile.*" >>cscope.files
find ${COMM_LIB}  -name "Makefile" >>cscope.files
find ${COMM_LIB}  -name "*.dsp" >>cscope.files
find ${COMM_LIB}  -name "*.dsw" >>cscope.files
find ${COMM_LIB}  -name "*.mak" >>cscope.files
find ${COMM_LIB}  -name "*.lst" >>cscope.files
find ${COMM_LIB}  -name "*.mk" >>cscope.files

find ${COMM_LIB}  -name "*.s" >>cscope.files
find ${COMM_LIB}  -name "*.sx" >>cscope.files
find ${COMM_LIB}  -name "*.sx7" >>cscope.files
find ${COMM_LIB}  -name "*.S" >>cscope.files
find ${COMM_LIB}  -name "*.tcl" >>cscope.files
find ${COMM_LIB}  -name "*.py" >>cscope.files
find ${COMM_LIB}  -name "*.sh" >>cscope.files

#html
find ${COMM_LIB}  -name "*.plg" >>cscope.files
#config file
find ${COMM_LIB}  -name "*.sln" >>cscope.files
find ${COMM_LIB}  -name "*.sx6" >>cscope.files
#xml
find ${COMM_LIB}  -name "*.vcproj" >>cscope.files

#?
#find ${COMM_LIB}  -name "*.bat" >>cscope.files

cscope -bkq -i cscope.files
#cscope -bk -i cscope.files
ctags -R

