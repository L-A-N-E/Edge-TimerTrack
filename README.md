# TimerTrack 🏎

![banner](https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/153787379/132308ff-27a0-45e7-8323-80d9103f2390)

## Índice 📃

* [Descrição do Projeto](#descrição-do-projeto-memo)
   * [Introdução](#introdução-1st_place_medal)
   * [TimeTracker](#timetracker-2nd_place_medal)
   * [Futuro do Projeto](#futuro-do-projeto-3rd_place_medal)
* [Acesso ao projeto](#acesso-ao-projeto-file_folder)
* [Ferramentas utilizadas](#ferramentas-utilizadas-hammer_and_wrench)
* [Bibliotecas utilizadas](#bibliotecas-utilizadas-books)
* [Componentes necessários](#componentes-necessários-toolbox)
* [Montagem](#montagem-wrench)
   * [Cuidados durante a montagem](#cuidados-durante-a-montagem-warning)
* [Reprodução](#reprodução-gear)
* [Pessoas Desenvolvedoras do Projeto](#pessoas-desenvolvedoras-do-projeto-globe_with_meridians)

## Descrição do projeto :memo:

<h3>Introdução :1st_place_medal:</h3>
<p>
O projeto TRACER é uma iniciativa inovadora que visa criar uma comunidade ativa e amigável em torno da Fórmula E. Este projeto é composto por um site abrangente, que oferece informações detalhadas sobre todos os aspectos da Fórmula E, e um aplicativo interativo que está totalmente integrado ao site. Uma das principais funcionalidades deste aplicativo é a tabela de ranking, também conhecida como tabela de pontuação, que será alimentada pelos dados coletados através do nosso protótipo, o TimeTracker. A tabela de ranking será atualizada em tempo real, garantindo a competitividade e o engajamento contínuo da comunidade de fãs da Fórmula E. Nosso objetivo é proporcionar uma experiência rica e dinâmica, permitindo que os usuários acompanhem o desempenho de seus pilotos favoritos e participem de competições amistosas dentro do aplicativo.
</p>

<h3>TimeTracker :2nd_place_medal:</h3>
<p>
O TimeTracker é um componente crucial do projeto TRACER, atuando como um protótipo para futuras melhorias e expansões. Este dispositivo é projetado para registrar e calcular o tempo de percurso de um carro entre dois pontos. Utilizando um RTC (Relógio em Tempo Real) e botões de entrada, o TimeTracker mede com precisão o tempo decorrido entre as pressões dos botões, que representam o carro passando por dois pontos de controle.

Ao pressionar o primeiro botão, o tempo é registrado, e o LED azul acende brevemente para indicar a passagem do carro. Quando o segundo botão é pressionado, o tempo decorrido é calculado e mostrado em um display LCD, juntamente com a iluminação do LED amarelo para sinalizar a conclusão do percurso. Este tempo também é armazenado na EEPROM para análises futuras e pode ser exibido no monitor serial para monitoramento em tempo real. Além disso, o TimeTracker inclui uma animação visual de um carro no display LCD, criando uma experiência interativa para os usuários.
</p>

<h3>Futuro do Projeto :3rd_place_medal:</h3>
<p>
 No futuro do desenvolvimento do projeto TRacer, temos planejadas várias melhorias e expansões. Um dos principais objetivos é substituir o Arduino UNO pelo ESP32, o que permitirá uma maior conectividade e eficiência na coleta e transmissão de dados. Essa mudança será crucial para a evolução do TimeTracker e outras funcionalidades do sistema.
  
  Além disso, planejamos aprimorar o software em Python, garantindo uma integração mais robusta e eficiente com o aplicativo e o banco de dados. Com essa melhoria, os dados coletados em tempo real pelo TimeTracker serão processados e exibidos instantaneamente na tabela de ranking do aplicativo, mantendo a competividade e a precisão das informações.
  
  Outro passo importante será interligar a tabela de classificação com o aplicativo, permitindo que os usuários visualizem as informações em tempo real diretamente no app. Isso não só melhora a experiência do usuário, mas também facilita a tomada de decisões e a análise de desempenho. Com essas melhorias, o projeto TRacer estará ainda mais preparado para fornecer uma plataforma interativa e informativa, conectando a comunidade e incentivando a participação ativa na Fórmula E.
</p>

## Acesso ao projeto :file_folder:

Você pode acessar o [código do projeto](timer_track.cpp) ou a [simulação feita no Wooki](https://wokwi.com/projects/398423919785427969)

## Ferramentas utilizadas :hammer_and_wrench:

- `Arduino IDE`

## Bibliotecas utilizadas :books:

- ``LiquidCrystal_I2C``
- ``EEPROM``
- ``Wire``
- ``RTClib``

## Componentes necessários :toolbox:

|   Componente   | Quantidade |
|:--------------:|:----------:|
|      Cabos     |     20     |
|   Botão Azul   |     1      |
| Botão Amarelo  |     1      |
| Arduino - UNO  |     1      |
| LCD 16x2 com módulo I2C |     1      |
| Real Time Clock - RTC |     1     |
|    Led Azul    |     1     |
|  Led Amarelo   |     1     |
| Resistores de 220Ω |     2     |
|    Cabo USB    |     1     |

## Montagem :wrench:

<details>
  <summary>Imagem da Montagem</summary>
  <img src="https://github.com/L-A-N-E/Edge-TimerTrack/assets/163866552/934638a8-2f9f-4f49-be11-f24e9d5d6e1d" alt="imagem-montagem">
</details>

<h3>Cuidados durante a montagem :warning:</h3>

- ``1.`` Conectando os LED’s:
   - ``1.1.`` Conecte o led azul no pino 6, e o led amarelo no pino 5.
   - ``1.2.`` Ambos possuem polaridade, então precisamos ter cuidado na hora de conectar-los aos cabos;
   - ``1.3.`` O LED possui um terminal maior, que tem polaridade positiva, e o lado do terminal menor tem polaridade negativa. Portanto, conectamos a conexão do Arduino no terminal positivo (Ânodo) e o GND no terminal negativo (Catodo);

- ``2.`` Conectando o LCD:
  - ``2.1.`` **Atenção!** Estamos utilizando um LCD 16x2 com um módulo I2C!;
  - ``2.2.`` Conecte o VCC no terminal positivo (5V), GND no terminal negativo (GND), o SDA no pino do Arduino A4.2 e o SCL no A5.2;
  - ``2.3.`` Teste para ver se o display está funcionando, se tiver problemas com o display, pode ser algumas dessas possibilidades: o LCD está quebrado, com mal contato ou o contraste está baixo;
    - ``2.3.1.`` Para aumentar o contraste do display basta girar o trimpot de ajuste do contraste no sentido anti-horário. Por sua vez, para diminuir o contraste gire no sentido horário.
      
      <details>
        <summary>Imagem de onde fica o trimpot de ajuste do contraste</summary>
        <img src="https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/101829188/50648d65-2402-4508-a47d-1d38bbf663e5" alt="Terminais do DHT11">
      </details>

- ``3.`` Conectando os Botões:
  - ``3.1`` Conecte um fio no botão azul e conecte no pino 4, e outro fio no botão azul conecte no terminal negativo. Já no botão amarelo, conecte um fio nele e no pino 3, e outro fio nele e no terminal negativo.
  - ``3.2.`` Certifique-se de que a polaridade dos botões esteja correta ao conectá-los. A conexão incorreta pode danificar os botões ou o circuito.
  - ``3.3.`` Verifique se todos os botões estão firmemente conectados e se não há folga nos cabos.
  - ``3.4.`` Sempre teste os botões antes de usar o circuito em uma aplicação real. Isso pode ajudar a identificar e corrigir problemas antecipadamente.
    
- ``4.`` Conectando o RTC:
  - ``4.1.`` Conecte o SCL no A5 do arduino, o SCA no A4 do arduino, o 5V no terminal positivo do breadboard e o GND no terminal negativo do breadboard.
  - ``4.2.`` O RTC é um componente delicado. Manipule com cuidado para evitar danos.
  - ``4.3.`` Certifique-se de que o RTC esteja configurado com a hora correta. Uma configuração incorreta pode levar a erros no funcionamento do seu projeto.
  - ``4.4.`` Verifique se o RTC está recebendo a alimentação adequada. Uma alimentação insuficiente ou excessiva pode danificar o RTC ou afetar seu funcionamento.
 
## Reprodução :gear:

- ``1.`` Após a montagem do projeto, é necessário inserir o código por meio de um computador que possui o programa Arduino IDE instalado;
- ``2.`` Baixe as [bibliotecas necessárias](#bibliotecas-utilizadas-books) no Arduino IDE; 
- ``3.`` Transferir o código do computador para  o Arduino por meio do Cabo USB;
- ``4.`` Testar para ver se está funcionando;
- ``5.`` Com tudo montado e pronto, é necessário levá-lo para o ambiente em que será implementado e ligá-lo á uma fonte;

## Pessoas Desenvolvedoras do Projeto :globe_with_meridians:

| [<img src="https://avatars.githubusercontent.com/u/101829188?v=4" width=115><br><sub>Alice Santos Bulhões</sub>](https://github.com/AliceSBulhoes) |  [<img src="https://avatars.githubusercontent.com/u/163866552?v=4" width=115><br><sub>Eduardo Oliveira Cardoso Madid</sub>](https://github.com/EduardoMadid) |  [<img src="https://media.licdn.com/dms/image/D5603AQF59776BVSUSg/profile-displayphoto-shrink_800_800/0/1697337839569?e=1717632000&v=beta&t=4spOdaBAcH7gOmyEpgpyF6hk1TM14MvCJ5DI-CNdCsI" width=115><br><sub>Lucas Henzo Ide Yuki</sub>](https://github.com/LucasYuki1) | [<img src="https://avatars.githubusercontent.com/u/153787379?v=4" width=115><br><sub>Nicolas Haubricht Hainfellner</sub>](https://github.com/NicolasHaubricht) |
| :---: | :---: | :---: | :---: |
| RM:554499 | RM:556349 | RM:554865 | RM:556259 |

