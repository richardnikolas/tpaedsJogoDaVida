# TP AEDS - Jogo Da Vida
<b><h2>Introdução</h2></b>

O Jogo da Vida foi criado pelo matemático britânico John Horton Conway em 1970. Antes de continuar, leia as seguintes fontes:

http://en.wikipedia.org/wiki/Conway's_Game_of_Life <br>
http://pt.wikipedia.org/wiki/Jogo_da_vida (em português)

<b> (TODAS AS FIGURAS/IMAGENS ESTARÃO NA PASTA "FIGURAS") </b><br>

O objetivo do “jogo” é reproduzir, através de regras simples, as alterações e mudanças em grupos de seres vivos, tendo aplicações em diversas áreas da ciência. As regras definidas são aplicadas a cada nova "geração". Desta forma, a partir de uma imagem em
um tabuleiro bidimensional definida pelo jogador, percebem-se mudanças muitas vezes inesperadas e belas a cada nova geração, variando de padrões fixos a caóticos.

A Figura 1 mostra um exemplo de geração do Jogo da Vida. Essa formação, conhecida como Glider Gun, foi porposta por Bill Gosper em 1970. Neste tabuleiro, quadros em preto representam células vivas e quadros em branco, células mortas. A formação da Figura 1 pode ser vista evoluindo dinamicamente em http://en.wikipedia.org/wiki/File:Gospers_glider_gun.gif. Nessa figura, as gerações são calculadas usando regras bem definidas. A variação da figura, de geração para geração, causa o efeito visual bonito e surprendente. A seguir veremos como as células mudam de geração em geração, formando figuras dinâmicas.

<b><h2>Regras de Funcionamento</h2></b>
Para aplicar as regras, é necessária a definição de v izinhos. Uma célula tem 3, 5 ou 8 vizinhos (desconsiderando tabuleiros com apenas uma linha). A Figura 2 mostra três tabuleiros, onde a célula p reta está circundada por seus vizinhos, representados pelas células verdes. Na Figura 2, a célula preta tem, respectivamente, 3 , 5 e 8 vizinhos.

As regras para decidir como será a próxima geração são estas:
1. Qualquer célula viva com menos de dois vizinhos vivos morre de solidão;
2. Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação;
3. Qualquer célula morta com exatamente três vizinhos vivos se torna uma célula
viva;
4. Qualquer célula viva com dois ou três vizinhos vivos continua no mesmo estado
para a próxima geração.
A Figura 3 mostra uma mudança de geração . O tabuleiro da esquerda representa a geração anterior e o tabuleiro da direita representa a nova geração. Células brancas são células mortas enquanto células coloridas são células vivas. As cores indicam cada regra
aplicada na mudança de geração: <br>
● A célula preta morreu devido à regra 1 <br>
● As células verdes morreram devido à regra 2 <br>
● As células rosas se tornaram vivas devido à regra 3 <br>
● A célula vermelha continuou viva devido à regra 4, pois tinha 2 vizinhos <br>
● A célula azul continuou viva devido à regra 4, pois tinha 3 vizinhos <br>

<h2><b> O Que Deve Ser Feito </h2></b>
Neste trabalho prático, vamos programar o J ogo da Vida, de acordo com as regras apresentadas anteriormente. Serão usados os conhecimentos adquirido nas aulas teóricas e práticas, tais como: <br>
● variáveis e funções;
● condicionais; 
● repetições;
● arquivos;
● vetores e matrizes;
● Alocação dinâmica. <br>

Como boa prática de programação, tente sempre quebrar um problema em problemas menores e resolvêlos
com a criação de funções e procedimentos. Por exemplo, crie um método que recebe a localização de uma célula (linha e coluna) e
retorna o seu número de vizinhos vivos.
DICA: até que uma nova geração esteja totalmente calculada, é necessário manter a geração anterior intacta. Não se pode mudar um estado de uma célula antes que o novo estado de cada um de seus vizinhos esteja calculado. Ou seja, pode ser necessário manter duas matrizes: uma para a geração atual e uma para a nova geração.

1. Para simular o Jogo da Vida , você deverá:
(i) ler de um arquivo a geração inicial,
(ii) imprimir na tela a geração inicial,
(iii) aguardar que o usuário digite “s“ ou “n“. Se o usuário digitar “s“,
(iv) imprimir a próxima geração. Se o usuário digitar “n“,
(v) salvar a última geração em um arquivo, que possa ser aberto futuramente pelo programa, para continuar a execução.
A primeira linha do arquivo de entrada contém o número de linhas n e o número de colunas m , ambos são números inteiros entre 0 e 1 00. Após a primeira linha, o arquivo de entrada contém exatamente n linhas. Cada linha contém m números 0 ou 1, representando respectivamente uma célula viva (1) ou morta (0). Esses zeros e uns estão separados por espaço. A Figura 4 é um exemplo de arquivo de entrada, onde n = 7 e m =6. As células estão representado a geração inicial da Figura 3.

Ao imprimir uma geração na tela, as células mortas devem ser impressas como “” (espaço em branco) e as células vivas como um * (asterisco). Além disso, u m quadro delimitando o tabuleiro também deve ser impresso. A Figura 5 mostra como a geração da Figura 4 seria impressa na tela.
