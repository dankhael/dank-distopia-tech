# Semana 01 - Fundamentos: variáveis, laços e aritmética; caracteres, arrays e structs simples

**Tema:** Revisão de tipos básicos, ciclos `while`/`for` e operações aritméticas com inteiros e vírgula flutuante; manipulação de `char`, arrays estáticos, C-strings e primeiras `struct`s (números complexos)

**Linguagem:** C++

---

## Exercício 1 - Inverter dígitos

Escreva um programa que leia um número inteiro `t` e imprima os seus dígitos por ordem inversa, tratando o resultado como um novo número inteiro (ou seja, zeros à esquerda do número invertido desaparecem naturalmente).

**Exemplo:**
```
Entrada: 12300
Saída:   321
```

**Solução:** `01-inverter-digitos/`

---

## Exercício 2 - Classificador de caracteres

Escreva um programa que leia um único carácter da entrada padrão e imprima:

- `DIGIT` se o carácter for um dígito (`'0'`-`'9'`);
- `LETTER` se for uma letra maiúscula ou minúscula (`'A'`-`'Z'` ou `'a'`-`'z'`);
- `OTHER` em qualquer outro caso.

Resolva a classificação comparando os códigos ASCII do carácter diretamente (sem usar `<cctype>`).

**Exemplo:**
```
Entrada: 7
Saída:   DIGIT

Entrada: k
Saída:   LETTER

Entrada: #
Saída:   OTHER
```

**Solução:** `02-classificador-caracteres/`

---

## Exercício 3 - Remover duplicados consecutivos

Implemente a função:

```cpp
int filter_duplicates(const int a[], int n, int b[]);
```

que recebe um array `a` de `n` inteiros e produz em `b` a mesma sequência mas com repetições **consecutivas** colapsadas num único elemento (i.e. só remove duplicados adjacentes, não duplicados espalhados pelo array). A função deve devolver o número de elementos escritos em `b`.

Use a função auxiliar `void print_array(const int a[], int n)` (disponibilizada em `print_array.h`) para imprimir o array resultante no formato `[e0,e1,...,en]`.

**Exemplo:**
```
a = { 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 33 }
b = [1,0,1,0,33]
```

**Solução:** `03-remover-duplicados-consecutivos/`

---

## Exercício 4 - Verificação de pangrama (C-strings)

Implemente a função:

```cpp
bool pangram(const char s[], char m[]);
```

que verifica se a frase `s` (usando apenas C-strings, sem `std::string`) contém todas as letras do alfabeto (ignorando maiúsculas/minúsculas). A função deve devolver `true` se `s` for um pangrama e, caso **não** seja, preencher `m` com as letras do alfabeto que faltam (por ordem alfabética); se `s` for um pangrama, `m` deve ficar vazio (`m[0] = '\0'`).

**Exemplo:**
```
s = "A quick brown fox jumps over a classy dog"
Saída: "A quick brown fox jumps over a classy dog" false "twz"
```

**Solução:** `04-verificacao-pangrama-cstring/`

---

## Exercício 5 - Números complexos e Mandelbrot (v1)

Defina uma `struct complex` com dois campos inteiros, `real` e `img`, num ficheiro de cabeçalho `complex.h`, incluindo uma função `void print(const complex z[], int n)` que imprima um array de complexos no formato `[ z0 z1 ... ]` (mostrando `a+bi`, `a-bi`, `a` ou `bi` conforme os campos sejam zero ou não).

No `.cpp`, implemente:

```cpp
complex sum(complex a, complex b);
complex mul(complex a, complex b);
void mandel(complex c, int n, complex z[]);
```

em que `mandel` preenche o array `z` com os primeiros `n` termos da iteração do conjunto de Mandelbrot para o ponto `c`: `z[0] = 0`, `z[i] = z[i-1]² + c`.

**Exemplo:**
```
c = 0+0i, n = 1
Saída: [ 0 ]
```

**Solução:** `05-complexos-e-mandelbrot-v1/`

---

## Exercícios Extra

Estes exercícios exploram os mesmos conceitos da semana (laços, aritmética, alocação dinâmica) mas são complementares — boa prática extra, não essenciais para seguir o resto do currículo.

### Extra 1 - Números perniciosos

Escreva um programa que leia dois inteiros `start` e `end` da entrada padrão e, para cada número `n` no intervalo `[start, end]`, imprima `n` (seguido de um espaço) se **ambas** as seguintes condições se verificarem:

- `n` é primo;
- o número de bits a `1` na representação binária de `n` (a sua "população de bits") também é primo.

Implemente uma função `bool prime(int n)` para testar primalidade e uma função auxiliar que calcule a contagem de bits a `1` de um inteiro sem usar operadores de bit (`<<`, `>>`, `&`), decompondo o número em potências de 2 decrescentes.

**Exemplo:**
```
Entrada: 1 20
Saída:   3 5 7 11 13 19
```

**Solução:** `extra/01-numeros-perniciosos/`

---

### Extra 2 - Aproximação de Pi

Escreva um programa que leia um inteiro `j` (número de termos da série) e um inteiro `pr` (número de casas decimais) e calcule uma aproximação de π usando a série de Leibniz:

```
π ≈ 4 * Σ (-1)^i / (2i + 1),  para i = 0 .. j
```

Imprima o resultado com exatamente `pr` casas decimais (formato fixo, usando `std::fixed` e `std::setprecision`).

**Exemplo:**
```
Entrada: 100000 6
Saída:   3.141603
```

**Solução:** `extra/02-aproximacao-de-pi/`

---

### Extra 3 - Repetir string

Implemente a função:

```cpp
char* repeat(const char str[], int n);
```

que aloca dinamicamente (com `new[]`) e devolve uma nova C-string contendo `str` repetida `n` vezes seguidas. O chamador é responsável por libertar a memória com `delete[]`.

**Exemplo:**
```
str = "H e l l o", n = 2
Saída: "H e l l oH e l l o"
```

**Solução:** `extra/03-repetir-string/`

---
