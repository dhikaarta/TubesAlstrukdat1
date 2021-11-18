#include "location.h"

int main(){
    LOCATION* x;
    x = makeArrayOfLOCATION(4, 1, 5);
    TulisLOCATION(x[0]);
    TulisLOCATION(x[1]);
    TulisLOCATION(x[2]);
    TulisLOCATION(x[3]);

    return 0;
}

