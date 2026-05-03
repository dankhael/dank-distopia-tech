# Milestone 6 - Lambda Functions, Map, Filter e Sort

**Tema:** Funções lambda, map, filter e sort

**Linguagem:** Python

---

## Exercício 1 - Lambda básico

Crie funções lambda para:
- Dobrar um número
- Verificar se um número é positivo
- Retornar o maior entre dois números

```python
dobrar = # sua lambda aqui
eh_positivo = # sua lambda aqui
maior = # sua lambda aqui

# Testes:
# dobrar(5) -> 10
# eh_positivo(-3) -> False
# maior(4, 7) -> 7
```

---

## Exercício 2 - Map para transformar dados

Dada uma lista de temperaturas em Celsius, use `map` com uma lambda para converter todas para Fahrenheit.

```python
celsius = [0, 20, 30, 37, 100]

fahrenheit = # use map aqui

# Resultado esperado: [32.0, 68.0, 86.0, 98.6, 212.0]
```

---

## Exercício 3 - Filter para selecionar dados

Dada uma lista de números, use `filter` para:
1. Obter apenas os números pares
2. Obter apenas os números maiores que 10
3. Obter apenas os números negativos

```python
numeros = [-5, 3, 12, -8, 7, 15, 20, -1, 8, 0]

pares = # use filter aqui
maiores_que_10 = # use filter aqui
negativos = # use filter aqui

# pares -> [12, -8, 20, 8, 0]
# maiores_que_10 -> [12, 15, 20]
# negativos -> [-5, -8, -1]
```

---

## Exercício 4 - Sort com chave customizada

Dada uma lista de tuplas `(nome, idade)`, ordene:
1. Por nome (ordem alfabética)
2. Por idade (crescente)
3. Por idade (decrescente)

```python
pessoas = [("Ana", 25), ("Carlos", 19), ("Bruna", 30), ("Diego", 22)]

por_nome = # use sorted aqui
por_idade = # use sorted aqui
por_idade_desc = # use sorted aqui

# por_nome -> [("Ana", 25), ("Bruna", 30), ("Carlos", 19), ("Diego", 22)]
# por_idade -> [("Carlos", 19), ("Diego", 22), ("Ana", 25), ("Bruna", 30)]
# por_idade_desc -> [("Bruna", 30), ("Ana", 25), ("Diego", 22), ("Carlos", 19)]
```

---

## Exercício 5 - Pipeline de dados

Dada uma lista de strings com nomes, crie um pipeline que:
1. Remova nomes com menos de 4 caracteres (filter)
2. Converta todos para maiúsculo (map)
3. Ordene em ordem alfabética (sorted)

```python
nomes = ["ana", "carlos", "bo", "maria", "li", "fernando", "bea"]

resultado = # combine filter, map e sorted

# Resultado esperado: ["CARLOS", "FERNANDO", "MARIA"]
```

---

## Exercício 6 - Ordenar dicionários

Dado um dicionário com produtos e preços, retorne uma lista de tuplas ordenada:
1. Por preço (menor para maior)
2. Por nome do produto (ordem alfabética)

```python
produtos = {
    "notebook": 3500,
    "mouse": 80,
    "teclado": 200,
    "monitor": 1500,
    "webcam": 350
}

por_preco = # use sorted com items()
por_nome = # use sorted com items()

# por_preco -> [("mouse", 80), ("teclado", 200), ("webcam", 350), ("monitor", 1500), ("notebook", 3500)]
```

---

## Exercício 7 - Map e Filter combinados

Dada uma lista de números, use `map` e `filter` em conjunto para retornar o quadrado de todos os números ímpares.

```python
numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

resultado = # combine map e filter

# Resultado esperado: [1, 9, 25, 49, 81]
```

---

## Exercício 8 - Ordenação de strings por critério

Dada uma lista de palavras, ordene-as por:
1. Tamanho da palavra (menor para maior)
2. Última letra da palavra (ordem alfabética)
3. Número de vogais (maior para menor)

```python
palavras = ["python", "java", "go", "javascript", "rust", "c", "typescript"]

por_tamanho = # use sorted aqui
por_ultima_letra = # use sorted aqui
por_vogais = # use sorted aqui
```
