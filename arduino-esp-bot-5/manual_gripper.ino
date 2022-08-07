void openStepper()
{


digitalWrite(stepPin2, HIGH);
  digitalWrite(stepPin1, HIGH);
  
  delayMicroseconds(interval1);

  digitalWrite(stepPin2, LOW);
  digitalWrite(stepPin1, LOW);

  delayMicroseconds(interval2);



  stepcount--;
}

void closeStepper()
{



  digitalWrite(stepPin2, HIGH);
  digitalWrite(stepPin1, HIGH);

 delayMicroseconds(interval1);

  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin1, LOW);

  delayMicroseconds(interval2);
  stepcount++;
}
void manualGripper()
{
//if (leftt!= stepopenstate) {
//
//    if (leftt== HIGH) {
//      if(targetstep==0){
//        targetstep=0;
//      }
//      else{
//      targetstep=targetstep-200;
//      }
//    }
// 
//  }
//stepopenstate= leftt;
//
//if (rightt!= stepclosestate) {
//
//    if (rightt== HIGH) {
//      if(targetstep==800){
//        targetstep=800;
//      }
//      else{
//      targetstep=targetstep+200;
//      }
//    }
// 
//  }
//stepclosestate= rightt;
//
// if(stepcount-targetstep<0 ){
//
// if(stepcount !=targetstep){
//    closeStepper();
//    Serial.println("moving to prev target");
// }
//   
//   }
//else if(stepcount-targetstep>=0 ){
//
// if(stepcount !=targetstep){
//    openStepper();
//    Serial.println("moving to next target");
// }
//   
//   }
if(rightt==1){
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);

  closeStepper();

}
else if(leftt==1){
    digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);

     
   openStepper();

}


}
