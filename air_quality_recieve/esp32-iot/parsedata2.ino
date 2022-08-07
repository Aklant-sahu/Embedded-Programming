void parse_data(String datain){
  indexA=datain.indexOf("A");
indexB=datain.indexOf("B");
indexC=datain.indexOf("C");



data1=datain.substring(0,indexA);
data2=datain.substring(indexA+1,indexB);
data3=datain.substring(indexB+1,indexC);




distances=data1.toInt();
threshold=data2.toInt();
overflowing=data3.toInt();


}
