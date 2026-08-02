# Semana 02 - Structs, referências e operator<<; arrays, C-strings e algoritmos simples

**Tema:** Passagem por referência, sobrecarga de `operator<<` e `struct`s com aritmética própria; algoritmos sobre arrays (fusão, contagem, codificação) e C-strings

**Linguagem:** C++

---

## Exercício 1 - Números complexos (v2)

Defina em `complex.h` uma `struct complex` com dois campos `double x` (parte real) e `double y` (parte imaginária), e sobrecarregue `operator<<` para a imprimir no formato `x+yi` (ou `x-yi` se `y` for negativo), sempre com 3 casas decimais.

No `.cpp`, implemente, desta vez usando **passagem por referência** (incluindo um parâmetro de saída) em vez de retorno por valor:

```cpp
void add(const complex& a, const complex& b, complex& r);
void mul(const complex& a, const complex& b, complex& r);
double norm(const complex& c);   // módulo/norma do complexo
```

**Exemplo:**
```
a = 0+1i, b = 2+1i
add -> 2.000+2.000i
mul -> -1.000+2.000i
norm(add) = 2.828, norm(mul) = 2.236
```

**Solução:** `01-numeros-complexos-v2/`

---

## Exercício 2 - Frações: soma e multiplicação

Defina em `fraction.h` uma `struct fraction` com campos inteiros `num` e `den`, e sobrecarregue `operator<<` para a imprimir como `num/den` (ou apenas `num` quando `den == 1`).

Implemente no `.cpp`:

```cpp
int gcd(int a, int b);           // máximo divisor comum, recursivo
fraction add(fraction a, fraction b);
fraction mul(fraction a, fraction b);
```

Ambas as operações devem devolver o resultado **simplificado** (dividido pelo `gcd`) e com o denominador sempre positivo (se ficar negativo, inverta o sinal de `num` e `den`).

**Exemplo:**
```
a = -3/2, b = -2/3
add(a,b) -> -13/6
mul(a,b) -> 1
```

**Solução:** `02-fracoes-soma-multiplicacao/`

---

## Exercício 3 - Interseção de intervalos de tempo

Defina em `interval.h`:

```cpp
struct time_of_day { unsigned char h; unsigned char m; };
struct interval { time_of_day start; time_of_day end; };
```

com `operator<<` a imprimir `time_of_day` como `HH:MM` (com zero à esquerda) e `interval` como `[HH:MM,HH:MM[`.

No `.cpp`, implemente:

```cpp
interval intersection(interval a, interval b);
```

que devolve o intervalo de sobreposição entre `a` e `b`. Se os intervalos não se sobrepuserem, deve devolver o intervalo vazio `{ {0,0}, {0,0} }`. Resolva o problema sem ordenar com `std::sort` — troque os próprios intervalos (`troca`) para garantir que `a` começa depois (ou ao mesmo tempo) de `b`, e depois compare os limites (`maior`) para decidir a sobreposição.

**Exemplo:**
```
a = [12:30,14:30[, b = [14:30,18:30[
intersection(a,b) -> [00:00,00:00[   (sem sobreposição)
```

**Solução:** `03-intersecao-intervalos/`

---

## Exercício 4 - Fusão de arrays ordenados

Implemente:

```cpp
void merge_arrays(const int a[], int na, const int b[], int nb, int c[]);
```

que funde dois arrays já ordenados (`a` de tamanho `na`, `b` de tamanho `nb`) num único array `c` de tamanho `na+nb`, mantendo a ordenação (semelhante ao passo de fusão do merge sort). Imprima o resultado com `print_array` (formato `[e0,e1,...]`).

**Exemplo:**
```
a = {0,1}, b = {2,3,4}
c = [0,1,2,3,4]
```

**Solução:** `04-fusao-arrays-ordenados/`

---

## Exercício 5 - Codificação RLE (Run-Length Encoding)

Implemente:

```cpp
void rle_encode(const char str[], char rle[]);
```

que codifica `str` no formato *run-length encoding*: para cada sequência de carateres repetidos, escreve o número de repetições (podendo ocupar até 2 dígitos, i.e. até 99) seguido do carácter. Trate corretamente o caso de `str` vazia.

**Exemplo:**
```
str = "a"
Saída: "1a"
```

**Solução:** `05-codificacao-rle/`

---

## Exercícios Extra

Variantes e algoritmos complementares sobre os mesmos temas (structs, arrays, C-strings) — bons para praticar mais, mas não essenciais para seguir o resto do currículo.

### Extra 1 - Mandelbrot (v2, sem array)

Reescreva o cálculo do conjunto de Mandelbrot do Exercício 5 da semana anterior, mas desta vez sem guardar a sequência inteira: implemente

```cpp
void mandelbrot(const complex& c, unsigned int n, complex& z_n);
```

que calcula **apenas** o n-ésimo termo `z_n` da iteração `z_0 = 0`, `z_i = z_{i-1}² + c`, usando um ciclo com variáveis temporárias em vez de um array. Reaproveite `add`, `mul` e `norm` da mesma forma que no Exercício 1 (por referência).

**Exemplo:**
```
c = -1.200+0.400i, n = 7
Saída: z_7 (com 3 casas decimais)
```

**Solução:** `extra/01-mandelbrot-v2/` (reutiliza `complex.h` do Exercício 1)

---

### Extra 2 - Pertença a um conjunto de intervalos

Reutilizando `time_of_day`/`interval` de `interval.h`, implemente:

```cpp
bool pertence(time_of_day t, const interval a);
int search_intervals(time_of_day t, const interval a[], int n, interval& u);
```

`pertence` indica se o instante `t` está contido no intervalo `a` (considerando também o caso em que `start.h == end.h`). `search_intervals` percorre um array de `n` intervalos, calcula em `u` a **união** (menor `start` e maior `end`) de todos os intervalos que contêm `t`, e devolve a duração dessa união em minutos.

**Exemplo:**
```
t = 15:15
a = { [12:30,14:30[, [14:30,15:30[, [15:10,16:10[, [09:30,15:15[, [09:45,15:16[ }
Saída: <minutos> [09:30,16:10[
```

**Solução:** `extra/02-pertenca-conjunto-intervalos/` (reutiliza `interval.h` do Exercício 3)

---

### Extra 3 - Máximo de um array

Implemente:

```cpp
int max(const int a[], int n);
```

que devolve o maior elemento de um array de `n` inteiros.

**Exemplo:**
```
a = { -3, -2, -1 }
Saída: -1
```

**Solução:** `extra/03-maximo-de-array/`

---

### Extra 4 - Letras únicas de uma frase

Implemente:

```cpp
int nrl(const char s[], char low[]);
```

que conta quantas letras do alfabeto aparecem **exatamente uma vez** em `s` (ignorando maiúsculas/minúsculas) e escreve essas letras, em ordem alfabética, em `low`. Deve devolver esse número; se for `0`, `low` fica vazio.

**Exemplo:**
```
s = "  F C U P  F E U P  Porto  "
Saída: "  F C U P  F E U P  Porto  " 2 "ct"
```

**Solução:** `extra/04-letras-unicas/`

---

### Extra 5 - Soma de um array de frações

Reutilizando a `struct fraction` de `fraction.h`, implemente:

```cpp
fraction sum(const fraction fa[], int n);
```

que soma `n` frações de um array, devolvendo o resultado simplificado (usando `gcd`) e com denominador positivo, tal como no Exercício 2 (soma de frações).

**Exemplo:**
```
fa = { 0/1, 1/2, -2/3, 3/4, -4/5 }
Saída: -29/60
```

**Solução:** `extra/05-soma-array-fracoes/` (reutiliza `fraction.h` do Exercício 2)

---

### Extra 6 - Remover espaços (trim)

Implemente:

```cpp
void trim(char s[]);
```

que remove, **in-place**, os espaços no início e no fim da C-string `s` (deslocando os carateres restantes para o início do array e terminando a string mais cedo com `'\0'`).

**Exemplo:**
```
s = "    abc def"
Saída: "abc def"
```

**Solução:** `extra/06-trim-espacos/`

---
