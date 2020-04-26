#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>


//Program will now have to accept command line arguements and I want this to work on any file 
//So I will need to change it up a bit

#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

// These vars will contain the hash
uint32_t h0, h1, h2, h3;


void md5(int opt, int opts, char *option){

FILE *fileToHash;
if(opt == 1)
{
  fileToHash = fopen(option, "rb");
  if(!fileToHash)
  {
    printf("error opening the file");
    return;
  }
}
else if(opts == 1)
{
  //Need to do something here
}

 // Message (to prepare)
    uint8_t *msg = NULL;
 
    // Note: All variables are unsigned 32 bit and wrap modulo 2^32 when calculating
 
    // r specifies the per-round shift amounts
 
    uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    // Use binary integer part of the sines of integers (in radians) as constants// Initialize variables:
    uint32_t k[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
 
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;
 
    // Pre-processing: adding a single 1 bit
    //append "1" bit to message    
    /* Notice: the input bytes are considered as bits strings,
       where the first bit is the most significant bit of the byte.[37] */
 
    // Pre-processing: padding with zeros
    //append "0" bit until message length in bit ≡ 448 (mod 512)
    //append length mod (2 pow 64) to message




    /*
    *
    *  Now that our variables are defined
    * Just read in the file as a message 
    * and hash!
    * 
    **/ 



}


int main(int argc, char **argv){

    printf("Hi and welcome to the MD5 Hash portal\n");
    printf("Here is how to use this portal\n");
    printf("Comile it using the command gcc -o md5 -O3 -lm md5.c\n");
    printf("You can use it on single strings or entire files");

    //Declare string value
    char *svalue = NULL;
    //declare string flag argument
    int sflag = 0;
    //declare file flag argument;
    int fflag = 0;

    int c;

    //Need to parse the command line arguments.....Use getopt to get the command line arguments
    //A while loop to loop over the arguments and process them until the user tells us to stop(-1)
    while((c = getopt (argc, argv, "s:f:")) != -1)
    {
      //Now that we have entered the loop we need to see what the user actually wants

      switch(c)
      {
        case 's':
          sflag = 1;
          svalue = optarg;
          break;
        case 'f':
          fflag = 1;
          svalue = optarg;
          break;
        case '?':
          if(optopt == 'c')
            fprintf(stderr, "Option -%c requires an argument.\n", optopt);
          else if (isprint (optopt))
            fprintf(stderr, "Unknown option `-%c'.\n", optopt);
          else 
            fprintf(stderr, "Unkown option character '\\x%x'.\n", optopt);
          return 1;
        default:
          abort();
      }
    }

    if(sflag == 9 && fflag == 0)
    {
      printf("Make to select an option, -f [filename], -s [string]\n");
      return 1;
    }

    printf("sflag = %d, fflag = %d, cvalue = %s \n", sflag, fflag, svalue);

    clock_t begin = clock();
    md5(fflag, sflag, svalue);
    clock_t end = clock();
return 0;
}
