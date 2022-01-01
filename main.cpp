#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

/*
struct Subarray{
    int low;
    int high;
    int maxsum;

    Subarray(){
        low = -1;
        high = -1;
        maxsum = 0;
    }
};
*/

void Merge(int A[], int p, int q, int r);
void MergeSort(int A[], int p, int r);
int BinarySearch(const int A[], int v, int n);
int RecursionBinarySearch(int A[], int i, int n, int v);
int** SquareMatrixMultiply(int **A, int **B, int n);
int ** SquareMatrixMultiplyRecursive(int **A, int **B, int n);
/*
Subarray FindMaximumSubarray(int A[], int low, int high);
Subarray FindMaxCrossingSubarray(int A[], int low, int mid, int high);
*/

int FindMaximumSubarray(int A[], int low, int high);
int FindMaxCrossingSubarray(int A[], int low, int mid, int high);
int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    int n = 100;
    int mas[n];
    int v = 548;
    for(int i=0; i< n; ++i) {
        int a;
        a = rand() % 1000;
        while (a == 0) { a = rand() % 1000; }
        mas[i] = a;
    }

    for(int i = 0; i < n; ++i)
        std::cout << "[" << i << "] = " << mas[i] << std::endl;
    int index = BinarySearch(mas,v,n);
    if(index != -1)
        std::cout << index <<" = "<< mas[index] << std::endl;
    else
        std::cout << "Нет такого числа" <<std::endl;

    int A[16];
    A[0] = 13;
    A[1] = -3;
    A[2] = -25;
    A[3] = 20;
    A[4] = -3;
    A[5] = -16;
    A[6] = -23;
    A[7] = 18;
    A[8] = 20;
    A[9] = -7;
    A[10] = 12;
    A[11] = -5;
    A[12] = -22;
    A[13] = 15;
    A[14] = -4;
    A[15] = 7;
    int k = 16;


    for(int i = 0; i < k; ++i)
        std::cout << "[" << i << "] = " << A[i] << std::endl;
    //Subarray array = FindMaximumSubarray(A,0,k-1);
    //std::cout << array.low << " " << array.high << " " << array.maxsum << std::endl;
    int sum = FindMaximumSubarray(A,0,k-1);
    std::cout << sum << std::endl;

    int **AA;
    int l = 10;
    AA = new int *[l];
    for(int i = 0; i < l; ++i)
      AA[i] = new int[l];
    int **BB;
    BB = new int *[l];
    for(int i = 0; i < l; ++i)
        BB[i] = new int[l];
    for(int i = 0; i <l; ++i)
        for(int j = 0; j < l; ++j){
            AA[i][j] = rand() %10;
            BB[i][j] = rand() %10;
        }
    int **C = SquareMatrixMultiply(AA,BB,l);
    for(int i = 0; i < l; ++i){
        for(int j = 0; j < l; ++j)
            std::cout << C[i][j] << " ";
        std::cout<<std::endl;
    }


    /*
    int y = 100;
    int sum = 0;
    for(int i = 1; i < y; ++i)
        sum+=y-i;
    std::cout << sum << std::endl;
    */
    //========================================================================================================//
    //2.3 Правило Горнера
    /* int temp = 0;
     for(int i = n; i>0; ++i)
         temp = a[i] + x * temp
    */
    //========================================================================================================//
    /*
    //2.2.2 Selection sort; Собственная реализация по описанию алгоритма (не из псевдокода) *Посчитать для неё (0) функцию от кол-ва элементов
    int n = 100;
    std::vector<int> mas(n);
    for(int i=0; i< n; ++i) {
        int a = rand() % 1000;
        while (a == 0)
            a = rand()%1000;
        mas[i] = a;
    }

    for(int i = 0; i < n-1; ++i) {
        int min  = i;
        for (int j = i+1; j < n; ++j) {
            if (mas[j] < mas[i])
                min = j;
        }
        std::swap(mas[i],mas[min);
    }

    for(int i=0; i < mas.size(); ++i)
        std::cout << "[" << i+1 <<"] = " << mas[i] << std::endl;


    //========================================================================================================//

    //2.1.3 Линейный поиск числа *Доказать инвариативность
    int n,v;
    std::vector<int> A(n);
    std::vector<int> ans(n);
    for(int i= 0; i < n; ++i)
        if(A[i] == v)
            ans.push_back(i);

    //========================================================================================================//
    //2.1.4 Сложение 2-n битовых довичных целых чисел
    int m = 6;
    std::vector<int> A(m);
    std::vector<int> B(m);
    std::vector<int> C(m+1);
    for (int i = 0; i < m; ++i) {
        A[i]=rand()%2;
        B[i]=rand()%2;
    }

    std::cout << std::endl;
    for (int i = 0; i < m+1; ++i) {
        C[i]=0;
    }

    int k = m/2;
    for (int i = 0; i < k; ++i) {
        std::swap(A[i],A[m-i-1]);
        std::swap(B[i],B[m-i-1]);
    }

    for(int i = 0 ; i < m; ++i){

        C[i] += A[i]+B[i];
        if(C[i] == 2){
            C[i] = 0;
            C[i+1] = 1;
        }
        else if(C[i] == 3 ){
            C[i] = 1;
            C[i+1] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        std::cout << A[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << B[i];
    }
    if(C[m+1] != 0 )
        std::cout << C[m+1];
    for (int i = m; i >= 0 ; --i) {
        std::cout << C[i];
    }
    std::cout << std::endl;

    //========================================================================================================//

    int n = 100;
    std::vector<int> mas(n);
    for(int i=0; i< n; ++i) {
        int a = rand() % 1000;
        while (a == 0)
            a = rand()%1000;
        mas[i] = a;
    }

    //Убывающая
    for(int j = 1; j < mas.size(); ++j){
        int key = mas[j];
        int i = j - 1;
        while(i>=0 && mas[i] < key){
            mas[i+1] = mas[i];
            i = i - 1;
        }
        mas[i+1] = key;
    }

    //========================================================================================================//

    //Возрастающая
    for(int j = 1; j < mas.size(); ++j){
        int key = mas[j];
        int i = j - 1;
        while(i>=0 && mas[i] > key){
            mas[i+1] = mas[i];
            i = i - 1;
        }
        mas[i+1] = key;
    }

    for(int i=0; i < mas.size(); ++i)
        std::cout << "[" << i+1 <<"] = " << mas[i] << std::endl;

    */


    //========================================================================================================//
    // BubbleSort
    /*
    int n;
    std::vector<int> A(n);
    for(int i = 0; i < n-1; ++i )
        for(int j = n; j >= i + 1; --j )
            if(A[j] < A[j - 1])
                std::swap(A[j],A[j-1]);
    return 0;
     */
    /*
    int n = 100;
    int A[n];
    for(int i = 0; i < n; ++i) {
        int a = rand() % 1000;
        while(a == 0)
            a = rand() % 1000;
        A[i] = a;
    }
    for(int i = 0; i < n; ++i)
        std::cout << "[" <<  i << "] = " << A[i] << std::endl;

    std::cout << "После сортировки" << std::endl;
    MergeSort(A,0,n-1);
    for(int i = 0; i < n; ++i)
        std::cout << "[" <<  i << "] = " << A[i] << std::endl;
    */
}
//============================================================================================================//
//Поиск подмассива грубой силой
//Доделать задачки из главы с математикой и из главы с алгоритмом переумножения матриц 4.2
//Поиск максимального подмассива за линейное время n
int LineSumSubarray(int A[], int n){
    int max_sum = 0;
    for(int i = 0; i < n; ++i){
        if(sum == 0)
            start_index = i;
        sum+=A[i];
        if(max_sum <= sum){
            max_sum = sum;
            end_index = i;
        }
        if(sum < 0)
            sum = 0;
    }
}

//Алгоритм Штрассена для умножения матриц. Работает только с квадратными матрицами размеры которой степени 2;


//Умножение матриц стандартным способом
int** SquareMatrixMultiply(int **A, int **B, int n){
    int **C;
    C = new int *[n];
    for(int i = 0; i < n; ++i)
        C[i] = new int[n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            C[i][j] = 0;
            for(int k = 0; k < n; ++k)
                C[i][j] = C[i][j]+A[i][k]*B[k][j];
        }
    return C;
}


//============================================================================================================//
// Поиск максимальной суммы подмасиива в массиве
//Возвращение только максимальной суммы элементов
int FindMaxCrossingSubarray(int A[], int low, int mid, int high){
    int left_sum = -std::numeric_limits<int>::max();
    int sum = 0;
    for (int i = mid; i >= low; --i){
        sum = sum +A[i];
        if(sum > left_sum)
            left_sum = sum;
    }
    int right_sum = -std::numeric_limits<int>::max();
    sum = 0;
    for (int j = mid + 1; j <= high; ++j){
        sum = sum +A[j];
        if(sum > right_sum)
            right_sum = sum;
    }
    return (left_sum + right_sum);
}

int FindMaximumSubarray(int A[], int low, int high){
    if(high == low)
        return A[low];
    else{
        int mid = (high + low)/2;
        int leftsum = FindMaximumSubarray(A,low,mid);
        int rightsum = FindMaximumSubarray(A,mid+1, high);
        int crosssum = FindMaxCrossingSubarray(A,low,mid,high);
        if(leftsum >= rightsum && leftsum >= crosssum)
            return leftsum;
        else if(rightsum >= leftsum && rightsum >= crosssum)
            return  rightsum;
        else
            return crosssum;
    }
}
/*
//Возвращение индексов подмассива + суума элементов
Subarray FindMaxCrossingSubarray(int A[], int low, int mid, int high){
    int left_sum = -std::numeric_limits<int>::max();
    int sum = 0;
    int max_left = -1;
    for (int i = mid; i >= low; --i){
        sum = sum + A[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -std::numeric_limits<int>::max();
    int max_right = -1;
    sum = 0;
    for (int j = mid + 1; j <= high; ++j){
        sum = sum + A[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    Subarray crossSubarray;
    crossSubarray.high = max_right;
    crossSubarray.low = max_left;
    crossSubarray.maxsum = left_sum + right_sum;
    return crossSubarray;
}

Subarray FindMaximumSubarray(int A[], int low, int high){
    if(high == low){
        Subarray array;
        array.maxsum = A[low];
        array.low = low;
        array.high = high;
        return array;
    }
    else{
        Subarray rightArray;
        Subarray leftArray;
        Subarray crossArray;
        int mid = (low + high)/2;
        rightArray = FindMaximumSubarray(A,low,mid);
        leftArray = FindMaximumSubarray(A,mid+1,high);
        crossArray = FindMaxCrossingSubarray(A,low,mid,high);
        if(leftArray.maxsum >= rightArray.maxsum && leftArray.maxsum >= crossArray.maxsum)
            return leftArray;
        else if(rightArray.maxsum >= leftArray.maxsum && rightArray.maxsum >= crossArray.maxsum)
            return rightArray;
        else
            return crossArray;
    }
}
*/

//============================================================================================================//
//Сортировка MergeSort реализация
void Merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; ++i)
        L[i] = A[p+i];
    for(int i = 0; i < n2; ++i)
        R[i] = A[q+i+1];

    int i = 0;
    int j = 0;
    int k = p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int p, int r){
    if(p >= r)
        return;
    int q = p + (r - p)/2;
    MergeSort(A,p,q);
    MergeSort(A,q+1,r);
    Merge(A,p,q,r);

}
//2.3.5
//Бинарный поиск итерациями
int BinarySearch(const int A[], int v, int n){
    int i = 0;
    while(i <= n){
        int mid =(n+i)/2;
        if(A[mid] == v)
            return mid;
        else if(A[mid] < v)
            i =  mid + 1;
        else
            n = mid - 1;
    }
    return -1;
}
//Бинарный поиск рекурсией
int RecursionBinarySearch(int A[], int i, int n, int v){
    if(i > n)
        return -1;
    int mid = (n + i)/2;
    if(A[mid] == v)
        return mid;
    else if(A[mid] > v)
        return RecursionBinarySearch(A,i,mid-1,v);
    else
        return RecursionBinarySearch(A,mid+1,n,v);
}

//2.3.7 nLgn для множества из n целых чисел и другого целого числа имеется ли в множестве два элемент сумма которых равна x;
