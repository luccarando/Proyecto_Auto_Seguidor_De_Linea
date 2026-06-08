//int slderecho = 18; //declaro el pin de entrada del sensor derecho
//int slizquierdo = 17; //declaro el pin de entrada del sensor izquierdo
//int Vslderecho = 0; //declaro valor inicial del sensor derecho
//int Vslizquierdo = 0; //declaro valor inicial del sensor izquierdo
int Dmotorderecho1 = 21; // declaro el pin para manejar giro de motor derecho
int Dmotorderecho2 = 19; // declaro el pin para manejar giro de motor derecho
int PWMmotorderecho = 13; // declaro el pin para manejar velocidad del motor derecho
int Dmotorizquierdo1 = 23; // declaro el pin para manejar giro de motor izquierdo
int Dmotorizquierdo2 = 22; // declaro el pin para manejar giro de motor izquierdo
int PWMmotorizquierdo = 32; // declaro el pin para manejar velocidad del motor izquierdo
int ADCderecho = 36; // declaro pin ADC para sensor derecho
int ADCizquierdo = 39; // declaro pin ADC para sensor izquierdo
int VADCderecho = 0; // declaro valor inicial de ADC derecho
int VADCizquierdo = 0; // delacro valor inicial de ADC izquierdo
int umbral = 800; // negro < 800 , blanco > 800
int Vfinalderecho = 1;
int Vfinalizquierdo = 1;
void setup()
{
Serial.begin(9600);
analogReadResolution(12); // Configuramos la resolución a 12 bits (rango de 0 a 4095)
analogSetAttenuation(ADC_11db); // Rango hasta ~3.3V
//pinMode (slderecho, INPUT); // declaro pin 14 como entrada
//pinMode (slizquierdo, INPUT); // declaro pin 27 como entrada
pinMode (Dmotorderecho1, OUTPUT);// declaro pin como salida
pinMode (Dmotorderecho2, OUTPUT);// declaro pin como salida
pinMode (PWMmotorderecho, OUTPUT);// declaro pin como salida
pinMode (Dmotorizquierdo1, OUTPUT);// declaro pin como salida
pinMode (Dmotorizquierdo2, OUTPUT);// declaro pin como salida
pinMode (PWMmotorizquierdo, OUTPUT);// declaro pin como salida
}
void loop() {
//Vslderecho=digitalRead(slderecho); // leo el valor digital de pin 14
//Serial.print("El valor del sensor derecho es:"); // escribo el valor en consola
//Serial.println(Vslderecho);
//Vslizquierdo=digitalRead(slizquierdo); // leo el valor digital de pin 27
//Serial.print("El valor del sensor izquierdo es:"); // escribo el valor en consola
//Serial.println(Vslizquierdo);
VADCderecho = analogRead(ADCderecho); // Lectura del ADC del ESP32 (Resolución de 12
bits: 0 a 4095)
VADCizquierdo = analogRead(ADCizquierdo); // Lectura del ADC del ESP32 (Resolución de
12 bits: 0 a 4095)
// Determinar estado lógico (0 = Blanco, 1 = Negro)
// Si el valor supera el umbral, está sobre el fondo blanco.
if (VADCderecho > umbral)
{
Vfinalderecho = 1;
}
else
{
Vfinalderecho = 0;
}
if (VADCizquierdo > umbral)
{
Vfinalizquierdo = 1;
}
else
{
Vfinalizquierdo = 0;
}
if(Vfinalizquierdo == 1 && Vfinalizquierdo == 1 ) // si los dos sensores están sobre blanco SE
DETIENE
{
digitalWrite(Dmotorderecho1, LOW);
digitalWrite(Dmotorderecho2, LOW);
digitalWrite(Dmotorizquierdo1, LOW);
digitalWrite(Dmotorizquierdo2, LOW);
//analogWrite(PWMmotorderecho, 40); // velocidad del motor derecho con PWM
//analogWrite(PWMmotorizquierdo, 40); // velocidad del motor izquierdo con PWM
}
if (Vfinalizquierdo ==1 && Vfinalderecho ==0 ) // si izquierdo esta blanco y el derecho en
negro gira a la DERECHA
{
digitalWrite(Dmotorderecho1, HIGH);
digitalWrite(Dmotorderecho2, LOW);
digitalWrite(Dmotorizquierdo1, LOW);
digitalWrite(Dmotorizquierdo2, HIGH);
analogWrite(PWMmotorderecho, 110); // velocidad del motor derecho con PWM
analogWrite(PWMmotorizquierdo, 110); // velocidad del motor izquierdo con PWM
}
if (Vfinalizquierdo==0 && Vfinalderecho==1 ) // si izquierdo esta negro y el derecho en
blanco gira a la IZQUIERDA
{
digitalWrite(Dmotorderecho1, LOW);
digitalWrite(Dmotorderecho2, HIGH);
digitalWrite(Dmotorizquierdo1, HIGH);
digitalWrite(Dmotorizquierdo2, LOW);
analogWrite(PWMmotorderecho, 110); // velocidad del motor derecho con PWM
analogWrite(PWMmotorizquierdo, 110); // velocidad del motor izquierdo con PWM
}
if (Vfinalizquierdo==0 && Vfinalderecho==0 ) // si izquierdo esta NEGRO y el derecho en
NEGRO sigue recto
{
digitalWrite(Dmotorderecho1, LOW);
digitalWrite(Dmotorderecho2, HIGH);
digitalWrite(Dmotorizquierdo1, LOW);
digitalWrite(Dmotorizquierdo2, HIGH);
analogWrite(PWMmotorderecho, 80); // velocidad del motor derecho con PWM
analogWrite(PWMmotorizquierdo, 80); // velocidad del motor izquierdo con PWM
}}
