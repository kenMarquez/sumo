unsigned long distancia;
unsigned long duracion;
#define INFR1 4
#define INFR2 5
#define INFR3 8
#define MTA1 14 
#define MTA2 13
#define MTB1 12
#define MTB2 11
#define TRI 6
#define ECH 7

void setup()
{
  // put your setup code here, to run once:
  pinMode(INFR1,INPUT); 
  pinMode(INFR2,INPUT); 
  pinMode(INFR3,INPUT);
  pinMode(MTA1,OUTPUT); 
  pinMode(MTA2,OUTPUT); 
  pinMode(MTB1,OUTPUT); 
  pinMode(MTB2,OUTPUT); 
  pinMode(TRI,OUTPUT); 
  pinMode(ECH,INPUT); 
  
  Serial.begin(9600);

}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(TRI,LOW);          /*Se calcula la distancia a la que ve algo el ultrasonico*/
  delayMicroseconds(5);          //
  digitalWrite(TRI,HIGH);         //
  delayMicroseconds(10);         //
  duracion = pulseIn(ECH,HIGH);   //
  distancia = duracion/58;       /*Distancia calculada*/
  
  int lI1 = analogRead(INFR1);    
  int lI2 = analogRead(INFR2); 
  int lI3 = analogRead(INFR3);    
  
  Serial.print("Lectura INFR1: ");
  Serial.println(lI1);
  
  Serial.print("Lectura INFR2: ");
  Serial.println(lI2);
  
  Serial.print("Lectura INFR3: ");
  Serial.println(lI3);
  
  delay(3000);
  
  if (lt1 < 100){

    digitalWrite(MTA1,HIGH);       
  }else{
    digitalWrite(MTA2,HIGH);       
    digitalWrite(MTA1,HIGH);    
    
  }
  
    delay(500);


}


void testMotors(){

  Serial.print(distancia);
  Serial.println(" cm");
  
  if(distancia<5){
    digitalWrite(MTA1,LOW);
    digitalWrite(MTA2,HIGH);    //El motor 1 gira hacia cierto lado.
  }else{
    digitalWrite(MTA2,LOW);
    digitalWrite(MTA1,HIGH);    //El motor 1 gira hacia cierto lado.
  }
  if((lI1 > 300) || (lI2 > 300) || (lI3 > 300)){
      digitalWrite(MTB1,LOW);    //El motor 2 gira hacia cierto lado.
      digitalWrite(MTB2,HIGH);
  }else{
    digitalWrite(MTB2,LOW);    //El motor 2 gira hacia cierto lado.
    digitalWrite(MTB1,LOW);
  }
  delay(1000);
  
}
