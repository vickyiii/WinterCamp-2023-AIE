// Copyright (C) 2022 Advanced Micro Devices, Inc
//
// SPDX-License-Identifier: MIT

#include <adf.h>
#include "system_settings.h"

/*
Matrix A dimensions -> 16x8
Matrix B dimensions ->  8x8
*/

void matmult_int16(
  input_window_int16* __restrict matA,
  input_window_int16* __restrict matB,
  output_window_int16* __restrict matC) {
   
   // holds the first 32 elements of matA, xbuff will be used for matA
   v32int16 buf_matA = window_readincr_v32(matA);
   // Holds 32 elements of matB, ybuff will be used for matB
   v16int16 buf_matB = undef_v16int16();
   // 16 accumulator registers
   v16acc48 acc0 = undef_v16acc48();
   v16acc48 acc1 = undef_v16acc48();
   // 16 lane registers for C even rows
   v16int16 group_0 = undef_v16int16();
   // 16 lane registers for C odd rows
   v16int16 group_1 = undef_v16int16();

   // (xbuff, xstart, xoffsets, xoffsets_hi, xsquare, zbuff, zstart, zoffsets, zoffsets_hi, zstep)
   #define IMUL \
     buf_matB = window_readincr_v16(matB); \
     acc0 = mul16(buf_matA,  0, 0x10101010, 0x54545454, 0x1010, buf_matB, 0, 0x76543210, 0x76543210, 8);\
     acc1 = mul16(buf_matA, 16, 0x10101010, 0x54545454, 0x1010, buf_matB, 0, 0x76543210, 0x76543210, 8)

   // (acc, xbuff, xstart, xoffsets, xoffsets_hi, xsquare, zbuff, zstart, zoffsets, zoffsets_hi, zstep)
   #define IMAC(Start1) \
     buf_matB = window_readincr_v16(matB);\
     acc0 = mac16(acc0, buf_matA,  Start1     , 0x10101010, 0x54545454, 0x1010, buf_matB, 0, 0x76543210, 0x76543210, 8);\
     acc1 = mac16(acc1, buf_matA,  Start1 + 16, 0x10101010, 0x54545454, 0x1010, buf_matB, 0, 0x76543210, 0x76543210, 8)

   for (unsigned int i=0; i<F_Ra/4; i++)  // Each iteration computes 4 rows of C
   chess_prepare_for_pipelining
   chess_loop_range(4,)
   {
     IMUL;
     IMAC(2);
     IMAC(4);
     IMAC(6);
     window_decr_v32(matB, 2); // reset B pointer
     buf_matA = window_readincr_v32(matA); // reads the next 4 rows of A
     // shift round saturate
     group_0 = srs(acc0, 0);
     window_writeincr(matC, group_0);
     group_1 = srs(acc1, 0);
     window_writeincr(matC, group_1);
   }
}
