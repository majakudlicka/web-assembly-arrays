### Web assembly array example

The project has 2 demos. Demo1 is an example of a basic usage of passing an array parameter to .wasm function.
Demo2 uses `wasm-arrays` npm module and gives further (as well as more reusable) examples of passing arrays in and out of wasm.
Both demos use compiled C++ code.

Prerequisites:

You don't need a compiler to run the pre-compiled examples, but in order to change any of the underlying functions, Emscripten is recommended.
You can download the compiler toolchain and set up env as per [official instructions](https://webassembly.org/getting-started/developers-guide/) 

_Demo1_

To run: 
- cd demo1
-  npm i
 - node server.js
 - Go to `http://localhost:3000/` and you can see the result of summing the array that uses compiled C++ code under the hood. 
 - You also have function `sumUp` exposed on the window object
 
To compile:

 - `em++ sum.cpp -s WASM=1 -o sum.js` 
 
 For further info check out [this article](https://medium.com/@tdeniffel/c-to-webassembly-pass-and-arrays-to-c-86e0cb0464f5)

_Demo2_

To run: 
- cd demo2
-  npm i
 - node server.js
 - Go to `http://localhost:1337/` and you can see the result of `ccallArrays` wrapper function that wraps different functions using arrays as input or output parameters
 - Further info can be found [here](https://www.npmjs.com/package/wasm-arrays)

To compile:

`em++ example.cpp -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']" -o example.js`
