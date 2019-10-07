char switch_flag=0;
char key_state[3][3] = {{0,0,0}, {0,0,0},{0,0,0}};        
long time1 = 0;

void setup() {
  
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
}

void loop() {
  if( digitalRead(2) == 0 && switch_flag==0){

    switch_flag=1;
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(12,HIGH);  
    delay(1000);      
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);

  }
  if(switch_flag==1){
    if(digitalRead(2)==0||digitalRead(3)==0||digitalRead(4)==0){

      digitalWrite(8,LOW);
      digitalWrite(10,LOW);
      digitalWrite(12,LOW);
      
      for(int i=0; i<3; i++){
        time1 = millis();
        while(digitalRead(2) && digitalRead(3) && digitalRead(4)){
          if(millis() - time1 >1000){
            break;
          }
        }
        if(digitalRead(2) == 0){
          while(digitalRead(2) == 0);
          key_state[i][0] = 1;
        }
        else if(digitalRead(3) == 0){
          while(digitalRead(3) == 0);
          key_state[i][1] = 1;
        }
        else if(digitalRead(4) == 0){
          while(digitalRead(4) == 0);
          key_state[i][2] = 1;
        }
        else{
          key_state[i][0] = 0;
          key_state[i][1] = 0;
          key_state[i][2] = 0;
        }
      }
      delay(300); 
      for(int i=0; i<3; i++){
        digitalWrite( 8,key_state[i][0]);
        digitalWrite(10,key_state[i][1]);
        digitalWrite(12,key_state[i][2]);
        delay(500);
        digitalWrite( 8,!key_state[i][0]);
        digitalWrite(10,!key_state[i][1]);
        digitalWrite(12,!key_state[i][2]);
        delay(500);
      }
      digitalWrite( 8,key_state[0][0]|key_state[1][0]|key_state[2][0]);
      digitalWrite(10,key_state[0][1]|key_state[1][1]|key_state[2][1]);
      digitalWrite(12,key_state[0][2]|key_state[1][2]|key_state[2][2]);
      delay(300); 
      for(int i=0; i<3; i++){
        digitalWrite( 8,key_state[i][0]);
        digitalWrite(10,key_state[i][1]);
        digitalWrite(12,key_state[i][2]);
        delay(500);
        digitalWrite( 8,!key_state[i][0]);
        digitalWrite(10,!key_state[i][1]);
        digitalWrite(12,!key_state[i][2]);
        delay(500);
      }
      digitalWrite( 8,LOW);
      digitalWrite(10,LOW);
      digitalWrite(12,LOW);
    }


  }
  
}
