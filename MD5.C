#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))