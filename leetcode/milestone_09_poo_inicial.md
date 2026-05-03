# Milestone 9 - Conceitos Iniciais de Programação Orientada a Objeto

**Tema:** Classes, objetos, atributos, métodos, encapsulamento e herança

**Linguagem:** Java

---

## Exercício 1 - Primeira classe

Crie uma classe `Pessoa` com atributos `nome` e `idade`, um construtor, e um método `apresentar()` que imprima uma mensagem.

```java
public class Pessoa {
    // atributos

    // construtor

    // metodo apresentar()

    public static void main(String[] args) {
        Pessoa p = new Pessoa("Maria", 25);
        p.apresentar();
        // Saída: Olá, meu nome é Maria e tenho 25 anos.
    }
}
```

---

## Exercício 2 - Conta bancária

Crie uma classe `ContaBancaria` com:
- Atributos privados: `titular`, `saldo`
- Métodos: `depositar(valor)`, `sacar(valor)`, `consultarSaldo()`
- O saque só deve ser permitido se houver saldo suficiente

```java
public class ContaBancaria {
    private String titular;
    private double saldo;

    // construtor

    public void depositar(double valor) {
        // seu codigo aqui
    }

    public boolean sacar(double valor) {
        // seu codigo aqui
    }

    public double consultarSaldo() {
        // seu codigo aqui
    }

    public static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria("Carlos", 1000);
        conta.depositar(500);
        System.out.println(conta.consultarSaldo()); // 1500.0
        conta.sacar(200);
        System.out.println(conta.consultarSaldo()); // 1300.0
        conta.sacar(2000); // Saldo insuficiente!
    }
}
```

---

## Exercício 3 - Getters e Setters

Crie uma classe `Produto` com atributos privados `nome`, `preco` e `quantidade`. Implemente getters e setters com validação (preco e quantidade não podem ser negativos).

```java
public class Produto {
    private String nome;
    private double preco;
    private int quantidade;

    // construtor

    // getters e setters com validação

    public double valorTotal() {
        return preco * quantidade;
    }

    public static void main(String[] args) {
        Produto p = new Produto("Notebook", 3500.00, 10);
        System.out.println(p.getPreco());      // 3500.0
        p.setPreco(-100);                       // Preço inválido!
        System.out.println(p.valorTotal());     // 35000.0
    }
}
```

---

## Exercício 4 - Herança básica

Crie uma classe `Animal` com atributo `nome` e método `emitirSom()`. Depois crie subclasses `Cachorro` e `Gato` que sobrescrevam o método.

```java
public class Animal {
    protected String nome;

    public Animal(String nome) {
        this.nome = nome;
    }

    public void emitirSom() {
        System.out.println(nome + " faz um som.");
    }
}

// Crie as classes Cachorro e Gato que herdam de Animal

// Teste:
// Cachorro c = new Cachorro("Rex");
// c.emitirSom(); -> "Rex faz Au Au!"
// Gato g = new Gato("Mimi");
// g.emitirSom(); -> "Mimi faz Miau!"
```

---

## Exercício 5 - Construtor com super

Crie uma classe `Veiculo` com atributos `marca`, `modelo` e `ano`. Depois crie `Carro` que herda de `Veiculo` e adiciona o atributo `numPortas`. Use `super()` no construtor.

```java
public class Veiculo {
    protected String marca;
    protected String modelo;
    protected int ano;

    // construtor
}

public class Carro extends Veiculo {
    private int numPortas;

    // construtor usando super()

    // método exibirInfo()
}

// Teste:
// Carro c = new Carro("Toyota", "Corolla", 2023, 4);
// c.exibirInfo();
// -> Toyota Corolla 2023 - 4 portas
```

---

## Exercício 6 - toString e equals

Crie uma classe `Aluno` com `nome`, `matricula` e `curso`. Sobrescreva os métodos `toString()` e `equals()` (dois alunos são iguais se tiverem a mesma matrícula).

```java
public class Aluno {
    private String nome;
    private int matricula;
    private String curso;

    // construtor

    @Override
    public String toString() {
        // seu codigo aqui
    }

    @Override
    public boolean equals(Object obj) {
        // seu codigo aqui
    }

    public static void main(String[] args) {
        Aluno a1 = new Aluno("Ana", 12345, "CC");
        Aluno a2 = new Aluno("Ana Silva", 12345, "Computacao");
        System.out.println(a1);              // Aluno{nome=Ana, matricula=12345, curso=CC}
        System.out.println(a1.equals(a2));   // true (mesma matrícula)
    }
}
```

---

## Exercício 7 - ArrayList de objetos

Crie uma classe `Turma` que gerencie uma lista de alunos usando `ArrayList`. Implemente:
- `adicionarAluno(Aluno a)`
- `removerAluno(int matricula)`
- `buscarAluno(int matricula)`
- `listarAlunos()`

```java
import java.util.ArrayList;

public class Turma {
    private ArrayList<Aluno> alunos;

    public Turma() {
        this.alunos = new ArrayList<>();
    }

    // implemente os métodos

    public static void main(String[] args) {
        Turma t = new Turma();
        t.adicionarAluno(new Aluno("Ana", 1, "CC"));
        t.adicionarAluno(new Aluno("Bruno", 2, "EC"));
        t.listarAlunos();
        t.removerAluno(1);
        t.listarAlunos();
    }
}
```

---

## Exercício 8 - Métodos estáticos

Crie uma classe utilitária `MathUtils` com métodos estáticos:
- `max(int a, int b)`: retorna o maior
- `min(int a, int b)`: retorna o menor
- `media(int[] numeros)`: retorna a média
- `fatorial(int n)`: retorna o fatorial
- `ehPrimo(int n)`: verifica se é primo

```java
public class MathUtils {

    public static int max(int a, int b) {
        // seu codigo aqui
    }

    public static int min(int a, int b) {
        // seu codigo aqui
    }

    public static double media(int[] numeros) {
        // seu codigo aqui
    }

    public static long fatorial(int n) {
        // seu codigo aqui
    }

    public static boolean ehPrimo(int n) {
        // seu codigo aqui
    }

    public static void main(String[] args) {
        System.out.println(MathUtils.max(5, 3));        // 5
        System.out.println(MathUtils.media(new int[]{7, 8, 9})); // 8.0
        System.out.println(MathUtils.fatorial(5));       // 120
        System.out.println(MathUtils.ehPrimo(17));       // true
    }
}
```
