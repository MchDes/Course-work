mkdir build
cd build
#cmake -DCMAKE_CXX_COMPILER=clang++ ../
cmake  -G "MinGW Makefiles" ../.
make -j 8
cd ..