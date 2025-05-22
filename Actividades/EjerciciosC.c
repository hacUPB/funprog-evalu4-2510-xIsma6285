float calcularPromedio(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return (float)suma / tam;
}

void ordenarBurbuja(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int valorMaximo(int arr[], int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
