#include <Servo.h>

Servo myservo;


void forward(void);
void backward(void);
void hardleft(void);
void hardright(void);
void left(void);
void right(void);
void backleft(void);
void backright(void);
void do_nothing(void);

char data=0;

int flag=0;
int x=255;
int angle=0;

int motorleft_forward = 8;
int motorleft_backward = 9;
int motorright_forward = 13;
int motorright_backward = 12;
int weapon = 4;

int pwmleft = 10;
int pwmright = 11;

void setup() 
{
Serial.begin(9600);
  
pinMode(motorleft_forward,OUTPUT);
pinMode(motorleft_backward,OUTPUT);
pinMode(motorright_forward,OUTPUT);
pinMode(motorright_backward,OUTPUT);
pinMode(weapon,OUTPUT);

myservo.attach(3);
}

void loop() 
{
if (Serial.available()>0)
{
    data = Serial.read();
    switch(data)
      {
        case 'F':
        forward();
        break;
        case 'B':
        backward();
        break;
        case 'L':
        hardleft();
        break;
        case 'R':
        hardright();
        break;
        case 'G':
        left();
        break;
        case 'I':
        right();
        break;
        case 'H':
        backright();
        break;
        case 'J':
        backleft();
        break;
        case '0':
        x=80;
        break;
        case '1':
        x=90;
        break;
         case '2':
        x=100;
        break;
         case '3':
        x=120;
        break;
         case '4':
        x=160;
        break;
         case '5':
        x=180;
        break;
         case '6':
        x=200;
        break;
         case '7':
        x=220;
        break;
         case '8':
        x=240;
        break;
         case '9':
        x=255;
        break;
         case 'q':
        x=255;
        break;
        case 'W':
        angle=70;
        break;
        case 'w':
        angle=0;
        break;
        case 'U':
        flag=1;
        break;
        case 'u':
        flag=0; 
        break;
        case 'S':
        do_nothing();
        break;
      }

      if(flag)
      {
      digitalWrite(weapon, HIGH);
      }
      else
      {
      digitalWrite(weapon, LOW);  
      }
myservo.write(angle); 
}

}

void forward()
{
  analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,HIGH); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,HIGH);
  digitalWrite(motorright_backward,LOW);
  }
  void backward()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,HIGH);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,HIGH);
    }
      void hardleft()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,HIGH);
  digitalWrite(motorright_forward,HIGH);
  digitalWrite(motorright_backward,LOW);
    }
       void hardright()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,HIGH); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,HIGH);
    }
     void left()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,HIGH);
  digitalWrite(motorright_backward,LOW);
    }
    void right()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,HIGH); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,LOW);
    }
    void do_nothing()
      {
    analogWrite(pwmleft,255);
  analogWrite(pwmright,255);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,LOW);
    }



    void backleft()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,LOW);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,HIGH);
    }
    void backright()
  {
    analogWrite(pwmleft,x);
  analogWrite(pwmright,x);
  digitalWrite(motorleft_forward,LOW); 
  digitalWrite(motorleft_backward,HIGH);
  digitalWrite(motorright_forward,LOW);
  digitalWrite(motorright_backward,LOW);
    }
