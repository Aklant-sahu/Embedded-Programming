void navigation_decision()
{
  if(((ly<128 && ly>-129)|| (lx<128 && lx>-129) ) && (lx!=0 || ly!=0) ) // this condition wasnt working because lx and ly can range from 127 to -128
  {
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
  else{
          stopmotors();
      }
  }
  else if(((ry<128 && ry>-129)|| (rx<128 && rx>-129))&& (rx!=0 || ry!=0) )
  {
    
if(ry<buff2 && (rx>bufneg && rx<bufpos))
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
   else{
          stopmotors();
      }
}
