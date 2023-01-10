---
layout: default
---

# Matrix Multiplication Source Code Description

This document describes the kernel code to compute the matrix multiplication of A(8,8) x B(8,8) for four different data types. Depending on the data type, we tweak the algorithm to suit best the architecture of the AIE Tile, this slightly variation is mostly in the form of computing partial results to leverage the accumulator and data path of the vector processor architecture.

Before looking at each kernel in detail, it is important to highlight that we are going to be using advance MAC intrinsic functions to achieve our goal. This is well described in the [Full Lane Addressing Scheme documentation](https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_intrinsics/intrinsics/group__vect__mult__intrinsics__explained.html). We map matrix A and B to the X buffer (up to 1024-bit wide) and the Z buffer (256-bit wide), Y buffer is not used.  

The operations in advanced MAC can be described using lanes and columns. The number of columns is the number of multiplications that are done per output lane, with each of these multiplications added together. The product of lanes and columns gives the MACs/cycle. The maximum number of MACs/cycle for a given data type is described in this [table](https://docs.xilinx.com/r/en-US/am009-versal-ai-engine/Functional-Overview?section=gjd1525480035443__table_vfm_pr5_w2b).

The number of lanes and columns is a function of the data types we use. Note that not all combination of data types as supported for X and Z buffers. For this lab, we are going to use the same data type for both matrix A and matrix B.

## Matrix Multiplication

This section is only intended to provide context in order to understand the following sections. We all are familiar with matrix multiplication. The inner product of each row of the first matrix times each  column of the second matrix produces one element of the result. This is shown in the following animation.

TODO add matrix multiplication animation.

Matrix multiplication has a high computation intensity due to the number of required operations to compute the result. Accelerating matrix multiplication is well covered in the literature both for CPU and GPU.


## Matrix Multiplication on the AI Engine Tile

In the remainder of this document, we cover how the matrix multiplication is performed in the AI Engine tile for 4 different data types

* float
* int32
* int16
* int8

For simplicity, we consider the size of the matrices to be $$A_{8,8} \times B_{8,8} = C_{8,8}$$. The computation described in following section is also valid for matrix A with rows that are multiple of 8, in fact the the source code for the labs uses $$A{16,8}$$.

Please note that for a given data type, there may be other ways of breaking down the computation on the AI Engine tile. We only describe one of them.

For each data type we are going to fill the following table:

| MACs/cycles | lanes | columns | MatA maps to | MatB maps to | Elements on X buffer | Elements on Z buffer | Accumulator | mac intrinsic |
|-------------|-------|---------|--------------|--------------|----------------------|----------------------|-------------|---------------|
|             |       |         |              |              |                      |                      |             |               |

This table will help us drive the discussion about how the matrix multiplication is mapped to the AI Engine tile.

### Matrix Multiplication int32 and float

For int32 and float data types the computation is done in the same way. However, for float, the computation is done in the floating-point vector processor data path, whereas for int32 the computation is done in the fixed-point vector processor data path.

Based on the documentation, we know that for int32 and float (real data types only) the maximum number of MACs is 8. So, we need to find out a way of parallelizing the computation doing 8 multiply accumulate operations per cycle.


| MACs/cycles | lanes | columns | MatA maps to | MatB maps to | Elements on X buffer | Elements on Z buffer | Accumulator | mac intrinsic |
|-------------|-------|---------|--------------|--------------|----------------------|----------------------|-------------|---------------|
|     8       |  8    |   1     | X buffer     | Z buffer     |         16           |          8           |     acc80   |  [Link](https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_intrinsics/intrinsics/group__vect__mult__32x32.html#ga63b63eacca61ba92cd8b314bc6a27c41) |


What the table tells us is that at any given time we can only access to 16 elements of matrix A (2 rows) and 8 elements of matrix B (1 row). So, it is not possible to perform a complete inner product, hence, we can generate partial results and store the such partial result on the accumulator or register (in the case of the floating-point vector processor). 

At a high level, in each iteration we multiply one element of X buffer times all of the elements in Z buffer, add to the previous computation and move to the next row of matrix B, when all of the rows of B are completed, we have the result of the inner product. At this point, we can move to the next two rows of matrix A. Note, that as we have 16 elements in X buffer we can do the same operation for the odd rows of matrix A without having to load from memory again, thus minimizing data movement.


TODO add float/int32 matrix multiply animation

When writing to memory, we need to reduce the precision from 80-bits to 32-bits, this is done using the SRS path.

### Matrix Multiplication int16

TODO

### Matrix Multiplication int8

Based on the documentation, we know that for int8 (real data types only) the maximum number of MACs is 128. So, we need to find out a way of parallelizing the computation doing 128 multiply accumulate operations per cycle.


| MACs/cycles | lanes | columns | MatA maps to | MatB maps to | Elements on X buffer | Elements on Z buffer | Accumulator | mul intrinsic |
|-------------|-------|---------|--------------|--------------|----------------------|----------------------|-------------|---------------|
|     128     |  16   |   8     | Z buffer     | A buffer     |         64           |          32          |     acc48   |  [Link](https://www.xilinx.com/htmldocs/xilinx2022_2/aiengine_intrinsics/intrinsics/group__vect__mult__8x8.html#ga8676a949b7605d65c4dc6974c793d37b) |


What the table tells us is that at any given time we can access to 32 elements of matrix A (4 rows) and 64 elements of matrix B (8 rows). So, it is possible to perform a complete inner product, at least for a subset of matrix A.

At a high level, in each iteration we produce the inner product of two rows of matrix A and all columns of matrix B. Then, we can move to the next 4 rows of matrix A. Note, that as we have 32 elements of matrix A in Z buffer we can do the same operation for the rows i+2 and i+3 of matrix A without having to load from memory again, thus minimizing data movement.

TODO add int8 matrix multiply animation

---------------------------------------
<p align="center">Copyright&copy; 2023 Advanced Micro Devices</p>