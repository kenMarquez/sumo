unsigned long distancia;
unsigned long duracion;
#define INFR1 4
#define INFR2 5
#define INFR3 6
#define MTA1 14
#define MTA2 13
#define MTB1 12
#define MTB2 11
#define TRI 15
#define ECH 9

void setup()
{
  pinMode(INFR1,INPUT);
  pinMode(INFR2,INPUT);
  pinMode(INFR3,INPUT);

  pinMode(MTA1,OUTPUT);
  pinMode(MTA2,OUTPUT);
  pinMode(MTB1,OUTPUT);
  pinMode(MTB2,OUTPUT);
  pinMode(TRI,OUTPUT);
  pinMode(ECH,INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(TRI,LOW);          /*Se calcula la distancia a la que ve algo el ultrasonico*/
  delayMicroseconds(5);          //
  digitalWrite(TRI,HIGH);         //
  delayMicroseconds(10);         //
  duracion = pulseIn(ECH,HIGH);   //
  distancia = duracion/58;       /*Distancia calculada  e*/

  int lecturaInfra1 = analogRead(INFR1);
  int lecturaInfra2 = analogRead(INFR2);
  int lecturaInfra3 = analogRead(INFR3);

  if((lecturaInfra1 > 300) || (lecturaInfra2 > 300) ||(lecturaInfra3 > 300)){
    digitalWrite(MTA1,LOW);
    digitalWrite(MTA2,HIGH);    //El motor 1 gira hacia cierto lado.
    digitalWrite(MTB1,LOW);
    digitalWrite(MTB2,HIGH);
  }
  else{
    digitalWrite(MTA2,LOW);
    digitalWrite(MTA1,HIGH);    //El motor 1 gira hacia cierto lado.
    digitalWrite(MTB1,HIGH);
    digitalWrite(MTB2,LOW);
  }
/*  if(distancia<10){
    digitalWrite(MTA1,LOW);
    digitalWrite(MTA2,HIGH);    //El motor 1 gira hacia cierto lado.
    digitalWrite(MTB1,LOW);
    digitalWrite(MTB2,HIGH);
  }
  else{
    digitalWrite(MTA2,LOW);
    digitalWrite(MTA1,HIGH);    //El motor 1 gira hacia cierto lado.
    digitalWrite(MTB1,HIGH);
    digitalWrite(MTB2,LOW);
  }*/
  delay(1000);
}
