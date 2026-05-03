# Milestone 8 - Revisão e Reforço

**Tema:** Exercícios integradores que combinam conceitos das milestones anteriores

**Linguagem:** Python

---

## Exercício 1 - Gerenciador de tarefas

Crie um sistema de gerenciamento de tarefas que combine listas, dicionários, loops e funções. O sistema deve:
- Adicionar tarefa com título, prioridade (1-5) e status ("pendente"/"concluída")
- Listar tarefas ordenadas por prioridade
- Marcar tarefa como concluída
- Filtrar tarefas por status
- Remover tarefas concluídas

```python
class GerenciadorTarefas:
    def __init__(self):
        self.tarefas = []

    def adicionar(self, titulo, prioridade):
        pass

    def listar_por_prioridade(self):
        pass

    def concluir(self, titulo):
        pass

    def filtrar_por_status(self, status):
        pass

    def limpar_concluidas(self):
        pass
```

---

## Exercício 2 - Analisador de texto

Crie uma função que analise um texto e retorne um dicionário com:
- Total de palavras
- Total de caracteres (sem espaços)
- Palavra mais frequente
- Palavra mais longa
- Número de frases

```python
def analisar_texto(texto):
    # seu codigo aqui
    pass

# Exemplo:
# texto = "O Python é incrível. Python é usado por muitos. Eu amo Python."
# analisar_texto(texto) ->
# {
#     "total_palavras": 12,
#     "total_caracteres": 46,
#     "palavra_mais_frequente": "python",
#     "palavra_mais_longa": "incrivel",
#     "numero_frases": 3
# }
```

---

## Exercício 3 - Mini banco de dados

Implemente um sistema simples que simule um banco de dados em memória para registrar alunos com:
- Inserir aluno (nome, idade, notas)
- Buscar aluno por nome
- Calcular média de um aluno
- Listar alunos aprovados (média >= 7)
- Ranking dos alunos por média (usando sort)

Use recursão para calcular a média se o aluno tiver sub-notas aninhadas.

```python
class MiniDB:
    def __init__(self):
        self.alunos = {}

    def inserir(self, nome, idade, notas):
        pass

    def buscar(self, nome):
        pass

    def media(self, nome):
        pass

    def aprovados(self):
        pass

    def ranking(self):
        pass
```

---

## Exercício 4 - Jogo da forca

Implemente o jogo da forca usando conceitos de strings, listas, loops e condicionais.

Requisitos:
- Lista de palavras pré-definidas, escolha aleatória
- Mostrar a palavra com letras ocultas (underscores)
- Controlar letras já tentadas
- Limitar número de erros (6 tentativas)
- Mostrar as partes do boneco a cada erro

```python
import random

def jogo_da_forca():
    palavras = ["python", "programacao", "algoritmo", "recursao", "variavel"]
    # seu codigo aqui
    pass
```

---

## Exercício 5 - Encontrar caminho em labirinto

Dado um labirinto representado como uma matriz 2D, use recursão (backtracking) para encontrar um caminho do canto superior esquerdo ao canto inferior direito.

- `0` = caminho livre
- `1` = parede

```python
def resolver_labirinto(labirinto):
    # seu codigo aqui
    pass

# Exemplo:
# labirinto = [
#     [0, 1, 0, 0],
#     [0, 0, 0, 1],
#     [1, 0, 1, 0],
#     [0, 0, 0, 0]
# ]
# resolver_labirinto(labirinto) -> [(0,0), (1,0), (1,1), (1,2), (2,1), (3,1), (3,2), (3,3)]
```

---

## Exercício 6 - Sistema de busca

Crie um sistema de busca que indexe uma lista de textos e permita buscar por palavras-chave. Combine dicionários, listas e algoritmos de busca.

```python
class BuscaTexto:
    def __init__(self):
        self.indice = {}
        self.documentos = []

    def adicionar_documento(self, texto):
        """Indexa o documento para busca rápida"""
        pass

    def buscar(self, palavra):
        """Retorna lista de documentos que contêm a palavra"""
        pass

    def buscar_multiplas(self, palavras):
        """Retorna documentos que contêm TODAS as palavras"""
        pass

# Teste:
# b = BuscaTexto()
# b.adicionar_documento("Python é uma linguagem de programação")
# b.adicionar_documento("Java também é uma linguagem popular")
# b.adicionar_documento("Python é usado para ciência de dados")
# b.buscar("Python") -> [0, 2]
# b.buscar_multiplas(["Python", "dados"]) -> [2]
```
