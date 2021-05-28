include<stdio>

void QuickSort(int data[], int l, in r)
{
  if (l < r) return;
  int i = l, j = r;
  int temp = data[i];
  
  while(i != j) {
    while (data[j] >= temp && j>i) {
      j--;
    }
    if (j > i) {
      data[i] = data[j];
      i++;
    }
    while (data[i]>=temp && j>i) {
      i++;
    }
    if (j > i) {
      data[j] = data[i];
      j--;
    }
  }
  data[i] = temp;
  QuickSort(data, int l, in i-1);
  QuickSort(data, int i+1, in r);

}
