#include <ESP8266WiFi.h> //Importa lib de wifi server
#include <ESP8266WebServer.h> //Importa lib de WebServer para requisicoes get/post
#include <string.h> //lib de string


#define RED 5 // pino PWM 5 para a cor vermelha
#define GREEN 2 // pino PWM 9 para a cor verde
#define BLUE 4 // pino PWM 6 para a cor azul


int r = 0, g = 0, b = 0;
int controle = 0;

// Rede wifi
const char* ssid = "BRIGIDE 2G"; //Nome da rede
const char* password = "brigide123"; //Senha da rede

ESP8266WebServer server(80); // instancia o server na porta 80

void setup() {
  Serial.begin(115200); //taxa de comunicacao de bits
  delay(1000);

  Serial.print("Conectando..."); 
  Serial.println(ssid);
  WiFi.begin(ssid, password); // Funcao para conectar na rede

  while(WiFi.status() != WL_CONNECTED){ //Verifica status da conexao
    delay(500);
    Serial.print(".");  
  }
  Serial.println("");
  Serial.println("WiFi conectado!");

  //Config do servidor
  server.on("/", Home);  // Renderiza Home
  server.on("/turnOff", turnOff);  // Desliga todos os LEDs
  server.on("/turnRed", turnRed);  // Acende todos os LEDs como vermelho
  server.on("/turnBlue", turnBlue); // Acende todos os LEDs como azul
  server.on("/turnGreen", turnGreen); // Acende todos os LEDs como verde
  server.on("/turnYellow", turnYellow); // Acende todos os LEDs como amarelo
  server.on("/turnPurple", turnPurple); // Acende todos os LEDs como roxo
  server.on("/turnCyan", turnCyan); // Acende todos os LEDs como ciano
  server.on("/rainbowEffect", rainbowEffect); // Cria efeito de arco-iris nos LEDs
  server.begin(); //inicializa servidor
  Serial.println("Servidor inicializado!");

  //Exibir IP do server
  Serial.print("Utilize o IP: ");
  Serial.println(WiFi.localIP()); // exibe local ip

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  delay(1);
  analogWrite(RED, 0);
  delay(1);
  analogWrite(GREEN, 0);
  delay(1);
  analogWrite(BLUE, 0);
  
  
}

void loop() {
  Home(); //Chama a home
  server.handleClient(); // Funcao para constantemente escutar requisicoes
}





///////////////////////////////////////////////////////////////
//////////////////////// ROUTES ///////////////////////////////
///////////////////////////////////////////////////////////////

//Apagar:             /turnOff       GET    turnOff        Desliga todos os LEDs

//Apenas vermelho:    /turnRed       GET    turnRed        Acende todos os LEDs como vermelho

//Apenas azul:        /turnBlue      POST    turnBlue       Acende todos os LEDs como azul

//Apenas verde:       /turnGreen     POST    turnGreen      Acende todos os LEDs como verde

//Apenas amarelo:     /turnYellow    POST    turnYellow     Acende todos os LEDs como amarelo

//Apenas roxo:        /turnPurple    POST    turnPurple     Acende todos os LEDs como roxo

//Apenas ciano:       /turnCyan      POST    turnCyan       Acende todos os LEDs como ciano

//RainbowEffect:      /rainbowEffect POST    rainbowEffect  Cria efeito de arco-iris nos LEDs


void turnOff(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r > 0 || g > 0 || b > 0){
    if(r > 0){
      r--;
    }
    if(g > 0){
      g--;
    }
    if(b > 0){
      b--;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnRed(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);
  
  while(r < 1023 || g > 0 || b > 0){
    
    if(r < 1023){
      r++;
    }
    if(g > 0){
      g--;
    }
    if(b > 0){
      b--;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnBlue(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r > 0 || g > 0 || b < 1023){
    if(r > 0){
      r--;
    }
    if(g > 0){
      g--;
    }
    if(b < 1023){
      b++;
    }
    
    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnGreen(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r > 0 || g < 1023 || b > 0){
 
    if(r > 0){
      r--;
    }
    if(g < 1023){
      g++;
    }
    if(b > 0){
      b--;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnYellow(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r < 1023 || g < 1023 || b > 0){
  
    if(r < 1023){
      r++;
    }
    if(g < 1023){
      g++;
    }
    if(b > 0){
      b--;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnPurple(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r < 1023 || g > 0 || b < 1023){
  
    if(r < 1023){
      r++;
    }
    if(g > 0){
      g--;
    }
    if(b < 1023 ){
      b++;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void turnCyan(){
  controle = 0;
  r = analogRead(RED);
  g = analogRead(GREEN); 
  b = analogRead(BLUE);

  while(r > 0 || g < 1023 || b < 1023){
  
    if(r > 0){
      r--;
    }
    if(g < 1023){
      g++;
    }
    if(b < 1023){
      b++;
    }

    delay(1);
    analogWrite(RED, r);
    delay(1);
    analogWrite(GREEN, g);
    delay(1);
    analogWrite(BLUE, b);
  }
  server.send(200, "text/plain", "OK");
}

void rainbowEffect(){
  turnBlue(); // Comeca o efeito do azul
  while(true){

    // Fade do azul até o violeta, adicionando o vermelho
    for(r = 0; r <= 1023; r++){
      analogWrite(RED, r);
      delay(1);
    }
  
    // Fade do violeta até o vermelho, removendo o azul
    for(b = 1023; b >= 0; b--){
      analogWrite(BLUE, b);
      delay(1);
    }
  
    // Fade do vermelho até o amarelo, adicionando o verde
    for(g = 0; g <= 1023; g++){
      analogWrite(GREEN, g);
      delay(1);
    }
  
    // Fade do amarelo até o verde, removendo o vermelho
    for(r = 1023; r >= 0; r--){
      analogWrite(RED, r);
      delay(1);
    }
  
    // Fade do verde até o turquesa, adicionando o azul
    for(b = 0; b <= 1023; b++){
      analogWrite(BLUE, b);
      delay(1);
    }
  
    // Fade do turquesa até o azul, removendo o verde
    for(g = 1023; g >= 0; g--){
      analogWrite(GREEN, g);
      delay(1);
    }
    server.send(200, "text/plain", "OK");
  }
}


void Home(){ 
  server.send(200, "text/html", "<html><head><title>self.room</title><meta charset=\"UTF-8\" /></head><body style=\"font-family: Arial, Helvetica, sans-serif;\"><table align=\"center\"><tr><th><h4>self.room</h4></th></tr><tr><td align=\"center\"><form action=\"/turnRed\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">vermelho</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnGreen\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">verde</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnBlue\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">azul</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnYellow\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">amarelo</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnPurple\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">roxo</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnCyan\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">ciano</submit></form></td></tr><tr><td align=\"center\"><form action=\"/rainbowEffect\" method=\"GET\"><button type=\"submit\" style=\"background-color: blueviolet; color: white; border-radius: 3px; border: none; position: relative; padding: 10px;\">arco-iris</submit></form></td></tr><tr><td align=\"center\"><form action=\"/turnOff\" method=\"GET\"><button type=\"submit\" style=\"color: blueviolet; border-radius: 3px; border: 1px solid blueviolet; position: relative; padding: 10px;\">apagar</submit></form></td></tr></table></body></html>");
}
