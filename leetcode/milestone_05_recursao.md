# Milestone 5 - Recursão

**Tema:** Funções recursivas e pensamento recursivo

**Linguagem:** Python

---

## Exercício 1 - Fatorial

Escreva uma função recursiva que calcule o fatorial de um número `n`.

```python
def fatorial(n):
    # seu codigo aqui
    pass

# Exemplos:
# fatorial(0) -> 1
# fatorial(5) -> 120
# fatorial(10) -> 3628800
```

---

## Exercício 2 - Fibonacci

Escreva uma função recursiva que retorne o n-ésimo número da sequência de Fibonacci.

A sequência começa com: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

```python
def fibonacci(n):
    # seu codigo aqui
    pass

# Exemplos:
# fibonacci(0) -> 0
# fibonacci(1) -> 1
# fibonacci(6) -> 8
# fibonacci(10) -> 55
```

---

## Exercício 3 - Soma de dígitos

Escreva uma função recursiva que calcule a soma dos dígitos de um número inteiro positivo.

```python
def soma_digitos(n):
    # seu codigo aqui
    pass

# Exemplos:
# soma_digitos(123) -> 6  (1 + 2 + 3)
# soma_digitos(9999) -> 36  (9 + 9 + 9 + 9)
# soma_digitos(5) -> 5
```

---

## Exercício 4 - Potência

Escreva uma função recursiva que calcule `base` elevado a `expoente` sem usar o operador `**`.

```python
def potencia(base, expoente):
    # seu codigo aqui
    pass

# Exemplos:
# potencia(2, 3) -> 8
# potencia(5, 0) -> 1
# potencia(3, 4) -> 81
```

---

## Exercício 5 - Inverter string

Escreva uma função recursiva que inverta uma string.

```python
def inverter(s):
    # seu codigo aqui
    pass

# Exemplos:
# inverter("python") -> "nohtyp"
# inverter("abcd") -> "dcba"
# inverter("a") -> "a"
```

---

## Exercício 6 - Verificar palíndromo (recursivo)

Escreva uma função recursiva que verifique se uma string é um palíndromo.

```python
def eh_palindromo(s):
    # seu codigo aqui
    pass

# Exemplos:
# eh_palindromo("arara") -> True
# eh_palindromo("abcba") -> True
# eh_palindromo("python") -> False
```

---

## Exercício 7 - Torre de Hanoi

Implemente a solução recursiva para o problema da Torre de Hanoi. O programa deve imprimir cada movimento necessário.

```python
def hanoi(n, origem, destino, auxiliar):
    # seu codigo aqui
    pass

# Exemplo:
# hanoi(3, "A", "C", "B")
# Saída:
# Mover disco 1 de A para C
# Mover disco 2 de A para B
# Mover disco 1 de C para B
# Mover disco 3 de A para C
# Mover disco 1 de B para A
# Mover disco 2 de B para C
# Mover disco 1 de A para C
```

---

## Exercício 8 - Achatar lista

Escreva uma função recursiva que "achate" (flatten) uma lista aninhada em uma lista simples.

```python
def achatar(lista):
    # seu codigo aqui
    pass

# Exemplos:
# achatar([1, [2, 3], [4, [5, 6]]]) -> [1, 2, 3, 4, 5, 6]
# achatar([[1, 2], [3, [4, [5]]]]) -> [1, 2, 3, 4, 5]
# achatar([1, 2, 3]) -> [1, 2, 3]
```
