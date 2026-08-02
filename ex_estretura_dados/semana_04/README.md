# Semana 04 - Ficheiros: ifstream/ofstream; introdução a classes: encapsulamento e construtores

**Tema:** Leitura e escrita de ficheiros de texto com `ifstream`/`ofstream`, `getline` e `istringstream`; definição de classes com atributos privados, construtores, acessores e métodos `const`

**Linguagem:** C++

---

## Exercício 1 - Contar ocorrências de uma palavra num ficheiro

Implemente:

```cpp
int count(const string& fname, const string& word);
```

que abre o ficheiro `fname`, lê-o palavra a palavra (separadas por espaços/newlines) e devolve quantas vezes `word` ocorre, **ignorando maiúsculas/minúsculas**.

**Exemplo:**
```
count("p2_test2.txt", "THE")
p2_test2.txt: "The quick brown fox jumps over the lazy dog"
Saída: 2
```

**Solução:** `01-contar-palavra-em-ficheiro/` (inclui os ficheiros de teste `p2_test1.txt` a `p2_test5.txt`)

---

## Exercício 2 - Normalizar linhas de um ficheiro

Implemente:

```cpp
void normalise(const string& input_fname, const string& output_fname);
```

que lê `input_fname` linha a linha, remove os espaços no início e no fim de cada linha, converte o texto restante para maiúsculas, e escreve em `output_fname` apenas as linhas não vazias resultantes.

São fornecidas duas implementações: `normalise.cpp` (versão limpa, usando `string::erase`/`find_first_not_of`/`find_last_not_of`) e `normalise_2.cpp` — uma versão alternativa e mais rudimentar do mesmo problema, que processa carácter a carácter à mão em vez de usar as funções de `string` para trim.

Use `print(const string& file)` (de `print.h`) para mostrar o ficheiro de saída numerado, no formato `numero_linha|conteudo|`.

**Exemplo:**
```
Linha de entrada: "    word one "
Linha de saída:   "WORD ONE"
```

**Solução:** `02-normalizar-linhas-ficheiro/` (inclui os ficheiros de teste `p3_test1.txt` a `p3_test5.txt` e os ficheiros de saída já gerados `p3_test2_out.txt`, `p3_test4_out.txt`)

---

## Exercício 3 - Classe Date (v1)

A classe `Date` (declarada em `Date1.h`) representa uma data com os atributos privados `year`, `month`, `day`, dois construtores (`Date()` para o dia `0001/01/01`, e `Date(int year, int month, int day)`), acessores `get_year`/`get_month`/`get_day` e `void write() const` (que imprime a data no formato `yyyy/mm/dd`, com zeros à esquerda).

Implemente, no `.cpp`, a função livre:

```cpp
bool is_before(const Date& date1, const Date& date2);
```

que compara duas datas cronologicamente e devolve `true` se `date1` for anterior a `date2` (comparando ano, depois mês, depois dia).

**Exemplo:**
```
d6 = Date(2022,5,29), d7 = Date(2022,5,28)
d6.write() -> "2022/05/29"
is_before(d6, d7) -> false
```

**Solução:** `03-classe-date-v1/`

---

## Exercício 4 - Classe Fraction

Implemente a classe `Fraction`, com atributos privados `numerator_` e `denominator_`, construtores `Fraction()` (valor `0/1`) e `Fraction(int num, int den)` (que normaliza automaticamente a fração — simplifica pelo `gcd` e garante denominador positivo), acessores `numerator()`/`denominator()`, e as operações aritméticas:

```cpp
Fraction sum(const Fraction& right) const;
Fraction sub(const Fraction& right) const;
Fraction mul(const Fraction& right) const;
Fraction div(const Fraction& right) const;
```

além de `void write() const` (formato `num/den`). As funções auxiliares `gcd` e `normalise` são fornecidas em `fraction_aux.h` como referência (o `.cpp` desta solução define-as diretamente na própria classe).

**Exemplo:**
```
Fraction(2,4).div({3, 9}).write() -> "3/2"
```

**Solução:** `04-classe-fraction/`

---

## Exercício 5 - Classe Point2d

Implemente a classe `Point2d`, com coordenadas privadas `x`, `y` (`double`), construtor por omissão (origem `(0,0)`), construtor de cópia, construtor `Point2d(double x, double y)`, acessores/mutadores `get_x`/`get_y`/`set_x`/`set_y`, e:

```cpp
void translate(const Point2d& t);            // desloca o ponto por (t.x, t.y)
double distance_to(const Point2d& p) const;   // distância euclidiana até p
```

**Exemplo:**
```
a = Point2d(1.0, 2.1), b = Point2d(2.0, 3.1)
a.distance_to(b) -> 1.41
```

**Solução:** `05-classe-point2d/`

---

## Exercícios Extra

Variantes e algoritmos complementares sobre leitura/escrita de ficheiros e sobre a evolução da classe `Date` — boa prática extra, não essenciais para seguir o resto do currículo.

### Extra 1 - Implementar `wc` (word count)

Defina em `wc.h` uma `struct wcresult { unsigned int lines; unsigned int words; unsigned int bytes; };` e implemente:

```cpp
wcresult wc(const string& filename);
```

que reproduz o comportamento do utilitário Unix `wc`: conta o número de linhas, de palavras e de bytes (carateres, incluindo o `'\n'` de cada linha) do ficheiro `filename`.

**Exemplo:**
```
wc("p2_test2.txt")  // "The quick brown fox jumps over the lazy dog\n"
Saída: lines=1 words=9 bytes=44
```

**Solução:** `extra/01-implementar-wc/` (inclui os mesmos ficheiros de teste `p2_test1.txt` a `p2_test5.txt`)

---

### Extra 2 - Máximo dos números de um ficheiro

Implemente:

```cpp
void maximum(const string& input_fname, const string& output_fname);
```

que lê números de vírgula flutuante de `input_fname` (podendo estar vários por linha), escreve cada número lido (com 3 casas decimais) numa linha de `output_fname`, e no final acrescenta uma linha `count=<N>/max=<maior valor>`.

Use `show_file(const string& file)` (de `show_file.h`) para mostrar o conteúdo do ficheiro de saída no ecrã, precedido de `==> ficheiro <==`.

**Exemplo:**
```
p4_test1.txt:
-1.2
  1.222222222222
    3.14159

Saída (output file):
-1.200
1.222
3.142
count=3/max=3.142
```

**Solução:** `extra/02-maximo-numeros-ficheiro/` (inclui os ficheiros de teste `p4_test1.txt` a `p4_test4.txt` e `p4_test1_out.txt`)

---

### Extra 3 - Mediana por linha

Implemente:

```cpp
void calc_medians(const string& input_fname, const string& output_fname);
```

que lê `input_fname` linha a linha; cada linha tem um identificador (string) seguido de vários números. Linhas cujo identificador começa por `'#'` são ignoradas. Para as restantes, escreve em `output_fname` o identificador seguido da mediana dos números dessa linha, com 1 casa decimal.

**Exemplo:**
```
Linha de entrada: "a 1.2 1.2 3.0 3.1 3.2"
Linha de saída:   "a 3.0"
```

**Solução:** `extra/03-mediana-por-linha/` (reutiliza `show_file.h` do Extra 2; inclui os ficheiros de teste `p5_test1.txt` a `p5_test5.txt` e os ficheiros de saída `p5_test2_out.txt`, `p5_test3_out.txt`)

---

### Extra 4 - Média dos números de um ficheiro

Implemente:

```cpp
double average(const string& fname);
```

que lê todos os números de vírgula flutuante de `fname` (independentemente de estarem separados por espaços ou por outros carateres na mesma linha) e devolve a sua média.

**Exemplo:**
```
p6_test1.txt: "1.0 2.0 4.5"
average("p6_test1.txt") -> 2.50
```

**Solução:** `extra/04-media-numeros-ficheiro/` (inclui os ficheiros de teste `p6_test1.txt` a `p6_test5.txt`)

---

### Extra 5 - Classe Date (v2, com validação)

Estenda a classe `Date` (em `Date2.h`) para validar a data no momento da construção: se `year`, `month` ou `day` não formarem uma data válida (considerando meses de 30/31 dias e anos bissextos), os atributos internos ficam a `0` em vez dos valores fornecidos.

Adicione também um construtor a partir de texto:

```cpp
Date(const std::string& year_month_day);  // formato "yyyy/mm/dd"
```

que faz *parse* da string (separadores `/`) e valida da mesma forma, e o método:

```cpp
bool is_valid() const;   // true se year, month e day forem != 0
```

**Exemplo:**
```
Date d2(2022, 4, 31);   // 31 de abril não existe
d2.write() -> "0000/00/00"
d2.is_valid() -> false  // imprime "-invalid"
```

**Solução:** `extra/05-classe-date-v2-validacao/`

---

### Extra 6 - Classe Date (v3, representação interna em string)

Reimplemente a classe `Date` (em `Date3.h`) com a mesma interface pública da v2 (`Date()`, `Date(int,int,int)`, `Date(const string&)`, `is_valid()`, `write()`), mas desta vez guardando internamente a data como uma única `std::string yyyymmdd` de 8 carateres (em vez de três inteiros). `write()` deve construir a saída `yyyy/mm/dd` a partir de substrings dessa representação interna.

**Exemplo:**
```
Date d5("2022#12#31");   // separador inválido ('#' em vez de '/')
d5.write() -> "0000/00/00"
d5.is_valid() -> false   // imprime "-invalid"
```

**Solução:** `extra/06-classe-date-v3-string-interna/`

---
