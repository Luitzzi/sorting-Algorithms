
Welcome to the Sorting Algorithm Analyser - Get an overview over the basic sorting algorithms and their performance

---

## Features
* **All basic sorting algorithms implemented in all possible ways**<br />

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

## What did I learn?
* **Structure a 'bigger' C project**
  * Autobuild tool: CMake and previously Make
  * Organise sourcecode and header files
  <br/><br/>
* **Interchangeable algorithms**
  * Specific inputs for all algorithms
  * Interchangeable by using function pointers injected at runtime based on the user-input.
<br/><br/>
* **How the algorithms work of course**