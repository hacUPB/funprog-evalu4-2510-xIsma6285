// 1. Suma todos los valores dentro del arreglo
int calcSum(int arr[], int length) {
    int total = 0;
    for (int idx = 0; idx < length; idx++) {
        total += arr[idx];
    }
    return total;
}

// 2. Obtiene el elemento más grande del arreglo
int findMax(int arr[], int length) {
    int highest = arr[0];
    for (int idx = 1; idx < length; idx++) {
        if (arr[idx] > highest) {
            highest = arr[idx];
        }
    }
    return highest;
}

// 3. Calcula el valor promedio de los elementos
float calcAverage(int arr[], int length) {
    int total = calcSum(arr, length);
    return (float) total / length;
}

// 4. Cuenta cuántos números pares contiene el arreglo
int countEvens(int arr[], int length) {
    int evens = 0;
    for (int idx = 0; idx < length; idx++) {
        if (arr[idx] % 2 == 0) {
            evens++;
        }
    }
    return evens;
}

// 5. Suma el primer elemento y el último
int sumFirstLast(int arr[], int length) {
    if (length == 0) return 0; // Arreglo vacío
    return arr[0] + arr[length - 1];
}

// 6. Encuentra el número más pequeño dentro del arreglo
int findMin(int arr[], int length) {
    int lowest = arr[0];
    for (int idx = 1; idx < length; idx++) {
        if (arr[idx] < lowest) {
            lowest = arr[idx];
        }
    }
    return lowest;
}

// 7. Calcula la suma de las diferencias entre dos arreglos
int subtractArraysSum(int arr1[], int arr2[], int length) {
    int diffSum = 0;
    for (int idx = 0; idx < length; idx++) {
        diffSum += (arr1[idx] - arr2[idx]);
    }
    return diffSum;
}

// 8. Suma todos los elementos de dos arreglos combinados
int mergeArraysSum(int arr1[], int len1, int arr2[], int len2) {
    int total = 0;
    for (int i = 0; i < len1; i++) {
        total += arr1[i];
    }
    for (int j = 0; j < len2; j++) {
        total += arr2[j];
    }
    return total;
}

// 9. Multiplica todos los valores dentro del arreglo
int productArray(int arr[], int length) {
    if (length == 0) return 0; // Evita multiplicar vacío
    int result = 1;
    for (int idx = 0; idx < length; idx++) {
        result *= arr[idx];
    }
    return result;
}

// 10. Calcula la suma y el promedio utilizando punteros
void calcSumAverage(int arr[], int length, int *sum, float *average) {
    *sum = calcSum(arr, length);
    *average = (float)(*sum) / length;
}
