#include<iostream>

int binary(int start, int end, int key, int* arr) {
    int ret = -1;  // 未搜索到数据返回-1下标
    int mid;
    while (start <= end) {
        mid = start + ((end - start) >> 1);  // 直接平均可能会溢出，所以用这个算法
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else {  // 最后检测相等是因为多数搜索情况不是大于就是小于
            ret = mid;
            break;
        }
    }
    return ret;  // 单一出口
}

int main(void) {
    int arr[6] = {-1, 0, 3, 5, 9, 12};
    int res = binary(0, 5, 5, arr);
    std::cout << res;
    return 0;
}