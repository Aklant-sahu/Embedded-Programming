void lifting(){

        
 
 
       if(tri>50) {
        int val=map(tri,50,255,0,spb);
        digitalWrite(dirg, HIGH);
        analogWrite(pwmg, val);
       
        Serial.println("Lift up");
      
  }

        else if(cro>50){
      int val=map(cro,50,255,0,spb);
        digitalWrite(dirg, LOW);
        analogWrite(pwmg, val);
       
        Serial.println("Lift down");
      
        }
          else
          {
     analogWrite(pwmg, 0);
        
   }

}
