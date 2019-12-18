"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""
def maxHeapify(arr, n, i):
    """
    将一个arr调整为大顶堆，in-place地更改。
    param arr: heap
    param n: 需要调整的heap size
    param i: 当前子堆的根节点
    """
    large = i
    lchild, rchild = 2*i+1, 2*i+2
    if lchild < n and arr[lchild] > arr[large]:
        large = lchild
    if rchild < n and arr[rchild] > arr[large]:
        large = rchild
    if large != i:
        arr[i], arr[large] = arr[large], arr[i]
        maxHeapify(arr, n, large)

def buildMaxHeap(arr):
    """
    堆排序前，初始化，构建一个大顶堆，从最后一个非叶子结点开始
    """
    for i in range(int(len(arr)/2), -1, -1):
        maxHeapify(arr, len(arr), i)

def heapSort(arr):
    # 初始化大顶堆
    buildMaxHeap(arr)
    # 一个个地将堆顶元素交换到数组后面，并且调整堆
    for i in range(len(arr)-1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        maxHeapify(arr, i, 0)
