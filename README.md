# 排序演算法比較

#### 資工一 409410034 蕭文愷

**Github 連結:** https://github.com/xwk1246/sort-compare

### 系統環境：

​	**OS:** Manjaro 21.0.2 Ornara

​	**Kernel:** x86_64 Linux 5.10.30-1-MANJARO

​	**CPU:** Intel Core i7-4790K @ 8x 4.4GHz

​	**GPU:** GeForce GTX 1070

​	**RAM:** 16GB DDR3 1866MHz

#### 資料集生成方法：

	##### 	dataset1:

​	使用rand函式生成範圍內整數並寫入檔案

```c
int randint(int dataSize) {
    int x;
    int i;
    FILE* fp = fopen("dataset1.txt", "w"); //以寫入模式開啟檔案，如不存在則新建檔案。
    srand(time(NULL)); //以系統時先來設定rand種子
    for (i = 0; i < dataSize; i++) { //重複產生1000000筆整數
        x = rand() % 10000000; //隨機範圍為10000000以內整數
        fprintf(fp, "%d\n", x); //寫入檔案並換行
    }
    fclose(fp); //關閉檔案
    return 0;
}		
```

##### 	dataset2:

```c
int randstring(int dataSize) {
    int x, i, j;
    FILE* fp = fopen("dataset2.txt", "w"); //開啟檔案
    srand(time(NULL)); //以系統時先來設定rand種子
    for (i = 0; i < dataSize; i++) { //重複產生1000000筆字母字串
        for (j = 0; j < 100; j++) { //重複100次每一位字母
            x = rand() % 52; //隨機
            while (x >= 26 && x <= 32) {
                x = rand() % 52;
            }
            fprintf(fp, "%c", 'A' + x);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
```



​	

### 排序法：

#### 	Quicksort:

​		

#### 	Mergesort:



#### 	Heapsort:



### Reference:

如何撰寫虛擬碼 - https://michaelchen.tech/blog/how-to-write-pseudocode/

Makefile 語法和示範 - https://hackmd.io/@sysprog/SySTMXPvl

堆排序(Heapsort)https://www.youtube.com/watch?v=j-DqQcNPGbE

更快的排序演算法——快速排序 (Quick Sort) - https://www.youtube.com/watch?v=AsQW27DT82I&t=250s