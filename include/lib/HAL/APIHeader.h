#ifndef VexV5
    #define IS_PROS
#else
    #define IS_VEXCODE
#endif

#ifdef IS_PROS
    #include "main.h"
#else
    #include "vex.h"
#endif