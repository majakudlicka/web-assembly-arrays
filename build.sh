rm build/ -rf
mkdir build
cd build
cmake ../cpp
make
mv sum.js ../web/gen/
mv hello.wasm ../web/gen/
