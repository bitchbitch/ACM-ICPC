#include <utility>
using std::swap;
 
int partition(int* array, int left, int right)
{
        int index = left;
        int pivot = array[index];       
        swap(array[index], array[right]);
        for (int i=left; i<right; i++)
        {
                if (array[i] > pivot)    // 降序
                        swap(array[index++], array[i]);
        }
        swap(array[right], array[index]);
        return index;
}
 
void qsort(int* array, int left, int right)
{
        if (left >= right) 
                return;
        int index = partition(array, left, right);
        qsort(array, left, index - 1);
        qsort(array, index + 1, right);
}
