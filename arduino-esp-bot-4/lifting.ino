

void lift_up(){

//  prev_a_state=digitalRead(ENCA);
        
//        int val=map(tri,50,255,0,spb);
      int  val=200;
        digitalWrite(dirg, HIGH);
        analogWrite(pwmg, val);
        countup();
       
        Serial.println("Lift up");
}

void lift_down(){
//   prev_a_state=digitalRead(ENCA);
        
//      int val=map(cro,50,255,0,spb);
int val=200;
        digitalWrite(dirg, LOW);
        analogWrite(pwmg, val);
        countdown();
       
        Serial.println("Lift down");
      
}

void lifting(){
//
//       if(tri>50) {
//       lift_up();
//      
//  }
//
//        else if(cro>50){
//          lift_down();
//        }
//          else
//          {
//     analogWrite(pwmg, 0);
//        
//   }

if(tri>50 && lifting_up==0){
   lifting_up=1;
  while(tri>50){
   fetch_data();

parse_data(datain);
      lift_up();
  }

}
else if(tri>50 && lifting_up==1){
   lifting_up=0;
  while(tri>50){
     fetch_data();

parse_data(datain);
   analogWrite(pwmg, 0);
   Serial.println("stop_lift");
  }
}
else if(lifting_up==1){
  lift_up();
}
else if(cro>50 && lifting_down==0){
   lifting_down=1;
  while(cro>50){
      fetch_data();

parse_data(datain);
      lift_down();
  }
}

else if(cro>50 && lifting_down==1){
  lifting_down=0;
  while(cro>50){
      fetch_data();

parse_data(datain);
   analogWrite(pwmg, 0);
   Serial.println("stop_lift");
  }
}

else if(lifting_down==1){
  lift_down();
}
else if(lifting_up==0 && lifting_down==0){
  analogWrite(pwmg, 0);
   Serial.println("stop_lift");
}




}
