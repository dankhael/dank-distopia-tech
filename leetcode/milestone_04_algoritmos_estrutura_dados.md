# Milestone 4 - Algoritmos e Estrutura de Dados

**Tema:** Dicionários, listas, tuplos, fila, pilha e algoritmos de ordenação

**Linguagem:** Python

---

## Exercício 1 - Contador de palavras

Dada uma string com várias palavras, use um dicionário para contar quantas vezes cada palavra aparece.

```python
def contar_palavras(texto):
    # seu codigo aqui
    pass

# Exemplo:
# contar_palavras("o gato viu o rato e o rato viu o gato")
# -> {"o": 4, "gato": 2, "viu": 2, "rato": 2, "e": 1}
```

---

## Exercício 2 - Pilha com lista

Implemente uma pilha (stack) usando uma lista Python com as operações:
- `push(item)`: adiciona um item ao topo
- `pop()`: remove e retorna o item do topo
- `peek()`: retorna o item do topo sem remover
- `is_empty()`: retorna True se a pilha estiver vazia

```python
class Pilha:
    def __init__(self):
        self.items = []

    def push(self, item):
        pass

    def pop(self):
        pass

    def peek(self):
        pass

    def is_empty(self):
        pass

# Teste:
# p = Pilha()
# p.push(1)
# p.push(2)
# p.push(3)
# print(p.peek())  -> 3
# print(p.pop())   -> 3
# print(p.pop())   -> 2
```

---

## Exercício 3 - Fila com lista

Implemente uma fila (queue) usando uma lista Python com as operações:
- `enqueue(item)`: adiciona um item ao final da fila
- `dequeue()`: remove e retorna o primeiro item da fila
- `front()`: retorna o primeiro item sem remover
- `is_empty()`: retorna True se a fila estiver vazia

```python
class Fila:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        pass

    def dequeue(self):
        pass

    def front(self):
        pass

    def is_empty(self):
        pass

# Teste:
# f = Fila()
# f.enqueue("A")
# f.enqueue("B")
# f.enqueue("C")
# print(f.front())    -> "A"
# print(f.dequeue())  -> "A"
# print(f.dequeue())  -> "B"
```

---

## Exercício 4 - Bubble Sort

Implemente o algoritmo Bubble Sort para ordenar uma lista de números em ordem crescente.

```python
def bubble_sort(lista):
    # seu codigo aqui
    pass

# Exemplo:
# bubble_sort([64, 34, 25, 12, 22, 11, 90])
# -> [11, 12, 22, 25, 34, 64, 90]
```

**Desafio extra:** Imprima o estado da lista após cada passagem do algoritmo para visualizar o processo de ordenação.

---

## Exercício 5 - Tuplos e coordenadas

Dada uma lista de tuplos representando coordenadas `(x, y)`, escreva uma função que calcule a distância entre cada par consecutivo de pontos.

**Fórmula da distância:** `d = sqrt((x2-x1)^2 + (y2-y1)^2)`

```python
import math

def distancias_consecutivas(pontos):
    # seu codigo aqui
    pass

# Exemplo:
# pontos = [(0, 0), (3, 4), (6, 8)]
# distancias_consecutivas(pontos) -> [5.0, 5.0]
```

---

## Exercício 6 - Agenda telefônica

Crie uma agenda telefônica usando dicionários com as seguintes funcionalidades:
- Adicionar contato (nome e telefone)
- Buscar contato pelo nome
- Remover contato
- Listar todos os contatos

```python
class Agenda:
    def __init__(self):
        self.contatos = {}

    def adicionar(self, nome, telefone):
        pass

    def buscar(self, nome):
        pass

    def remover(self, nome):
        pass

    def listar(self):
        pass

# Teste:
# ag = Agenda()
# ag.adicionar("Maria", "11999990000")
# ag.adicionar("Joao", "11988880000")
# ag.buscar("Maria")  -> "11999990000"
# ag.listar()  -> {"Maria": "11999990000", "Joao": "11988880000"}
```

---

## Exercício 7 - Selection Sort

Implemente o algoritmo Selection Sort para ordenar uma lista de números.

```python
def selection_sort(lista):
    # seu codigo aqui
    pass

# Exemplo:
# selection_sort([29, 10, 14, 37, 13])
# -> [10, 13, 14, 29, 37]
```

---

## Exercício 8 - Frequência de caracteres

Escreva uma função que receba uma string e retorne um dicionário com a frequência de cada caractere, ordenado do mais frequente para o menos frequente.

```python
def frequencia_ordenada(texto):
    # seu codigo aqui
    pass

# Exemplo:
# frequencia_ordenada("abracadabra")
# -> [('a', 5), ('b', 2), ('r', 2), ('c', 1), ('d', 1)]
```
