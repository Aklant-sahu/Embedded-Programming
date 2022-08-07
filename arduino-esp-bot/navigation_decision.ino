void navigation_decision()
{
  if(ly>=buff2 && ly<=buff1 && lx>=buff2 && ly<=buff1 && ry>=buff2 && ry<=buff1 && rx>=buff2 && ry<=buff1 ) {
     stopmotors();
  }
  else{
    
  
  if (ly<buff2 && (lx>bufneg && lx<bufpos))
      {
        forward_fast();
      }
   
  else if(ly>buff1 && (lx>bufneg && lx<bufpos))
      {
        backward_fast();
      }
  else if(lx<buff2 && (ly>bufneg && ly<bufpos))
      {
        left_fast();
      }
  else if(lx>buff1 && (ly>bufneg && ly<bufpos))
      {
        right_fast();
        //Serial.print(lx);
      }
  else if(ry<buff2 && (rx>bufneg && rx<bufpos))
      {
        forward_slow();
      }
  else if(ry>buff1 &&( rx>bufneg && rx<bufpos))
      {
        backward_slow();
      }
  else if(rx<buff2 && (ry>bufneg && ry<bufpos))
      {
        left_slow();
      }
  else if(rx>buff1 && (ry>bufneg && ry<bufpos))
      {
        right_slow();
      }
      else{
        
      stopmotors();
      }

 
    }
//      if ((lx <= 20 && lx >= -20 && ly <= 20 && ly >= -20)&&(rx <= 20 && rx >= -20 && ry <= 20 && ry >= -20))
//      {
//        stopmotors();
//      }




}
