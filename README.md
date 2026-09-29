# Package Sorting Assignment

## Problem Statement

A logistics company receives package weights:

20, 15, 20, 10, 15, 20, 25, 10

Each package has a unique package ID.

Package IDs and weights:

| Package ID | P1 | P2 | P3 | P4 | P5 | P6 | P7 | P8 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| Weight | 20 | 15 | 20 | 10 | 15 | 20 | 25 | 10 |

## (A) Merge Sort and Quick Sort

### Merge Sort

The packages are sorted using Merge Sort by repeatedly dividing the array until each subarray contains one element and then merging the subarrays in ascending order.

### Quick Sort

The packages are sorted using Quick Sort by selecting the last element as the pivot and partitioning the array around the pivot.

The intermediate steps and final outputs are recorded in the trace and output files.

## (B) Maintaining the Original Order of Equal-Weight Packages

Stability means preserving the original relative order of packages having equal weights.

Original order of equal weights:

- Weight 10: P4 → P8
- Weight 15: P2 → P5
- Weight 20: P1 → P3 → P6

Stable sorted order:

10(P4), 10(P8), 15(P2), 15(P5), 20(P1), 20(P3), 20(P6), 25(P7)

The modified implementation preserves the relative order of packages having equal weights.

## (C) Analysis

### Duplicate Values

Both Merge Sort and Quick Sort can handle duplicate values.

### Stability

Merge Sort is stable when implemented correctly.

Standard in-place Quick Sort is not stable.

Quick Sort can be modified to preserve stability using additional storage and stable partitioning.

### Number of Comparisons

The actual number of comparisons obtained during program execution is provided in the comparison table.

### Time Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

### Space Complexity

| Algorithm | Space Complexity |
|---|---|
| Merge Sort | O(n) |
| Quick Sort | O(log n) average |

## Conclusion

Merge Sort and Quick Sort can both sort duplicate package weights. However, standard Quick Sort does not guarantee stability. When maintaining the original order of equal-weight packages is important, stable Merge Sort is suitable because it preserves the relative order of equal elements and has O(n log n) worst-case time complexity.