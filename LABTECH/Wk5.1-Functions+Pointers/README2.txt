Files in this directory:

 README.txt - This file.

passvalue.c - Shows using pointers to modify formal parameters
              in C's pass-by-value system.

prototype.c - Shows using prototypes so compiler can verify
              function signatures (arguments and return types).

    fnptr.c - Shows using function pointers to call functions.
              Functions are compiled code, which has to be in
              memory somewhere, and everything in memory has to
              have an address.  If it has an address, you can set
              a pointer to it, and that includes functions.
              Function pointers have type signatures, which
              should match the signatures of the functions
              pointed to.

     uhoh.c - Shows when Unix time runs out on a 32-bit integer.

     hello.h - an example of how to use header files to keep your
     	       code clean
     hello.c - an example of how to use custom headers
