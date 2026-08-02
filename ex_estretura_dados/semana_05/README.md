# Semana 05 - Templates de classes e listas ligadas; STL avançada: matrizes, iteradores e templates genéricos

**Tema:** Membros estáticos de classe, templates de classe e implementação de estruturas de dados ligadas por apontador; `vector<vector<T>>`, templates de função sobre iteradores e classes com `std::list`

**Linguagem:** C++

---

## Exercício 1 - Classe Color

Implemente a classe `Color` (declarada em `Color.h`), com os atributos privados `r`, `g`, `b`, os construtores `Color(unsigned char red, unsigned char green, unsigned char blue)` e `Color(const Color& c)` (construtor de cópia), os acessores `red()`, `green()`, `blue()`, o método `bool equal_to(const Color& other) const` e `void invert()` (inverte a cor, `255 - componente`).

Defina também cinco constantes estáticas da classe: `Color::RED`, `Color::GREEN`, `Color::BLUE`, `Color::BLACK`, `Color::WHITE`.

**Exemplo:**
```
Color c(1, 2, 3);
const Color& r = c;
Saída: r.red()=1  r.blue()=3  r.green()=2
```

**Solução:** `01-classe-color/`

---

## Exercício 2 - Pilha genérica com lista ligada

Implemente uma classe template `Stack<T>` (declarada em `Stack.h`) que representa uma pilha (LIFO) usando uma lista ligada de `node<T>` (cada nó com `value` e `next`), sem usar `std::vector` nem `std::stack`:

```cpp
template <typename T>
class Stack {
public:
  Stack();
  ~Stack();                 // liberta todos os nós
  size_t size() const;
  bool peek(T& elem) const; // lê o topo sem remover; false se vazia
  bool pop(T& elem);        // remove e devolve o topo; false se vazia
  void push(const T& elem); // insere no topo
};
```

**Exemplo:**
```
Stack<int> s;
s.size() -> 0
s.peek(v) -> false
s.pop(v)  -> false
```

**Solução:** `02-pilha-generica-lista-ligada/`

---

## Exercício 3 - Filtro de máximo numa matriz 2D

Implemente:

```cpp
bool max_filter(vector<vector<int>>& v, int n);
```

que aplica, **in-place**, um filtro de máximo com janela `n x n` (`n` ímpar) a cada posição interior da matriz `v` (i.e. cada célula suficientemente longe da borda para ter uma vizinhança completa de tamanho `n x n`): cada célula passa a valer o maior valor entre os seus vizinhos dentro da janela (excluindo-se a si própria). Se `n` for par, ou maior do que o número de linhas/colunas de `v`, a função não deve alterar `v` e deve devolver `false`; caso contrário devolve `true`.

**Desafio:** este exercício vem com duas implementações — `matrix-max-filter.cpp` (correta) e `matrix-max-filter-com-bug.cpp` (com bug). Antes de espreitar a versão correta, tente encontrar o problema na versão com bug: ela usa como índices da matriz os próprios deslocamentos `k`/`l` da janela (`v[k][l]`, que variam em `[-m, m]`) em vez das coordenadas de vizinho `neighbourhood_line`/`neighbourhood_col`, e usa uma condição de fronteira `> 0` em vez de `>= 0` (excluindo indevidamente a linha/coluna 0).

**Exemplo:**
```
v = { {1,2,3}, {4,5,6}, {7,8,9} }
max_filter(v, 3) -> true
v => {{1 2 3}{4 9 6}{7 8 9}}   // só a célula central (1,1) tem vizinhança completa
```

**Solução:** `03-filtro-maximo-matriz2d/`

---

## Exercício 4 - Funções genéricas sobre iteradores

Implemente duas funções template que funcionam sobre qualquer par de iteradores (não apenas `vector`):

```cpp
template <typename Itr>
string to_string(Itr start, Itr end);       // ex: "[ 1 2 3 ]"

template <typename Itr, typename T>
int replace(Itr start, Itr end, const T& a, const T& b);  // substitui a por b, devolve nº de substituições
```

**Exemplo:**
```
v = { 1, 2, 3, 3, 4 }
replace(v.begin(), v.end(), 3, 0) -> 2
to_string(v.cbegin(), v.cend()) -> "[ 1 2 0 0 4 ]"
```

**Solução:** `04-funcoes-genericas-iteradores/`

---

## Exercício 5 - Média móvel

Implemente a classe `MovingAverage` (declarada em `MovingAverage.h`), que mantém internamente uma janela deslizante (`std::list<double>`) com, no máximo, `n` valores mais recentes:

```cpp
class MovingAverage {
public:
  MovingAverage(std::size_t n);
  void update(double value);  // adiciona um valor; se já houver n valores, remove o mais antigo
  double get() const;         // média dos valores atualmente na janela
};
```

**Exemplo:**
```
MovingAverage ma(1);
ma.update(1.2); ma.get() -> 1.20
ma.update(3.4); ma.get() -> 3.40   // janela de tamanho 1: só guarda o valor mais recente
ma.update(5.0); ma.get() -> 5.00
```

**Solução:** `05-media-movel/`

---

## Exercícios Extra

Composição de objetos, algoritmos de contagem e parsing complementares — boa prática extra, não essenciais para seguir o resto do currículo.

### Extra 1 - Composição: Polygon feito de Points

Implemente a classe `Point` (coordenadas inteiras `x`, `y`, construtor por omissão na origem, construtor `Point(int x, int y)` e `void show() const` que imprime `(x,y)`), e a classe `Polygon`, que é composta por um `vector<Point>`:

```cpp
class Polygon {
public:
  Polygon(vector<Point> pontos);
  void show() const;   // imprime "{(x1,y1)(x2,y2)...}"
};
```

**Exemplo:**
```
Point p1, p2(0, 1);
p1.show(); p2.show();
Saída: (0,0)(0,1)
```

**Solução:** `extra/01-composicao-poligono/`

---

### Extra 2 - Pessoas nascidas antes de uma data

Implemente as classes `Date` (ano/mês/dia privados, construtor por omissão `1/1/1`, construtor `Date(int year, int month, int day)`, `bool is_before(const Date& date) const` e `void show() const`) e `Person` (nome e data de nascimento privados, construtor por omissão `"NO_NAME"` com data por omissão, construtor `Person(const string& name, const Date& birth_date)`, `get_name()`, `get_birth_date()` e `void show() const`).

Implemente também a função livre:

```cpp
void born_before(const vector<Person>& persons, const Date& date);
```

que imprime a data de referência seguida de `": "` e depois, para cada pessoa em `persons` cuja data de nascimento seja anterior a `date`, chama `show()` nessa pessoa.

**Exemplo:**
```
born_before({ {"Rui",{2000,4,5}}, {"Ana",{1999,5,11}}, {"Susana",{1999,5,13}}, {"Pedro",{2010,2,10}} }, {2020,1,1});
Saída: 2020/1/1: Rui-2000/4/5 Ana-1999/5/11 Susana-1999/5/13 Pedro-2010/2/10
```

**Solução:** `extra/02-pessoas-antes-de-data/` (inclui também o `Makefile` de compilação original)

---

### Extra 3 - Frequência de palavras (vector de pares)

Implemente:

```cpp
void count_words(const string& str, vector<pair<string, size_t>>& count);
```

que conta as ocorrências de cada palavra em `str` (ignorando maiúsculas/minúsculas) e preenche `count` com pares `(palavra, contagem)`, ordenados por palavra (ordem alfabética).

**Exemplo:**
```
str = "If you want to buy  buy  if you don't want to buy  bye bye"
Saída: [ buy:3 bye:2 don't:1 if:2 to:2 want:2 you:2 ]   (ordenado alfabeticamente)
```

**Solução:** `extra/03-frequencia-palavras-vector-pair/` (ver também a versão com `std::map` deste mesmo exercício na semana seguinte)

---

### Extra 4 - Conversor de numerais romanos

Implemente:

```cpp
unsigned roman_to_arab(const string& roman);
```

que converte um numeral romano (usando os símbolos `I V X L C D M`, incluindo notação subtrativa como `IV`, `IX`, `XL`, etc.) para o valor inteiro correspondente.

**Exemplo:**
```
roman_to_arab("MMMDCCCLXXXVIII") -> 3888
```

**Solução:** `extra/04-conversor-numerais-romanos/`

---
