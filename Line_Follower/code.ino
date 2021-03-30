// IR
const int l_ir=11;
const int c_ir=12;
const int r_ir=13; 

//L293D
//Motor A
const int eA = 3;
const int in1 = 9;
const int in2 = 10; 

//Motor B
const int eB = 2;
const int in3 = 7; 
const int in4 = 8; 

void setup()
{
  pinMode(l_ir,INPUT);
  pinMode(r_ir,INPUT);
  pinMode(c_ir,INPUT);
  
  pinMode(eA,OUTPUT);
  pinMode(eB,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  Serial.begin(9600);
  Serial.println("hello world");
}

void loop()
{
  delay(10);
  int al = digitalRead(l_ir);
  int ar = digitalRead(r_ir);
  int ac = digitalRead(c_ir);

  analogWrite(eA, 255);
  analogWrite(eB, 255);
  
  Serial.println(al);
  Serial.println(ac);
  Serial.println(ar);
  Serial.println("----------------");
// Left
  if (al==1 && ar==0)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
  
// Right
  if (al==0 && ar==1)
  {
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }
//When it meets a end line
  if(al==0 && ac==0 && ar==0)
  {
    digitalWrite(in1,LOW);      
    digitalWrite(in2,LOW);    
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
 
//When it meets a t-junction 
  if(al==1 && ac==1 && ar==1)
  {
    //Left and right tyres move in clockwise and anticlockwise direction
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    //turns left
    digitalWrite(in1,HIGH);      
    digitalWrite(in2,LOW); 
  }

//Forward
  if(al==0 && ac==1 && ar==0)
  {
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);  
  }  
}
