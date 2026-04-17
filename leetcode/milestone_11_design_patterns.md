# Milestone 11 - Design Patterns

**Tema:** Padroes de projeto mais utilizados na pratica

**Linguagem:** Java

---

## Exercicio 1 - Singleton

Implemente o padrao Singleton para uma classe `ConfigManager` que carrega e armazena configuracoes da aplicacao. Garanta que apenas uma instancia exista.

```java
public class ConfigManager {
    private static ConfigManager instancia;
    private Map<String, String> configs;

    private ConfigManager() {
        configs = new HashMap<>();
    }

    public static ConfigManager getInstancia() {
        // seu codigo aqui
    }

    public void setConfig(String chave, String valor) {
        // seu codigo aqui
    }

    public String getConfig(String chave) {
        // seu codigo aqui
    }

    public static void main(String[] args) {
        ConfigManager c1 = ConfigManager.getInstancia();
        c1.setConfig("tema", "escuro");

        ConfigManager c2 = ConfigManager.getInstancia();
        System.out.println(c2.getConfig("tema")); // "escuro"
        System.out.println(c1 == c2);              // true
    }
}
```

---

## Exercicio 2 - Factory Method

Crie uma fabrica de formas geometricas. A classe `FormaFactory` deve receber o tipo da forma como string e retornar a instancia correta.

```java
public interface Forma {
    void desenhar();
    double calcularArea();
}

// Implemente Circulo, Quadrado e Triangulo

public class FormaFactory {
    public static Forma criarForma(String tipo, double... parametros) {
        // seu codigo aqui
        // "circulo" -> new Circulo(parametros[0])
        // "quadrado" -> new Quadrado(parametros[0])
        // "triangulo" -> new Triangulo(parametros[0], parametros[1])
    }

    public static void main(String[] args) {
        Forma c = FormaFactory.criarForma("circulo", 5);
        Forma q = FormaFactory.criarForma("quadrado", 4);
        c.desenhar();  // "Desenhando circulo com raio 5"
        System.out.println(c.calcularArea()); // 78.54
    }
}
```

---

## Exercicio 3 - Observer

Implemente o padrao Observer para um sistema de noticias. Quando uma noticia e publicada, todos os assinantes sao notificados.

```java
public interface Observador {
    void atualizar(String noticia);
}

public interface Publicador {
    void inscrever(Observador o);
    void desinscrever(Observador o);
    void notificarTodos();
}

public class AgenciaNoticias implements Publicador {
    private List<Observador> observadores;
    private String ultimaNoticia;

    // implemente os metodos

    public void publicarNoticia(String noticia) {
        this.ultimaNoticia = noticia;
        notificarTodos();
    }
}

public class Leitor implements Observador {
    private String nome;

    @Override
    public void atualizar(String noticia) {
        System.out.println(nome + " recebeu: " + noticia);
    }
}

// Teste:
// AgenciaNoticias agencia = new AgenciaNoticias();
// agencia.inscrever(new Leitor("Ana"));
// agencia.inscrever(new Leitor("Bruno"));
// agencia.publicarNoticia("Java 25 lancado!");
// -> "Ana recebeu: Java 25 lancado!"
// -> "Bruno recebeu: Java 25 lancado!"
```

---

## Exercicio 4 - Strategy

Implemente o padrao Strategy para um sistema de calculo de frete. Diferentes estrategias de envio tem custos diferentes.

```java
public interface EstrategiaFrete {
    double calcular(double peso, double distancia);
}

public class FreteEconomico implements EstrategiaFrete {
    @Override
    public double calcular(double peso, double distancia) {
        return peso * 0.5 + distancia * 0.1;
    }
}

public class FreteExpresso implements EstrategiaFrete {
    // custo mais alto, entrega rapida
}

public class FreteSedex implements EstrategiaFrete {
    // custo intermediario
}

public class CalculadoraFrete {
    private EstrategiaFrete estrategia;

    public void setEstrategia(EstrategiaFrete estrategia) {
        this.estrategia = estrategia;
    }

    public double calcular(double peso, double distancia) {
        return estrategia.calcular(peso, distancia);
    }
}

// Teste:
// CalculadoraFrete calc = new CalculadoraFrete();
// calc.setEstrategia(new FreteEconomico());
// System.out.println(calc.calcular(2.0, 100)); // 21.0
// calc.setEstrategia(new FreteExpresso());
// System.out.println(calc.calcular(2.0, 100)); // valor diferente
```

---

## Exercicio 5 - Decorator

Implemente o padrao Decorator para um sistema de pedidos de cafe. O cafe base pode receber decoradores como leite, chocolate, chantilly, etc.

```java
public interface Bebida {
    String descricao();
    double preco();
}

public class CafeSimples implements Bebida {
    @Override
    public String descricao() { return "Cafe simples"; }

    @Override
    public double preco() { return 5.0; }
}

public abstract class DecoradorBebida implements Bebida {
    protected Bebida bebida;

    public DecoradorBebida(Bebida bebida) {
        this.bebida = bebida;
    }
}

// Implemente: ComLeite, ComChocolate, ComChantilly

// Teste:
// Bebida pedido = new CafeSimples();
// pedido = new ComLeite(pedido);
// pedido = new ComChocolate(pedido);
// System.out.println(pedido.descricao()); // "Cafe simples + Leite + Chocolate"
// System.out.println(pedido.preco());     // 5.0 + 2.0 + 3.0 = 10.0
```

---

## Exercicio 6 - Adapter

Crie um Adapter para integrar um sistema de pagamento antigo com uma nova interface.

```java
// Interface nova que o sistema espera
public interface ProcessadorPagamento {
    boolean processar(String cartao, double valor);
    boolean estornar(String transacaoId);
}

// Sistema legado com interface diferente
public class SistemaPagamentoLegado {
    public int realizarCobranca(String numCartao, int valorCentavos) {
        System.out.println("Cobrando " + valorCentavos + " centavos do cartao " + numCartao);
        return 1; // codigo de sucesso
    }

    public int cancelarCobranca(int codigoTransacao) {
        System.out.println("Cancelando transacao " + codigoTransacao);
        return 1;
    }
}

// Implemente o Adapter
public class AdapterPagamento implements ProcessadorPagamento {
    private SistemaPagamentoLegado sistemaLegado;

    // adapte os metodos
}
```

---

## Exercicio 7 - Builder

Implemente o padrao Builder para construir objetos `Pedido` complexos de forma legivel.

```java
public class Pedido {
    private String cliente;
    private List<String> itens;
    private String endereco;
    private String formaPagamento;
    private boolean embrulhoPresente;
    private String observacao;

    // construtor privado

    public static class Builder {
        private String cliente;
        private List<String> itens = new ArrayList<>();
        private String endereco;
        private String formaPagamento;
        private boolean embrulhoPresente = false;
        private String observacao = "";

        public Builder(String cliente) {
            this.cliente = cliente;
        }

        public Builder adicionarItem(String item) {
            // seu codigo aqui
        }

        public Builder endereco(String endereco) {
            // seu codigo aqui
        }

        public Builder pagamento(String forma) {
            // seu codigo aqui
        }

        public Builder comEmbrulho() {
            // seu codigo aqui
        }

        public Builder observacao(String obs) {
            // seu codigo aqui
        }

        public Pedido build() {
            // seu codigo aqui
        }
    }

    public static void main(String[] args) {
        Pedido pedido = new Pedido.Builder("Ana")
            .adicionarItem("Notebook")
            .adicionarItem("Mouse")
            .endereco("Rua A, 123")
            .pagamento("Cartao")
            .comEmbrulho()
            .observacao("Entregar pela manha")
            .build();
    }
}
```

---

## Exercicio 8 - Projeto final: Combinando patterns

Crie um mini sistema de e-commerce que combine multiplos design patterns:

- **Singleton**: `Loja` (unica instancia)
- **Factory**: Criar diferentes tipos de `Produto` (fisico, digital, servico)
- **Observer**: Notificar clientes quando um produto volta ao estoque
- **Strategy**: Diferentes formas de calculo de desconto (desconto fixo, percentual, progressivo)
- **Builder**: Construir pedidos complexos

```java
// Este exercicio e aberto - planeje a arquitetura e implemente
// o sistema combinando os patterns aprendidos.
//
// Requisitos minimos:
// 1. Cadastro de produtos (factory)
// 2. Instancia unica da loja (singleton)
// 3. Notificacao de clientes sobre estoque (observer)
// 4. Calculo de desconto configuravel (strategy)
// 5. Montagem de pedidos (builder)
//
// Bonus: adicione Decorator para servicos extras no pedido
// (embrulho, entrega expressa, seguro)
```
