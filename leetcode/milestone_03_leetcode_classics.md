# Milestone 3 - Leetcode Classics

**Tema:** Problemas classicos de programacao no estilo Leetcode

**Linguagem:** Python

---

## Exercicio 1 - Two Sum

Dada uma lista de inteiros `nums` e um inteiro `target`, retorne os indices dos dois numeros cuja soma e igual ao `target`.

Voce pode assumir que cada entrada tem exatamente uma solucao e nao pode usar o mesmo elemento duas vezes.

```python
def two_sum(nums, target):
    # seu codigo aqui
    pass

# Exemplo:
# two_sum([2, 7, 11, 15], 9) -> [0, 1]
# Explicacao: nums[0] + nums[1] = 2 + 7 = 9
```

---

## Exercicio 2 - Palindromo

Escreva uma funcao que verifique se uma string e um palindromo (le-se igual de tras pra frente). Ignore espacos e diferencas entre maiusculas/minusculas.

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

## Exercicio 3 - FizzBuzz

Imprima os numeros de 1 a 100, mas:
- Para multiplos de 3, imprima `"Fizz"` em vez do numero
- Para multiplos de 5, imprima `"Buzz"` em vez do numero
- Para multiplos de 3 e 5, imprima `"FizzBuzz"`

**Saida parcial:**
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

## Exercicio 4 - Numero reverso

Escreva uma funcao que receba um inteiro e retorne o numero com os digitos invertidos.

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

## Exercicio 5 - Anagramas

Escreva uma funcao que verifique se duas strings sao anagramas (contem as mesmas letras, na mesma quantidade).

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

## Exercicio 6 - Maior sequencia de caracteres

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

## Exercicio 7 - Numeros romanos

Escreva uma funcao que converta um numero inteiro (1 a 3999) para algarismos romanos.

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

## Exercicio 8 - Parenteses validos

Dada uma string contendo apenas os caracteres `(`, `)`, `{`, `}`, `[` e `]`, determine se a string e valida. Uma string e valida se cada abertura tem um fechamento correspondente na ordem correta.

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
