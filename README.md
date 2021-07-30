# 排序演算法比較

**Github 連結:** <https://github.com/xwk1246/sort-compare>

## 系統環境

**OS:** Manjaro 21.0.2 Ornara

**Kernel:** x86_64 Linux 5.10.30-1-MANJARO

**CPU:** Intel Core i7-4790K @ 8x 4.4GHz

**GPU:** GeForce GTX 1070

**RAM:** 16GB DDR3 1866MHz

## 資料集生成方法

### dataset1

使用 rand 函式生成範圍內整數並寫入檔案

```c
int randint(int dataSize) {
    int x;
    int i;
    FILE* fp = fopen("dataset1.txt", "w"); //以寫入模式開啟檔案，如不存在則新建檔案。
    srand(time(NULL)); //以時間來設定rand種子
    for (i = 0; i < dataSize; i++) { //重複產生1000000筆整數
        x = rand() % 10000000; //隨機範圍為10000000以內整數
        fprintf(fp, "%d\n", x); //寫入檔案並換行
    }
    fclose(fp); //關閉檔案
    return 0;
}
```

### dataset2

```c
int randstring(int dataSize) {
    int x;
    int i, j;
    FILE* fp = fopen("dataset2.txt", "w"); //以寫入模式開啟檔案，如不存在則新建檔案。
    srand(time(NULL)); //以時間設定rand種子
    for (i = 0; i < dataSize; i++)     {
        for (j = 0; j < 100; j++)         {
            x = rand() % ('z' - 'A' + 1); //產生ASCII 'A'到'z'字元
            while (x >= 26 && x <= 32) { //排除符號
                x = rand() % ('z' - 'A');
            }
            fprintf(fp, "%c", 'A' + x); //寫入檔案
        }
        fprintf(fp, "\n");
    }
    fclose(fp); //關閉檔案
    return 0;
}
```

## 排序法

### Quicksort

Quick Sort 的想法是，先找一個基準點，然後派兩個代理人分別從資料的兩邊開始往中間找，如果右邊找到一個值比基準點小，左邊找到一個值比基準點大，就讓他們互換。反覆找並互換，直到兩個人相遇。然後再將相遇的點跟基準點互換。重複遞迴執行。

#### partition 函式

用來將陣列分成左右兩個部份，取其中一位為 pivot，將小於 pivot 的數放在 pivot 左邊，大於 pivot 的數放在右邊。

```pseudocode
function partitionFunc(left, right, pivot)
   leftPointer = left
   rightPointer = right - 1
   while True do
      while A[++leftPointer] < pivot do //從左邊往右找第一個小於pivot的值
         //do-nothing
      while rightPointer > 0 && A[--rightPointer] > pivot do　//從右邊找第一個大於pivot的值
         //do-nothing
      if leftPointer >= rightPointer　//當左右兩個指標相遇時中止迴圈
         break
      else
         swap leftPointer,rightPointer　//對調找到的值，使小於pivot在左，大於pivot在右
   swap leftPointer,right　//將pivot換到中間
   return leftPointer
```

#### quicksort function

用來遞迴呼叫 partition 函式,當不可再分割時中止遞迴。

```pseudocode
procedure quickSort(left, right)
   if right-left <= 0　//當分割只有一個數
      return
   else
      pivot = A[right]　//設pivot為其中一邊
      partition = partitionFunc(left, right, pivot)　//
      quickSort(left,partition-1)　//呼叫遞迴，傳入分割位置從最左邊到中間
      quickSort(partition+1,right)　//呼叫遞迴，傳入分割位置從中間到右邊
```

### Mergesort

將原本的 Data List 切割成兩等分，將左、右的 Sublist 各自以 Merge Sort 排序，合併左右半部的兩個 Sublist 成為一個新的 Data List。

####　merge函式

用來將分割的陣列合併，複製到新陣列，比較大小，小的先放再將剩下放回原陣列。

```pseudocode
procedure merge( c as a array, a as array, b as array )
   arr1 as array
   arr2 as array
   copy a, b to arr1, arr2
   while ( arr1 and arr2 have elements )　//當兩個陣列都還有盛
      if ( arr1[0] > arr2[0] )
         add arr2[0] to the end of c　//比較a b第一項大小，小的加到原陣列
         remove arr2[0] from arr2　//刪除第一項
      else
         add arr1[0] to the end of c　//比較a b第一項大小，小的加到原陣列
         remove arr1[0] from arr1　//刪除第一項
   while ( arr1 has elements )
      add arr1[0] to the end of c　//將陣列剩下的部份都加到原陣列
      remove arr1[0] from a
   while ( arr2 has elements ) //將陣列剩下的部份都加到原陣列
      add arr2[0] to the end of c
      remove arr2[0] from arr2
```

#### mergesort function

用來呼叫分割和合併。

```pseudocode
procedure mergesort( c as array )
   if ( n == 1 ) return a
   var l1 as array = a[0] ... a[n/2] //分割陣列成兩部份，從第一項到中間
   var l2 as array = a[n/2+1] ... a[n]　//分割陣列成兩部份，從第一項到最後
   l1 = mergesort( l1 )　//合併
   l2 = mergesort( l2 ) //合併
   return merge( l1, l2 )
```



### Heapsort

建立heap，分為max heap與min heap，重複對調頭與尾並重新建立符合heap條件。

#### heapify

用來將tree從指定parent往下重新形成heap。

```c
void heapify(int tree[], int i, int n) {
    if (i >= n)
        return;
    int lChild = 2 * i + 1;
    int rChild = 2 * i + 2;
    int max = i;
    if (lChild < n && tree[lChild] > tree[max]) { //比較三個元素，找出最大者
        max = lChild;
    }
    if (rChild < n && tree[rChild] > tree[max]) {　//比較三個元素，找出最大者
        max = rChild;
    }
    if (max != i) {
        swap(tree, i, max);　//最大者與parent交換
        heapify(tree, max, n); //重新往下建立heap
    }
}
```

#### buildheap

用來將亂序的陣列由最後元素的parent依序向上執行heapify，形成heap。

```c
void buildheap(int tree[], int n) {
    int lastNode = n - 1;
    int lastParent = (lastNode - 1) / 2; //取的最後元素的parent
    int i;
    for (i = lastParent; i >= 0; i--) { //由最後parent節點往上建立heap
        heapify(tree, i, n);
    }
}
```

#### heapsort主函式

用來呼叫buildheap和heapify，完成排序。

```c
void heapSort(int tree[], int n) {
    int i;
    buildheap(tree, n); //先建立heap
    for (i = n - 1; i >= 0; i--) {
        swap(tree, i, 0); //將heap最上元素與最後對調
        heapify(tree, 0, i);　//重新建立heap
    }
}
```

## 執行時間

##### (取五次結果，同一次test使用相同測資)

#### Quicksort

```
dataset1
test1: quicksort finished in 122.00 ms
test2: quicksort finished in 121.29 ms
test3: quicksort finished in 119.80 ms
test4: quicksort finished in 124.32 ms
test5: quicksort finished in 121.83 ms
Average: 121.85

dataset2
test1: quicksort finished in 468.69 ms
test2: quicksort finished in 485.50 ms
test3: quicksort finished in 520.39 ms
test4: quicksort finished in 436.72 ms
test5: quicksort finished in 502.85 ms
Average: 482.83
```



#### Mergesort

```
dataset1
test1: mergesort finished in 169.48 ms
test2: mergesort finished in 177.72 ms
test3: mergesort finished in 171.75 ms
test4: mergesort finished in 175.42 ms
test5: mergesort finished in 192.61 ms
Average: 177.40

dataset2
test1: mergesort finished in 489.23 ms
test2: mergesort finished in 448.99 ms
test3: mergesort finished in 507.94 ms
test4: mergesort finished in 475.70 ms
test5: mergesort finished in 487.46 ms
Average: 481.86
```



#### Heapsort

```
dataset1
test1: heapsort finished in 311.15 ms
test2: heapsort finished in 310.18 ms
test3: heapsort finished in 303.47 ms
test4: heapsort finished in 321.27 ms
test5: heapsort finished in 332.52 ms
Average: 315.71

dataset2
test1: heapsort finished in 1112.90 ms
test2: heapsort finished in 958.27 ms
test3: heapsort finished in 1055.74 ms
test4: heapsort finished in 1053.85 ms
test5: heapsort finished in 1182.31 ms
Average: 1072.61
```

####　花費時間

Heapsort > Mergesort > Quicksort

#### 速度

Quicksort > Mergesort > Heapsort



## 時間複雜度

### Quicksort

- Best Case：Ο(n log n)                                
- Worst Case：Ο(n^2)　                                
- Average Case：Ο(n log n)

### Mergesort

- Best Case：Ο(n log n)                                
- Worst Case：Ο(n log n)　                                
- Average Case：Ο(n log n)

### Heapsort

- Best Case：Ο(n log n)                                
- Worst Case：Ο(n log n)　                                
- Average Case：Ο(n log n)



## 空間複雜度

### Quicksort

* O(1)

### Mergesort

* O(n)

### Heapsort

* O(1)

## 總結

第一次實做較複雜的排序法，仍有許多部份理解後無法自己寫出，也體會到排序法也是很深的一門學問，不同方法所耗費時間與佔用空間有巨大的差異，一些排序法也已經無法再用列舉的方式去理解，而且更加抽象，須再提昇自己的思考能力，將來才能撰寫更複雜的程式。

## Reference

如何撰寫虛擬碼 - <https://michaelchen.tech/blog/how-to-write-pseudocode/>

Makefile 語法和示範 - <https://hackmd.io/@sysprog/SySTMXPvl>

堆排序(Heapsort)<https://www.youtube.com/watch?v=j-DqQcNPGbE>

更快的排序演算法——快速排序 (Quick Sort) - <https://www.youtube.com/watch?v=AsQW27DT82I&t=250s>

Data Structure and Algorithms - Quick Sort - https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm

Data Structures - Merge Sort Algorithm - https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm

heapsort - https://www.youtube.com/watch?v=j-DqQcNPGbE

Time Complexities of all Sorting Algorithms - https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/

Analysis of different sorting techniques - https://www.geeksforgeeks.org/analysis-of-different-sorting-techniques/

