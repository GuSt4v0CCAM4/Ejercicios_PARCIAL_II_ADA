#include <iostream>
using namespace std;
class MergeSort{
private:
    int* arreglo;
    int size;
public:
    MergeSort(int* array, int arraysize){
        arreglo = array;
        size = arraysize;
    }
    void sort(){
        mergeSort(0, size -1);
    }
    void merge(int left, int middle, int right){
        int i,j,k;
        int n1 = middle - left +1;
        int n2 = right - middle;
        int* leftArray = new int[n1];
        int* rightArray = new int[n2];

        for (i = 0; i < n1; i++)
            leftArray[i] = arreglo[left + i];
        for (j = 0; j < n2; j++)
            rightArray[j] = arreglo[middle + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arreglo[k] = leftArray[i];
                i++;
            } else {
                arreglo[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arreglo[k] = leftArray[i];
            i++;
            k++;
        }
        while (j < n2) {
            arreglo[k] = rightArray[j];
            j++;
            k++;
        }

        delete[] leftArray;
        delete[] rightArray;

    }
    void mergeSort(int left, int right){
        if(left < right){
            int middle = left + (right - left)/2;
            mergeSort(left, middle);
            mergeSort(middle + 1, right);
            merge(left, middle, right);
        }
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;

    }
    int mediana(){
        if((size) == 1){
            //cout<<"La mediana es: "<<arreglo[0]<<endl;
            return arreglo[0];
        } else if ((size) % 2 == 0){
            int a, b, c;

            a = (size)/2;
            b = a +1;
            c = (arreglo[a-1] + arreglo[b-1])/2;
            //cout<<"La mediana es: "<<c<<endl;
            return c;
        }else if ((size) % 2 == !0){
            int a;
            a = (size+1)/2;
            //cout<<"La mediana es: "<<arreglo[a]<<endl;
            return arreglo[a-1];
        }
    }
};
int main(){
    int size = 7, i=0;
    int arr[7];

    while(size--){

        cin>>arr[i];
        MergeSort mergeSort(arr, i+1);
        mergeSort.sort();
        cout<<mergeSort.mediana()<<endl;
        i++;
    }

    return 0 ;
}

