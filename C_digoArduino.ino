const int led = 13;
const int led1 = 12;
// varible para recibir la instruccion de encender o apagar
int valor_dato = 0;
// variable para la lectura de la señal analoga del sensor
int lectura = 0;
float temperatura = 0.0;


void setup()
{
  pinMode (A0, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  // Se agregaron salidas para led de colores
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  digitalWrite (led, LOW);
  digitalWrite (led1, LOW);
  
  // iniciamos la comunicacion serial
  Serial.begin(9600);
  Serial.println("Conexión Establecida");
}

void loop(){
  lectura = analogRead (A0);
  
  while(Serial.available())
  {
    valor_dato = Serial.read();
  }
  
  if (valor_dato == '1')
  {
    digitalWrite (led, HIGH);
    digitalWrite (led1, HIGH);
  }
  else if (valor_dato == '0')
  {
    digitalWrite (led, LOW);
    digitalWrite (led1, LOW);
  }

  // se toma la lectura del pin al cual conectamos nuestro sensor
  temperatura = (lectura * (500.0/1023.0));
  // imprimimos por monitor serie la temperatura en °C
  Serial.println(temperatura);

  if (temperatura >80){
    digitalWrite (6, LOW);
    digitalWrite (7, HIGH);
  }
  else{
    digitalWrite (6, HIGH);
    digitalWrite (7, LOW);
  }

  delay (500);
}
