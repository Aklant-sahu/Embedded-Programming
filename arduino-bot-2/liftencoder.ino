//#define ENCA A6 // YELLOW
//#define ENCB A7
////int prev_enca=0,prev_encb=0;
//int prev_a_state,prev_b_state;
//int count;


void countup(){

  int a_state=digitalRead(ENCA);
  if(prev_a_state!=a_state){
   count++;
   Serial.println(count);
   prev_a_state=a_state;
  }
  

  
}

void countdown(){

  int a_state=digitalRead(ENCA);
  if(prev_a_state!=a_state){
   count--;
    Serial.println(count);
   prev_a_state=a_state;
  }
  

  
}

void enc_lift_up(){


        
        int val;
        digitalWrite(dirg, HIGH);
        analogWrite(pwmg, val);
        countup();
       
        Serial.println("Lift up");
}

void enc_lift_down()
{
   
        
      int val=map(cro,50,255,0,spb);
        digitalWrite(dirg, LOW);
        analogWrite(pwmg, val);
        countdown();
       
        Serial.println("Lift down");
      
}

void same(){
  target=stop_count[st_count];
  st_count=digitalRead(ENCA);
  

  
}
