# Milestone 3 - Leetcode Classics

**Tema:** Problemas clássicos de programação no estilo Leetcode

**Linguagem:** Python

---

## Exercício 1 - Two Sum

Dada uma lista de inteiros `nums` e um inteiro `target`, retorne os índices dos dois números cuja soma é igual ao `target`.

Você pode assumir que cada entrada tem exatamente uma solução e não pode usar o mesmo elemento duas vezes.

```python
def two_sum(nums, target):
    # seu codigo aqui
    pass

# Exemplo:
# two_sum([2, 7, 11, 15], 9) -> [0, 1]
# Explicação: nums[0] + nums[1] = 2 + 7 = 9
```

---

## Exercício 2 - Palíndromo

Escreva uma função que verifique se uma string é um palíndromo (lê-se igual de trás para frente). Ignore espaços e diferenças entre maiúsculas/minúsculas.

```python
def eh_palindromo(s):
    # seu codigo aqui
    pass

# Exemplos:
# eh_palindromo("arara") -> True
# eh_palindromo("Ana") -> True
# eh_palindromo("python") -> False
```

---

## Exercício 3 - FizzBuzz

Imprima os números de 1 a 100, mas:
- Para múltiplos de 3, imprima `"Fizz"` em vez do número
- Para múltiplos de 5, imprima `"Buzz"` em vez do número
- Para múltiplos de 3 e 5, imprima `"FizzBuzz"`

**Saída parcial:**
```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
...
```

---

## Exercício 4 - Número reverso

Escreva uma função que receba um inteiro e retorne o número com os dígitos invertidos.

```python
def reverter_numero(n):
    # seu codigo aqui
    pass

# Exemplos:
# reverter_numero(123) -> 321
# reverter_numero(-456) -> -654
# reverter_numero(100) -> 1
```

---

## Exercício 5 - Anagramas

Escreva uma função que verifique se duas strings são anagramas (contêm as mesmas letras, na mesma quantidade).

```python
def sao_anagramas(s1, s2):
    # seu codigo aqui
    pass

# Exemplos:
# sao_anagramas("listen", "silent") -> True
# sao_anagramas("hello", "world") -> False
# sao_anagramas("amor", "roma") -> True
```

---

## Exercício 6 - Maior sequência de caracteres

Dada uma string, encontre o comprimento da maior substring sem caracteres repetidos.

```python
def maior_substring_unica(s):
    # seu codigo aqui
    pass

# Exemplos:
# maior_substring_unica("abcabcbb") -> 3  (abc)
# maior_substring_unica("bbbbb") -> 1  (b)
# maior_substring_unica("pwwkew") -> 3  (wke)
```

---

## Exercício 7 - Números romanos

Escreva uma função que converta um número inteiro (1 a 3999) para algarismos romanos.

```python
def para_romano(num):
    # seu codigo aqui
    pass

# Exemplos:
# para_romano(3) -> "III"
# para_romano(58) -> "LVIII"
# para_romano(1994) -> "MCMXCIV"
```

---

## Exercício 8 - Parênteses válidos

Dada uma string contendo apenas os caracteres `(`, `)`, `{`, `}`, `[` e `]`, determine se a string é válida. Uma string é válida se cada abertura tem um fechamento correspondente na ordem correta.

```python
def parenteses_validos(s):
    # seu codigo aqui
    pass

# Exemplos:
# parenteses_validos("()") -> True
# parenteses_validos("()[]{}") -> True
# parenteses_validos("(]") -> False
# parenteses_validos("([)]") -> False
# parenteses_validos("{[]}") -> True
```
