// Copyright (C) 2022 Advanced Micro Devices, Inc
//
// SPDX-License-Identifier: MIT

#include <adf.h>
#include "system_settings.h"

/*
Matrix A dimensions -> 16x8
Matrix B dimensions ->  8x8
*/

void matmult_int32(
    input_window_int32* __restrict matA,
    input_window_int32* __restrict matB,
    output_window_int32* __restrict matC)
{

   v16int32 buf_matA = window_readincr_v16(matA);      // holds the first 16 elements of matA
   v8int32 buf_matB = undef_v8int32();  // Holds 8 elements of matB
   v8acc80 acc1 = undef_v8acc80();   // 8 accumulator registers on even rows
   v8acc80 acc2 = undef_v8acc80();   // 8 accumulator registers on odd rows
   v8int32 row_even = undef_v8int32();   // 8 lane registers for C even rows
   v8int32 row_odd = undef_v8int32();   // 8 lane registers for C odd rows


   #define LMUL   \
   buf_matB = window_readincr_v8(matB); \
   acc1 = lmul8(buf_matA, 0, 0x00000000, buf_matB, 0, 0x76543210);\
   acc2 = lmul8(buf_matA, 8, 0x00000000, buf_matB, 0, 0x76543210)

   #define LMAC(Start1, Start2)\
   buf_matB = window_readincr_v8(matB);\
   acc1 = lmac8(acc1, buf_matA, Start1, 0x00000000, buf_matB, 0, 0x76543210);\
   acc2 = lmac8(acc2, buf_matA, Start2, 0x00000000, buf_matB, 0, 0x76543210)


   for (unsigned int i=0;i<F_Ra/2;i++)  // Each iteration computes 2 rows of C
   chess_prepare_for_pipelining
   chess_loop_range(8,)
   {
     LMUL;
     LMAC(1,9);
     LMAC(2,10);
     LMAC(3,11);
     LMAC(4,12);
     LMAC(5,13);
     LMAC(6,14);
     LMAC(7,15);

     buf_matA = window_readincr_v16(matA); // reads the next 2 rows of A
     window_decr_v8(matB, 8); // reset B pointer
     // shift round saturate
     row_even = srs(acc1, 0);
     window_writeincr(matC, row_even); // Writes 1 row of C
     row_odd = srs(acc2, 0);
     window_writeincr(matC, row_odd); // Writes the next row of C
   }
}
