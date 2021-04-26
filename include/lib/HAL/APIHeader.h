#ifndef VexV5
    
    #define IS_PROS
#else
    #warning "vexcode"
    #define IS_VEXCODE
#endif

#ifdef IS_PROS
    #include "main.h"
#else
    #include "vex.h"
#endif