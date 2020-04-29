# The file md5Updated.c reflects the changes made to the project due to the covid-19 crisis. The other file present was my project up until the changes were made.


### MD5 HASH ALOGRITHM
Hi and welcome to my project for the module theory of algorithms. The goal of the project is to code the MD5 message-digest algorithm. MD5 was designed by Ronald Rivest in 1991 to replace an earlier hash function MD4, and was specified in 1992 as RFC 1321

## Motivation
Well needless to say that a lot of the motivation for the project stems from the fact the project is part of my college coursework:grin:. But on a more serious note the is topic of cryptography and cryptographic hash functions in particular is really facinating to me. In many ways they underpin society as they are what allow function on the internet to exist such as secure transactions, banking, communications etc to exist. If we didn't have any way to implemement safe security on the internet then there wouldn't be much point to it. I also have a deep appreciation for the blend of computer science and mathematics involved.

## Build status
The final update is working perfectly on my system. MacOs



## Code style
Standard C code style 
 
## Usage 

It's very easy to use. First step is to compile. Here's what I used to compile my source code
      
      gcc -o md5 -O3 -lm md5Updated.c

This is just what I used. You can also use make files to compile your code. 


## Tech/framework used
C. This entire project is written in the C programming language.
## Features
Ability to select between hashing single strings or large files. Also really fast. 

## Installation
Installing it is as simple as cloning the repoistory or if you don't have git installed on your machine you can download this repoistory as a zip file. Either way once the repoisitory is on your machine you need to compile it. See the USAGE section above on how to compile

## How it works
Considering this repoistory is based on tne md5 message digest algorithm, It makes sense to talk about how it works

Important note: One basic requirement of any cryptographic hash function is that it should be computationally infeasible to find two distinct messages that hash to the same value. MD5 fails this requirement catastrophically; such collisions can be found in seconds on an ordinary home computer. However MD5 is still used to provide a checksum. A checksum is essentially a signature a file has. Lets say you download file x from a website. The website says to you that if you run this file through the md5 message digest algorithm you should get y value. So you run file x that you downloaded through the md5 message digest algorithm and you get a completely different value than the y value the website told you should expect. That means that someone has tampered with the file and that it is not safe to run on your machine. Essentially we providing a way, using the md5 message digest algorithm, for someone to verify the authenticity/validity of a file downloaded from the internet or elsehwere. It's not 100% foolproof but if someone is willing to go to all that effort to generate another file with the same checksum then there's probably bigger issues at hand. 

### Inner working of how it works
MD5 processes a variable-length message into a fixed-length output of 128 bits. The input message is broken up into chunks of 512-bit blocks (sixteen 32-bit words); the message is padded so that its length is divisible by 512. The padding works as follows: first a single bit, 1, is appended to the end of the message. This is followed by as many zeros as are required to bring the length of the message up to 64 bits fewer than a multiple of 512. The remaining bits are filled up with 64 bits representing the length of the original message, modulo 264. 

The main MD5 algorithm operates on a 128-bit state, divided into four 32-bit words, denoted A, B, C, and D. These are initialized to certain fixed constants. The main algorithm then uses each 512-bit message block in turn to modify the state. The processing of a message block consists of four similar stages, termed rounds; each round is composed of 16 similar operations based on a non-linear function F, modular addition, and left rotation.

     // Note: All variables are unsigned 32 bit and wrap modulo 2^32 when calculating
       var int s[64], K[64]
       var int i

       // s specifies the per-round shift amounts
       s[ 0..15] := { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22 }
       s[16..31] := { 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20 }
       s[32..47] := { 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23 }
       s[48..63] := { 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 }

       // Use binary integer part of the sines of integers (Radians) as constants:
       for i from 0 to 63 do
           K[i] := floor(232 × abs (sin(i + 1)))
       end for
       // (Or just use the following precomputed table):
       K[ 0.. 3] := { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee }
       K[ 4.. 7] := { 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 }
       K[ 8..11] := { 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be }
       K[12..15] := { 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 }
       K[16..19] := { 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa }
       K[20..23] := { 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 }
       K[24..27] := { 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed }
       K[28..31] := { 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a }
       K[32..35] := { 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c }
       K[36..39] := { 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 }
       K[40..43] := { 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 }
       K[44..47] := { 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 }
       K[48..51] := { 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 }
       K[52..55] := { 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 }
       K[56..59] := { 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 }
       K[60..63] := { 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 }

       // Initialize variables:
       var int a0 := 0x67452301   // A
       var int b0 := 0xefcdab89   // B
       var int c0 := 0x98badcfe   // C
       var int d0 := 0x10325476   // D

       // Pre-processing: adding a single 1 bit
       append "1" bit to message    
       // Notice: the input bytes are considered as bits strings,
       //  where the first bit is the most significant bit of the byte.[50]

       // Pre-processing: padding with zeros
       append "0" bit until message length in bits ≡ 448 (mod 512)
       append original length in bits mod 264 to message

       // Process the message in successive 512-bit chunks:
       for each 512-bit chunk of padded message do
           break chunk into sixteen 32-bit words M[j], 0 ≤ j ≤ 15
           // Initialize hash value for this chunk:
           var int A := a0
           var int B := b0
           var int C := c0
           var int D := d0
           // Main loop:
           for i from 0 to 63 do
               var int F, g
               if 0 ≤ i ≤ 15 then
                   F := (B and C) or ((not B) and D)
                   g := i
               else if 16 ≤ i ≤ 31 then
                   F := (D and B) or ((not D) and C)
                   g := (5×i + 1) mod 16
               else if 32 ≤ i ≤ 47 then
                   F := B xor C xor D
                   g := (3×i + 5) mod 16
               else if 48 ≤ i ≤ 63 then
                   F := C xor (B or (not D))
                   g := (7×i) mod 16
               // Be wary of the below definitions of a,b,c,d
               F := F + A + K[i] + M[g]  // M[g] must be a 32-bits block
               A := D
               D := C
               C := B
               B := B + leftrotate(F, s[i])
           end for
           // Add this chunk's hash to result so far:
           a0 := a0 + A
           b0 := b0 + B
           c0 := c0 + C
           d0 := d0 + D
       end for

       var char digest[16] := a0 append b0 append c0 append d0 // (Output is in little-endian)

       // leftrotate function definition
       leftrotate (x, c)
           return (x << c) binary or (x >> (32-c));


## Tests
I tested the code using a wide range of string values and file values. It works fine on my system. I tested it on large text files as well. It can do War and Peace in milliseconds.

## Credits
Notes from Dr.  Ian McLoughlin.
Psuedo code was taken from wikipedia(Note there are many approaches to the problem someone could take. The idea behind the psuedo code is to convey the general idea in code).
Reddit r/crypto.
Various medium articles on the subject.




## License
A short snippet describing the license (MIT, Apache etc)

MIT © [Ross Heaney()
