# Semana 03 - Memória dinâmica e ponteiros; STL vector/string e templates de funções

**Tema:** Alocação dinâmica com `new`/`delete`, ponteiros para `struct`; `std::vector`, `std::string`, templates de funções e reimplementação de estruturas de dados esparsas

**Linguagem:** C++

---

## Exercício 1 - Concatenar listas dinâmicas (array list)

O ficheiro `alist.h` define uma `struct alist` (uma "array list" alocada dinamicamente) com um campo `size` e um array `elements` alocado com `new[]`, além de funções auxiliares já fornecidas: `alist* empty()`, `alist* build(int n, int v[])`, `void destroy(const alist* al)` e `void print(const alist* al)`.

Falta implementar:

```cpp
void append(alist* a, const alist* b);
```

que concatena os elementos de `b` ao fim de `a`, **modificando `a` in-place** (deve alocar um novo array com `a->size + b->size` elementos, copiar os elementos de `a` seguidos dos de `b`, libertar o array antigo de `a` com `delete[]` e atualizar `a->size`). `b` não deve ser alterado.

**Exemplo:**
```
a = [ 1 2 3 4 ], b = [ 5 6 7 ]
append(a, b) -> a = [ 1 2 3 4 5 6 7 ]
```

**Solução:** `01-lista-array-concatenar/`

---

## Exercício 2 - Prefixo comum mais longo

Implemente:

```cpp
string longest_prefix(const vector<string>& v);
```

que devolve o maior prefixo comum a **todas** as strings do vetor `v` (string vazia se não houver nenhum prefixo comum).

São fornecidas duas implementações: `longest-common-prefix.cpp`, que percorre o vetor com um ciclo `for (string x : v)` (range-for), e `longest-common-prefix_2000.cpp`, uma implementação alternativa que resolve o mesmo problema com um ciclo indexado (`for (int i = 1; i < v.size(); i++)`) em vez de range-for.

**Exemplo:**
```
v = { "a", "b", "a" }
Saída: ""
```

**Solução:** `02-prefixo-comum-mais-longo/`

---

## Exercício 3 - Normalizar vetor (clamp)

Implemente uma função template:

```cpp
template <typename T>
void normalise(vector<T>& v, const T& min, const T& max);
```

que percorre `v` e limita ("clampa") cada elemento ao intervalo `[min, max]`: valores acima de `max` passam a `max`, valores abaixo de `min` passam a `min`. Deve funcionar tanto para tipos numéricos como para `string` (usando a ordem lexicográfica).

**Exemplo:**
```
v = { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" }
normalise(v, "Antonio", "Zacarias")
Saída: [ Antonio Antonio Antonio Bernardo Tolentino Zacarias Xavier ]
```

**Solução:** `03-normalizar-vector-clamp/`

---

## Exercício 4 - Soma de matrizes esparsas

Uma matriz esparsa é representada em `smatrix.h` como `vector<sm_entry>`, em que cada `sm_entry { size_t row; size_t col; int value; }` guarda apenas as células não-nulas. Implemente:

```cpp
void sum(const smatrix& a, const smatrix& b, smatrix& r);
```

que calcula a soma de duas matrizes esparsas `a` e `b`, colocando em `r` apenas as entradas com valor final diferente de zero, ordenadas por `(row, col)` crescente.

**Exemplo:**
```
a = [ (0,0,1) (0,1,2) (5,10,20) (99,12,32) ]
b = [ (0,0,1) (0,1,-2) (10,5,20) (99,10,30) (99,11,31) ]
sum(a,b,r) -> r = [ (0,0,2) (5,10,20) (10,5,20) (99,10,30) (99,11,31) (99,12,32) ]
(nota: a entrada (0,1,2)+(0,1,-2) soma 0 e por isso é omitida do resultado)
```

**Solução:** `04-soma-matrizes-esparsas/`

---

## Exercício 5 - Dividir string em palavras

Implemente:

```cpp
void split(const string& s, vector<string>& v);
```

que divide `s` em palavras separadas por espaços, adicionando cada palavra (sem espaços) ao vetor `v`, ignorando espaços extra/consecutivos.

**Exemplo:**
```
s = "C++ LEIC  FCUP FEUP"
Saída: [ "C++" "LEIC" "FCUP" "FEUP" ]
```

**Solução:** `05-dividir-string-palavras/`

---

## Exercícios Extra

Variantes complementares sobre arrays de ponteiros e `std::string` — boa prática extra, não essenciais para seguir o resto do currículo.

### Extra 1 - A string mais longa

Implemente:

```cpp
const char* longest(const char* pa[]);
```

que recebe um array de C-strings terminado em `nullptr` e devolve um ponteiro para a mais longa. Em caso de empate, deve devolver a que ocorrer **mais tarde** no array.

**Exemplo:**
```
pa = { "", "0123", "Hello", "world", "!", nullptr }
Saída: "world"
```

**Solução:** `extra/01-string-mais-longa/`

---

### Extra 2 - Verificação de pangrama com std::string

Reescreva o exercício de pangramas da semana anterior usando `std::string` em vez de C-strings:

```cpp
bool pangram(const string& s, string& m);
```

que devolve `true` se `s` contiver todas as letras do alfabeto (ignorando maiúsculas/minúsculas) e, caso contrário, preenche `m` com as letras em falta.

**Exemplo:**
```
s = "A quick brown fox jumps over a classy dog"
Saída: "A quick brown fox jumps over a classy dog" false "twz"
```

**Solução:** `extra/02-pangrama-stdstring/`

---
