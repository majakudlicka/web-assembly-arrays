#include <emscripten.h>
#include <vector>
#include <stdint.h>
#include <memory>
#include <cstdlib>

int main(int argc, char const *argv[]) {
    emscripten_run_script("typeof window!='undefined' && window.dispatchEvent(new CustomEvent('wasmLoaded'))");
    return 0;
}

extern "C" {

    EMSCRIPTEN_KEEPALIVE
    int32_t* get5Nums (void) {

        int32_t *values = (int32_t*) std::malloc(sizeof(*values));

        for (int i=0; i<5; i++) {
            values[i] = i+1;
        }

        auto arrayPtr = &values[0];
        return arrayPtr;
    }

    EMSCRIPTEN_KEEPALIVE
    int addNums (float *buf, int bufSize) {

        int total = 0;

        for (int i=0; i<bufSize; i++) {
            total+= buf[i];
        }

        return total;
    }

        EMSCRIPTEN_KEEPALIVE
        float* getSetWASMArray (float *buf1, int buf1Size, int aNumber, float *buf2, int buf2Size) {

            float values[buf1Size];

            for (int i=0; i<buf1Size; i++) {
                values[i] = buf1[i];
            }

            printf("[WASM] Number is %d\n", aNumber);

            for (int b2=0; b2<buf2Size; b2++) {
                for (int b1=0; b1<buf1Size; b1++) {
                    values[b1] = values[b1] * buf2[b2];
                }
            }

            auto arrayPtr = &values[0];
            return arrayPtr;
        }
}
