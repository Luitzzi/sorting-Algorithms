![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
<br/>
![Small-Array-Gif](/images/small-array.gif)
Welcome to the Sorting Algorithm Analyser - Offers an overview over the basic sorting algorithms and their performance

---

## Features
* **All basic sorting algorithms implemented in multiple variations**<br />

    * Simple Sorting Algorithms
      * InsertionSort LeftToRight, RightToLeft
      * BubbleSort minToFront, maxToEnd
      * SelectionSort min, max
    <br /><br />
    * Complex Sorting Algorithms
      * Quicksort firstPivot, medianPivot
      * Quicksort dual-Pivot
      * Mergesort in-situ, ex-situ
      * Mergesort iterativ
      * Heapsort min-heap, max-heap
    <br /><br />
    * Special Sorting Algorithms
      * Countsort slow, advanced
      * Mapsort
<br /><br/>
* **Validate the algorithms with the test_Sorting_Algorithm() function**
<br /><br />
* **Analyse the performance of the algorithms**
  * Choose between three different array sizes:
    * "small" - up to 250k numbers
    * "big" - up to 9 million numbers
    * because even big wasn't enough I added huge - up to 1 billion numbers
    -> All arrays are filled pseudo-randomly.<br />
    -> When the sorting is complete the time it needed is displayed.<br/>
  * Pictures of all measurements are in the /images directory

| Algorithm      | Complexity                    | 100_000  | 200_000   | 1_000_000 | 9_000_000 | 100_000_000 | 1_000_000_000 |
|----------------|-------------------------------|----------|-----------|-----------|-----------|-------------|---------------|
| Bubblesort     | bc,wc,ac: n²                  | 22sec    | 89sec     |           |           |             |               |
| Insertion Sort | bc: n wc,ac: n²               | 5sec     | 23sec     |           |           |             |               |
| Selection Sort | bc,wc,ac: n²                  | 9sec     | 36sec     |           |           |             |               |
|                |                               |          |           |           |           |             |               |
| Quicksort      | bc, ac: n log n, wc: n²       | 0.17sec  | 0.73sec   | 14.5sec   | 1316sec   |             |               |
| Quicksort DP   | bc, ac: n log n, wc: n²       | 0.006sec | 0.01sec   | 0.07sec   | 0.68sec   | 8.65sec     | 99.4sec       |
| Mergesort      | bc, wc, ac: n log n           | 0.019sec | 0.02sec   | 0.14sec   | 1.4sec    | 17.8sec     | 201.4sec      |
| Heapsort       | bc, wc, ac: n log n           | 0.17sec  | 0.036sec  | 0.22sec   | 2.2sec    |             |               |
|                |                               |          |           |           |           |             |               |
| Countsort      | n -> range [0, 127]           | 0.001sec | 0.0027sec | 0.009sec  | 0.1sec    |             |               |
| Mapsort        | ~n -> no uniform distribution | 0.09sec  | 0.34sec   | 8.57sec   | 8.57sec   | 699.9sec    |               |

## What did I learn?

* **How the algorithms work and predict the sorting-time based on their complexity**
    * With the help of the algorithm's time complexity after one measurement it is possible to calculate the constant
      depending on the hardware, as well as system factors and predict further sorting-times.
      * Example: Predict the time of bubblesort - θ(n²): <br/>
        T(n) = c * n^2<br/>
        -> T(5000) = 0.052983 sec = c * 5000² <br />
        -> c = 0.052983sec / 5000² = 2,12 * 10⁻⁹sec <br />
        -> T(100000) = 2,12 * 10⁻⁹sec * 100000² = 22.1sec - Measurement = 22.03sec<br/>
        -> With this it is possible to calculate the sorting-time of any array size. However, due to the fact that c is
           depending on the hardware and system the times will vary. During the time I measured I still used the
           computer which could result in a reduction of cpu time for the program. Therefore, c changes based on the
           processes running at the time and is biased.
    <br/><br/>        
* **Structure a 'bigger' C project**
  * Autobuild tool: CMake and previously Make
  * Organise sourcecode and header files
  <br/><br/>
* **Interchangeable algorithms**
  * Specific inputs for all algorithms
  * Interchangeable by using function pointers injected at runtime based on the user-input.
<br/><br/>
* **Limited stack size on linux**
  * Due to the stack-size limit of 8MB some algorithms resulted in a seg.fault 
    when operating with arrays with multiple numbers.
    For example Mergesort ex-situ merges the divided parts into an extra array.


![Static Badge](https://img.shields.io/badge/Author-Luis_Gerlinger-blue)