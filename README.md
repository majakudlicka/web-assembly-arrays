### Web assembly array example

To run: 
-  npm i
 - node server.js
 
To compile from c++ to .wasm:

- Download the toolchain and set up env as per [official instructions](https://webassembly.org/getting-started/developers-guide/)
 - `em++ sum.cpp -s WASM=1 -o sum.js` 
 
 _Inspired by_ [this article](https://medium.com/@tdeniffel/c-to-webassembly-pass-and-arrays-to-c-86e0cb0464f5)
