#include <Arduino.h>

#include <Keyboard.h>

const byte ROWS = 3;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
};
byte rowPins[ROWS] = {2, 3, 4};
byte colPins[COLS] = {5, 6, 7};

//Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int numButtons = 9;

const int potentiometerPins[] = {A0, A1, A2};  // Pinos analógicos para os potenciômetros
const int numPotentiometers = 3;

const int minBrightness = 0;
const int maxBrightness = 100;

const int minPotValue = 0;
const int maxPotValue = 1023;
const int minVolume = 0;
const int maxVolume = 100;

int currentVolume = 0;

const int fnKey = KEY_LEFT_SHIFT; // define a tecla fn correspondente do seu teclado.

const int threshold = 100; // valor do potenciômetro para avançar e desavançar a cena

void setup() {
  for (int i = 0; i < numPotentiometers; i++) {
    pinMode(potentiometerPins[i], INPUT); // Configura os pinos dos potenciômetros como entrada
  }

  Keyboard.begin();
}

void loop() {
  // Verifica o estado dos botões do teclado matricial
  //char key = keypad.getKey();
  if (/*key*/) {
    // Botão pressionado, chame a função correspondente
    handleButtonPress(/*key*/);
    delay(100); // Pequeno atraso para evitar pressionamentos múltiplos
  }

  int potentiometerValue = analogRead(potentiometerPins[0]); // lê o valor do potenciômetro
  int brightness = map(potentiometerValue, 0, 1023, minBrightness, maxBrightness); // Mapeia o valor lido para o intervalo necessário
  setBrightness(brightness); // Brilho do pc usando a emulação

  delay(100); // Intervalo para atualizar novamente

  int potValue = analogRead(potentiometerPins[1]);
  int volume = map(potValue, minPotValue, maxPotValue, minVolume, maxVolume);
  setVolume(volume);

  delay(100);

  int mappedValue = map(potValue, minPotValue, maxPotValue, -threshold, threshold);

  if (mappedValue > threshold) {
    // Avançar cena no Photoshop
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(50);
    Keyboard.releaseAll();
  } else if (mappedValue < -threshold) {
    // Voltar cena no Photoshop
    Keyboard.press(KEY_LEFT_ARROW);
    delay(50);
    Keyboard.releaseAll();
  }

  delay(100);
}

void handleButtonPress(char buttonIndex) {
  // Função para lidar com o pressionamento de um botão
  // Implemente aqui as ações correspondentes a cada botão, como abrir aplicativos, realizar ações no Windows, etc.
  // Use uma estrutura condicional (if/else if) para determinar qual botão foi pressionado
  // e execute a ação correspondente

  if (buttonIndex == '1') {
    openWindowsExplorer();
  } else if (buttonIndex == '2') {
    openWebBrowser();
  } else if (buttonIndex == '3') {
    openTaskWin();
  } else if (buttonIndex == '4') {
    openDiscord();
  } else if (buttonIndex == '5') {
    openSpotify();
  } else if (buttonIndex == '6') {
    openCalculadora();
  } else if (buttonIndex == '7') {
    openObs();
  } else if (buttonIndex == '8') {
    openVsCode();
  } else if (buttonIndex == '9') {
    openRiot();
  }
}

// para definir os códigos para cada botão

void openWindowsExplorer() {
  // Código para abrir o Explorador de Arquivos do Windows
  // Implementar a ação correspondente aqui
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('e');
  Keyboard.releaseAll();
}

void openWebBrowser() {
  // Código para abrir o navegador de Internet (por exemplo, Edge)
  Keyboard.press(KEY_LEFT_GUI); // precionar a tecla windows
  Keyboard.press('s'); // precionar a tecla S
  Keyboard.releaseAll(); // soltar todos os botões

  delay(1000); // tempo de espera para a aparição da caixa de execução
  Keyboard.println("OperaGX");
  delay(600);
  Keyboard.press(KEY_RETURN); // aperta o botão dar enter
  Keyboard.releaseAll();
}

void openTaskWin() {
  // Código para abrir o Gerenciador de Tarefas do Windows
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
}

void openDiscord() {
  // Código para abrir o Discord
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("Discord");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openSpotify() {
  // Código para abrir o aplicativo Spotify
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("Spotify");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openCalculadora() {
  // Código para abrir a calculadora
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("Calculadora");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openObs() {
  // para abrir o OBS
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("obs");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openVsCode(){
  // para abrir o VsCode
  // para abrir o OBS
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("Visual Studio Code");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openRiot(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.println("Cliente Riot");
  delay(600);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

// PARTE DOS POTENCIÔMETROS. 

void setBrightness(int brightness) {
  Keyboard.press(fnKey); // Pressiona a tecla Fn
  Keyboard.press(KEY_F1); // Pressiona a tecla de ajuste de brilho
  delay(50);
  Keyboard.releaseAll();

  // Emular ações adicionais para ajustar o brilho, se necessário

  Keyboard.press(fnKey); // Solta a tecla Fn
  Keyboard.releaseAll();
}

void setVolume(int volume) {
  Keyboard.press(fnKey); // Pressiona a tecla Fn

  // Pressiona a tecla de ajuste de volume para cima ou para baixo, dependendo do valor do volume
  if (volume > currentVolume) {
    for (int i = 0; i < volume - currentVolume; i++) {
      Keyboard.press(KEY_F3); // Tecla de aumento de volume
      delay(50);
      Keyboard.releaseAll();
      delay(50);
    }
  } else if (volume < currentVolume) {
    for (int i = 0; i < currentVolume - volume; i++) {
      Keyboard.press(KEY_F2); // Tecla de diminuição de volume
      delay(50);
      Keyboard.releaseAll();
      delay(50);
    }
  }

  currentVolume = volume;

  Keyboard.release(fnKey); // Solta a tecla Fn
}
