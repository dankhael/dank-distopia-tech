# Semana 06 - std::map e sobrecarga de operadores; herança, polimorfismo e classes abstratas

**Tema:** `std::map`, sobrecarga de operadores de comparação/aritmética/stream; classes abstratas, funções virtuais puras, `override`, `dynamic_cast` e hierarquias de herança

**Linguagem:** C++

---

## Exercício 1 - Frequência de palavras com std::map

Reescreva o exercício de contagem de palavras com `vector<pair<...>>` (ver Extra 3 da semana anterior), mas desta vez usando `std::map` como estrutura de acumulação:

```cpp
void count_words(const string& str, map<string, size_t>& count);
```

que conta as ocorrências de cada palavra em `str` (ignorando maiúsculas/minúsculas) e preenche `count` com a palavra como chave e a contagem como valor. Use `show_map` para imprimir o mapa no formato `[ palavra:contagem ... ]`.

**Exemplo:**
```
str = "If you want to buy  buy  if you don't want to buy  bye bye"
Saída: [ buy:3 bye:2 don't:1 if:2 to:2 want:2 you:2 ]
```

**Solução:** `01-frequencia-palavras-map/`

---

## Exercício 2 - Classe Point com sobrecarga de operadores

Implemente a classe `Point` (coordenadas inteiras privadas `x_`, `y_`) com construtor por omissão (origem), construtor `Point(int x, int y)`, construtor de cópia, acessores `get_x()`/`get_y()`, e os operadores:

```cpp
Point& operator=(const Point& p);
Point operator+(const Point& p) const;
Point& operator+=(const Point& p);
Point operator*(int v) const;          // multiplicação "à direita" por escalar
Point operator*(int v, const Point& p); // multiplicação "à esquerda" por escalar (função livre)
std::ostream& operator<<(std::ostream& os, const Point& p);  // imprime "(x,y)"
```

**Exemplo:**
```
a = Point(1,2), b = Point(3,4), c = a * 2, d = Point(5,6)
b = 2 * d;
Saída: (1,2) (10,12) (2,4) (5,6)
```

**Solução:** `02-classe-point-operadores/`

---

## Exercício 3 - Calculadora polimórfica

A classe abstrata `Operation` (em `Operation.h`) guarda dois operandos inteiros e declara `virtual int operation() const = 0;`. Implemente duas subclasses:

```cpp
class Sum : public Operation { public: Sum(int a, int b); int operation() const; };
class Power : public Operation { public: Power(int a, int b); int operation() const override; };
```

em que `Sum::operation()` devolve a soma dos operandos e `Power::operation()` devolve o primeiro operando elevado ao segundo.

**Exemplo:**
```
Operation& s = Sum(2, 10);   s.operation() -> 12
Operation& p = Power(2, 10); p.operation() -> 1024
```

**Solução:** `03-calculadora-polimorfica/`

---

## Exercício 4 - Figuras desenháveis

A classe abstrata `Figure` (em `Figure.h`) guarda um centro `(x_center_, y_center_)` protegido e declara `virtual void draw() const = 0;`. Implemente duas subclasses:

```cpp
class Rectangle : public Figure { public: Rectangle(int x_center, int y_center, int width, int height); void draw() const override; };
class Circle    : public Figure { public: Circle(int x_center, int y_center, int radius); void draw() const override; };
```

em que `draw()` imprime `R(cx,cy)(largura,altura)` para retângulos e `C(cx,cy)(raio)` para círculos. Teste com um `vector<Figure*>` polimórfico contendo instâncias de ambas as classes.

**Exemplo:**
```
figures = { Rectangle(10,10,200,100), Circle(20,20,500), Rectangle(-10,-20,150,250), Circle(0,0,100) }
Saída: R(10,10)(200,100)C(20,20)(500)R(-10,-20)(150,250)C(0,0)(100)
```

**Solução:** `04-figuras-desenhaveis/`

---

## Exercício 5 - Folha de pagamento (Employee, SalariedEmployee, HourlyEmployee)

A classe abstrata `Employee` (em `Employee.h`) guarda `name` e `net_pay`, e declara `virtual void calculate_net_pay() = 0;` e `virtual void print_check() const = 0;`. Implemente:

```cpp
class SalariedEmployee : public Employee {
public:
  SalariedEmployee(std::string name, double salary);
  void calculate_net_pay() override;   // net_pay = salary_
  void print_check() const override;   // "nome:SE(salario)=net_pay"
};

class HourlyEmployee : public Employee {
public:
  HourlyEmployee(std::string name, double wage_rate, double hours=0);
  void calculate_net_pay() override;   // net_pay = hours_ * wage_rate_
  void print_check() const override;   // "nome:HE(horas,taxa)=net_pay"
};
```

e as funções livres:

```cpp
void read_hours_worked(vector<Employee*>& employees);  // lê horas do stdin só para os HourlyEmployee (via dynamic_cast)
void calculate_pay(vector<Employee*>& employees);
void print_checks(const vector<Employee*>& employees); // imprime "| cheque1 | cheque2 | ..."
```

> **Nota de correção:** o `employee.cpp` original tinha um fragmento de texto residual (`hat`) colado a seguir a `cout << " |";` dentro de `print_checks`, que impedia a compilação — foi removido, mantendo o resto da linha intacto.

**Exemplo:**
```
employees = { SalariedEmployee("John", 2000), HourlyEmployee("Mary", 10) }
(entrada: horas trabalhadas por Mary, ex. 40)
print_checks -> | John:SE(2000.00)=2000.00 | Mary:HE(40.00,10.00)=400.00 |
```

**Solução:** `05-folha-pagamento-employee/`

---

## Exercícios Extra

Mais prática sobre operadores e polimorfismo — boa prática extra, não essenciais para seguir o resto do currículo.

### Extra 1 - Ordenar datas com operator< (DESAFIO — código incompleto)

> **Atenção:** ao contrário dos outros exercícios desta semana, `dates.cpp` **não compila tal como está**. É propositadamente um desafio em aberto, não uma solução pronta.

O ficheiro `Date.h` define uma classe `Date` simples (ano/mês/dia, com valores por omissão `1/1/1` e acessores `getYear()`/`getMonth()`/`getDay()`), mas **sem** `operator<` nem `operator<<`. O `dates.cpp` tenta ordenar um `vector<Date>` com `std::sort` e depois imprimir cada data com `cout <<`, mas:

- declara uma função `void sort(){}` no mesmo `namespace std` usado (`using namespace std;`), que **colide** com `std::sort` e impede a chamada de `sort(dates.begin(), dates.end())` de resolver para o algoritmo genérico da STL;
- não existe nenhum `operator<(const Date&, const Date&)` para `std::sort` usar na comparação;
- não existe nenhum `operator<<(ostream&, const Date&)` para o `cout << d` funcionar.

**O desafio:** complete a classe `Date` com `operator<` (comparação cronológica: ano, depois mês, depois dia) e `operator<<` (por exemplo, no formato `yyyy/mm/dd`), e resolva a colisão de nomes com `sort` (por exemplo removendo/renomeando a função `sort` local), de forma a que o programa compile e ordene corretamente as datas por ordem cronológica.

**Exemplo:**
```
dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} }
Depois de resolvido o desafio, sort(dates) deve produzir:
2021/12/8 2023/11/14 2023/11/15
```

**Solução:** `extra/01-ordenar-datas-operator-menor/`

---

### Extra 2 - Substituição de carateres com std::map

Implemente:

```cpp
void replace(const map<char, char>& r, string& s);
```

que substitui, **in-place** em `s`, cada carácter que seja chave do mapa `r` pelo valor correspondente (carateres que não estão em `r` ficam inalterados).

**Exemplo:**
```
s = "C / C++ @ LEIC"
replace({ {'C','z'}, {'+','-'}, {'L','X'} }, s)
Saída: "z / z-- @ XEIz"
```

**Solução:** `extra/02-substituicao-caracteres-map/`

---

### Extra 3 - Hierarquia Person / Student / ErasmusStudent

A classe base `Person` (em `Person.h`) tem `id` e `name`, e um método virtual `to_string() const` (formato `"id/name"`). Implemente:

```cpp
class Student : public Person {
public:
  Student(int id, const string& name, const string& course);
  const string& course() const;
  string to_string() const;   // "id/name/course"
};

class ErasmusStudent : public Student {
public:
  ErasmusStudent(int id, const string& name, const string& course, const string& country);
  const string& country() const;
  string to_string() const;   // "id/name/course/country"
};
```

cada subclasse deve sobrepor `to_string()` para incluir a informação adicional respetiva.

**Exemplo:**
```
Person p(125, "Marie Curie");
Student s(126, "Ada Lovelace", "LEIC");
ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
Saída: 125/Marie Curie 126/Ada Lovelace/LEIC 127/Grace Hopper/LXPTO/United States
```

**Solução:** `extra/03-hierarquia-person-student-erasmus/`

---

### Extra 4 - Formas geométricas: área, perímetro e "contains"

A classe abstrata `Shape` (em `Shape.h`) guarda um centro (`struct point { double x, y; }`) e declara `area()`, `perimeter()` e `contains(const point&)` como puramente virtuais. Implemente:

```cpp
class Circle : public Shape {
public:
  Circle(const point& center, double radius);
  double area() const override;
  double perimeter() const override;
  bool contains(const point& p) const override;   // true se p está dentro ou na fronteira do círculo
};

class Rectangle : public Shape {
public:
  Rectangle(const point& center, double width, double height);
  double area() const override;
  double perimeter() const override;
  bool contains(const point& p) const override;   // true se p está dentro ou na fronteira do retângulo
};
```

**Exemplo:**
```
Circle c({1, 2}, 3);
pontos a testar: { (-2.1,2.0), (-1.9,2.0), (4.1,2.0), (3.9,2.0), (1.0,4.9), (1.0,-0.9), ... }
Saída: pontos que satisfazem c.contains(p), impressos como "(x,y)"
```

**Solução:** `extra/04-formas-geometricas-area-perimetro/`

---
