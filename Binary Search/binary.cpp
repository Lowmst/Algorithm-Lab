#include<iostream>

int binary(int start, int end, int key, int* arr) {
    int ret = -1;  // δ���������ݷ���-1�±�
    int mid;
    while (start <= end) {
        mid = start + ((end - start) >> 1);  // ֱ��ƽ�����ܻ����������������㷨
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else {  // ������������Ϊ��������������Ǵ��ھ���С��
            ret = mid;
            break;
        }
    }
    return ret;  // ��һ����
}

int main(void) {
    int arr[6] = {-1, 0, 3, 5, 9, 12};
    int res = binary(0, 5, 5, arr);
    std::cout << res;
    return 0;
}