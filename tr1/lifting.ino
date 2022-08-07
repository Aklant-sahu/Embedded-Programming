

void lift_up(){

//  prev_a_state=digitalRead(ENCA);
        
        int val=map(tri,50,255,0,spb);
        digitalWrite(dirg, HIGH);
        analogWrite(pwmg, val);
        countup();
       
        Serial.println("Lift up");
}

void lift_down(){
//   prev_a_state=digitalRead(ENCA);
        
      int val=map(cro,50,255,0,spb);
        digitalWrite(dirg, LOW);
        analogWrite(pwmg, val);
        countdown();
       
        Serial.println("Lift down");
      
}

void lifting(){

       if(tri>50) {
       lift_up();
      
  }

        else if(cro>50){
          lift_down();
        }
          else
          {
     analogWrite(pwmg, 0);
        
   }

}
