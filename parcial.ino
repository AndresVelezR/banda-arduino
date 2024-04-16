

#define derecha 22
#define izquierda 23
#define s1 30
#define s2 31
#define s3 32
#define s4 33
#define sw37 37
#define sw36 36
#define sw35 35
#define sw34 34
int veces = 0;
int veces2 = 0;
bool flag = false;
int izq = 0, der = 0;
unsigned long i_tiempo = millis();
unsigned long f_tiempo = millis();
unsigned long total_tiempo = millis();



void pausa(){

    digitalWrite(izquierda, 0);
    digitalWrite(derecha, 0);
  
  
}
void setup() {
  Serial.begin(9600);
  pinMode(derecha, OUTPUT);
  pinMode(izquierda, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(sw37, INPUT);
  pinMode(sw36, INPUT);
  pinMode(sw35, INPUT);
  pinMode(sw34, INPUT);

  


  // put your setup code here, to run once:

}

void loop() {
  int start = digitalRead(sw37); 

  if(start == 1){
    int rsw35 = digitalRead(sw35);
    int rsw34 = digitalRead(sw34);
    

   
    if(rsw35 == 0 && rsw34 == 0){
       
      while(true){

        while((digitalRead(s3) == 0) && (digitalRead(sw36) == 0) && (flag == false)){
      
          digitalWrite(izquierda, 1);
        }
        if(digitalRead(s3)){
        digitalWrite(izquierda, 0);
        flag = true;
        } else {
          digitalWrite(izquierda, 0);
        }
        while(digitalRead(s1) == 0 && (digitalRead(sw36) == 0) && (flag == true)){
        
          digitalWrite(derecha, 1);
        }
        if(digitalRead(s1)){
        digitalWrite(derecha, 0);
        veces = veces + 1;
        flag = false;
        } else {
          digitalWrite(derecha, 0);
        }
      }
    }
    if(rsw35 == 0 && rsw34 == 1){
      while(veces < 3){
        while((digitalRead(s3) == 0) && (digitalRead(sw36) == 0) && (flag == false)){
          digitalWrite(izquierda, 1);
        }
        if(digitalRead(s3)){
        digitalWrite(izquierda, 0);
        flag = true;
        } else {
          digitalWrite(izquierda, 0);
        }
        while(digitalRead(s2) == 0 && (digitalRead(sw36) == 0) && (flag == true)){
        
          digitalWrite(derecha, 1);
        }
        if(digitalRead(s2)){
        digitalWrite(derecha, 0);
        veces = veces + 1;
        flag = false;
        } else {
          digitalWrite(derecha, 0);
        }
    }
    } 
    if(rsw35 == 1 && rsw34 == 0){
      bool flag1, flag3, flag4 = false;
      i_tiempo = millis();
      while(veces2 < 1){
        if(digitalRead(s4) == 1){
          while(digitalRead(s2) == 0){
            digitalWrite(derecha, 1);
          }
          digitalWrite(derecha, 0);
          if(digitalRead(s2) == 1){
            while(digitalRead(s4) == 0){
              digitalWrite(izquierda, 1);
            }
            digitalWrite(izquierda, 0);
          }
          f_tiempo = millis();
          total_tiempo = f_tiempo - i_tiempo;
          Serial.println(total_tiempo);

        }
        if(digitalRead(s3) == 1){
          while(digitalRead(s2) == 0){
            digitalWrite(derecha, 1);
          }
          digitalWrite(derecha, 0);
          if(digitalRead(s2) == 1){
            while(digitalRead(s3) == 0){
              digitalWrite(izquierda, 1);
            }
            digitalWrite(izquierda, 0);
          }
          f_tiempo = millis();
          total_tiempo = f_tiempo - i_tiempo;
          Serial.println(total_tiempo);
        }
        if(digitalRead(s1) == 1){
          while(digitalRead(s2) == 0){
            digitalWrite(izquierda, 1);
          }
          digitalWrite(izquierda, 0);
          if(digitalRead(s2) == 1){
            while(digitalRead(s1) == 0){
              digitalWrite(derecha, 1);
            }
            digitalWrite(derecha, 0);
          }
          f_tiempo = millis();
          total_tiempo = f_tiempo - i_tiempo;
          Serial.println(total_tiempo);
        }
        veces2 = veces2 +1;
      }
      

    }
    if(rsw35 == 1 && rsw34 == 1){
      Serial.println("ERROR");
    }
  }
  
    
  }
  
    
  }


