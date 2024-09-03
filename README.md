# Matrix-Operation-Implementations

This repository provides different implementations of the following matrix operation:

where:

  - A and B are NxN square matrices of type double
  - A is an upper triangular matrix
  - A^T is the transpose of A
  - B^T is the transpose of B
  - '×' denotes matrix multiplication
  - '+' denotes matrix addition

## Implementations

The repository contains three implementations of the above matrix operation:

### BLAS (blas)

  This implementation utilizes the BLAS (Basic Linear Algebra Subprograms) library to perform matrix operations efficiently. BLAS provides optimized routines for matrix multiplication and addition, which are used here to achieve high performance.

  - Dependencies:
        BLAS library (e.g., ATLAS, OpenBLAS, or any other BLAS implementation)

### Naive (neopt)

  This implementation performs matrix operations using straightforward, manually coded algorithms without any optimizations. It provides a simple, clear way to understand the basic operations involved but may not be as efficient.

### Optimized (opt_m)

  This implementation improves upon the naive version by applying various performance optimization techniques. These optimizations are focused on enhancing the efficiency of the matrix operations through better memory access patterns and loop restructuring.

### Build and Run

To build the implementations, use the make command:


```bash 
make
```

This will generate the following binaries:

  - tema3_blas - for the BLAS implementation
 - tema3_neopt - for the naive implementation
 - tema3_opt_m - for the optimized implementation

### Running the Executables

To run the executables, use the following command structure:

```sh
./tema3_<mod> input
```

where <mod> is one of the modes (blas, neopt, opt_m), and input is the file containing the test descriptions.
