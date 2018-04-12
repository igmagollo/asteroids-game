# asteroids-game
Aplicação de listas em um game de Ateroides.

### Objetivo
Este repositório tem como objetivo principal aplicar a estrutura de dados lista. Uma das formas de aplicar (e provavelmente a mais divertida), é utilizar na implementação de um jogo.

### Asteroids game
Foi escolhido um jogo de asteroides por ser simples e ter margem para aplicar listas em mais de uma função (e se você for criativo, bota função nisso!).

Desta forma, escolhi três funções para utilizar a estrutura de dados lista, sendo duas delas óbvias e uma mais alternativa, como segue:
* Uma lista dinâmica para adicionar e remover projéteis atirados pela nave.
* Uma lista dinâmica para criação e remoção de asteroides.
* Uma lista estática para controlar a movimentação (uma espécia de física) da nave (uma forma alternativa para a utilização de lista).

### Bibliotecas utilizadas
Neste projeto foi utilizada a biblioteca gráfica SFML 2.4.2.

### Instalação
O repositório conta com a biblioteca SFML e um makefile, sendo necessário apenas ter as dependências da biblioteca. Atualmente o jogo tem apenas uma versão para linux.
Para instalar basta digitar.
    
    make install
    
em seguida, o jogo se abrirá para você!
Caso queira executar novamente, basta digitar

    ./asteroids
    
na pasta que você o instalou.