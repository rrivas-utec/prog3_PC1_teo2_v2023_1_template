# PC1: Práctica Calificación 1  
**course:** Programación III  
**unit:** 1 y 2  
**cmake project:** prog3_PC1_teo2_v2023_1
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `P1.cpp, P1.h`
    - `P2.cpp, P2.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - clases, punteros y sobrecarga de operadores y template de clases (14 points)
Crear un template de clase `FlexMatrix` que cuente con 3 parámetros: un parámetro `tipo` para definir el tipo de dato de los valores de la matriz, adicionalmente 2 parámetros `no-tipo` que definan las dimensiones iniciales (_rows y columns) de la matriz, debe contar además con un constructor que cuente con 2 parámetros: el primero del tipo `const char*` que recibirá una cadena de caracteres con valores numéricos separados por un carácter el que será definido por un segundo parámetro del tipo `char`.

los valores numéricos deberán ser almacenados en un arreglo dinámico de dimensión `_rows * columns`.

El template de clase debe contar con los siguientes métodos y operadores:
- `rows()` retornaran la cantidad de columnas
- `cols()` retornaran la cantidad de columnas
- `resize(int _rows, int _cols)` permitirá redimensionar la matriz, si la dimension se reduce se descarta los valores anteriores y si se incrementa los valores faltantes se completan con ceros.
- `operador()(int row, int col)` que retorne el valor ubicado en la fila y columna indicada en `row, col`.
- `begin()` que retorne el puntero al primer valor `(0,0)` de la matriz.
  
**Use Case #1:**  
```cpp
FlexMatrix<int, 3, 3> fm1("1,2,3,4,5,6", ',');
for (int i = 0; i < fm1.rows(); ++i) {
    for (int j = 0; j < fm1.cols(); ++j)
        cout << setw(3) << fm1(i, j);
    cout << endl;    
}
/* resultado:
1  2  3
4  5  6
0  0  0
 */
```
**Use Case #2:**
```cpp
FlexMatrix<int, 3, 3> fm1("1 2 3 4 5 6", ' ');
cout << fm1;
/* resultado:
1  2  3
4  5  6
0  0  0
 */
```
**Use Case #3:**
```cpp
FlexMatrix<double, 3, 3> fm1("1,2,3,4,5,6", ',');
fm1.resize(3, 2);
cout << fm1;
/* resultado:
1  2
3  4
5  6
 */
```

**Use Case #4:**
```cpp
FlexMatrix<float, 4, 3> fm1("1|2|3|4|5|6|7|8|9|10|11|12", '|');
auto fm2 = fm1;
fm1.resize(3, 4);
auto fm3 = fm2;
fm3.resize(2, 2);
cout << "----" << endl;
cout << fm1;
cout << "----" << endl;
for (int i = 0; i < fm1.rows(); ++i) {
    for (int j = 0; j < fm1.cols(); ++j)
        cout << setw(3) << fm1(i, j);
    cout << endl;
}
cout << "----" << endl;
cout << fm3;
cout << "----" << endl;
/* resultado:
----
 1  2  3
 4  5  6
 7  8  9
10 11 12
----
 1  2  3  4
 5  6  7  8
 9 10 11 12
----
 1  2
 3  4
----
 */

```

## Question #2 - template de función (6 points)
Escribir el template de función `get_fibonacci_lists` que reciba como parámetro un contenedor genérico (`vector` o `deque`) con valores numéricos enteros (`char`, `int`, `unsigned`, `size_t`) y que realice una división de los valores en cantidades que sigan la serie fibonacci.
La función debe retornar un contenedor de contenedores, que debera tener como tipo el mismo tipo de contenedor que tiene el parámetro de la función.  

**Use Case #1:**
```cpp
vector v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
auto fl1 = get_fibonacci_lists(v1);
for (const auto& row: fl1) {
    for (const auto& item: row)
        cout << setw(3) << item;
    cout << endl;
}
/* resultado:
     1 
     2
     3  4
     5  6  7
     8  9 10 11 12
    13 14 15 16 17 18 19 20
 */
```

**Use Case #2:**
```cpp
vector<unsigned int> v1 = {
        1,   2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
auto fl1 = get_fibonacci_lists(v1);
for (const auto& row: fl1) {
    for (const auto& item: row)
        cout << setw(3) << item;
    cout << endl;
}
/* resultado:
   1 
   2
   3  4
   5  6  7
   8  9 10 11 12
  13 14 15 16 17 18 19 20
  21 22 23 24 25 26 27 28 29 30 31 32 33
  34 35
 */
```
