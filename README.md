# Projeto de programação 1
Turma: 2016.2

Participantes: 

  - Hugo Davi Alves de Oliveira
  - Arquimedes Vinícius Pereira de França Moura
 
# PAC-MAN

O jogador controla o "personagem" que é uma bola redonda com uma
boca que se abre e fecha, posicionado em um labirinto simples repleto
de pastilhas e 4 fantasmas que o perseguiam. O objetivo era comer 
todas as pastilhas sem ser alcançado pelos fantasmas, em ritmo 
progressivo de dificuldade.

### Funcionalidades do jogo:

O jogador controla a direção do "personagem" (para cima,para baixo,
para a esquerda e para a direita) usando os botões diretores disponíveis no teclado, a cada nível a dificuldade aumenta mas com o mesmo objetivo, comer todas as pastilhas sem ser alcançado pelos fantasmas. 


# Assuntos utilizados:

  - Condicionais(IF/ELSE) 
  - Repetição(FOR/WHILE)
  - Recursão
  - Ordenação
  - Ponteiros
  - Matrizes
  - ArraysS
  - Alocação dinâmica
  - Busca

Condicionais:

> Serão utilizados principalmente para as funções 
> básicas do jogo, como mudar a direção do personagem,
> animação de game over e de especial, sincronização
> dos sons e imagens em momentos específicos.


Repetidores:
>Serão utilizados para a movimentação do personagem
>e dos fantasmas, fazendo eles andarem até que alguma
>condição seja satisfeita.


Ordenação:
>Iremos usar ordenação para o sistema de ranking,
>quando o usuário bater algum recorde ou entrar
>para o top 10, iremos usar o sistema de ordenação
>para coloca-lo na posição correta.


Ponteiros:
>Iremos usar ponteiros para auxiliar no sistema de ordenação,
>para alocar dinamicamente tamanho de vetores e também para 
>trabalharmos alocação de termos em uma matriz.


Matriz:
>Iremos usar matrizes principalmente para fazer o "tabuleiro" 
>do jogo, definir limites e áreas a serem percorridas, áreas 
>de colisão e a área de loop nas extremidades do mapa.


Array:
>Iremos utilizar array circular para realizar a função de
>tele-transporte do jogo, que é realizado na metade do 
>"tabuleiro" e faz o personagem passar e uma extremidade 
>do tabuleiro a outra.