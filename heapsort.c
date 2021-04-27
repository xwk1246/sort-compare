void swap(int tree[], int a, int b)
{
    int tmp;
    tmp = tree[a];
    tree[a] = tree[b];
    tree[b] = tmp;
}
void heapify(int tree[], int i, int n)
{
    if (i >= n)
        return;
    int lChild = 2 * i + 1;
    int rChild = 2 * i + 2;
    int max = i;
    if (lChild < n && tree[lChild] > tree[max])
    {
        max = lChild;
    }
    if (rChild < n && tree[rChild] > tree[max])
    {
        max = rChild;
    }
    if (max != i)
    {
        swap(tree, i, max);
        heapify(tree, max, n);
    }
}

void buildheap(int tree[], int n)
{
    int lastNode = n - 1;
    int lastParent = (lastNode - 1) / 2;
    int i;
    for (i = lastParent; i >= 0; i--)
    {
        heapify(tree, i, n);
    }
}
void heapSort(int tree[], int n)
{
    int i;
    buildheap(tree, n);
    for (i = n - 1; i >= 0; i--)
    {
        swap(tree, i, 0);
        heapify(tree, 0, i);
    }
}

//reference https://www.youtube.com/watch?v=j-DqQcNPGbE