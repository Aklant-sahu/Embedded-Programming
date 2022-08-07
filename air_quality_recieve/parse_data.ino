void parse_data(String datain){
  indexA=datain.indexOf("A");
indexB=datain.indexOf("B");
indexC=datain.indexOf("C");
indexD=datain.indexOf("D");
indexE=datain.indexOf("E");
indexF=datain.indexOf("F");
indexG=datain.indexOf("G");


data1=datain.substring(0,indexA);
data2=datain.substring(indexA+1,indexB);
data3=datain.substring(indexB+1,indexC);
data4=datain.substring(indexC+1,indexD);
data5=datain.substring(indexD+1,indexE);
data6=datain.substring(indexE+1,indexF);
data7=datain.substring(indexF+1,indexG);



t=data1.toInt();
h=data2.toInt();
mq2value=data3.toInt();
p=data4.toInt();
mq7value=data5.toInt();
mq135value=data6.toInt();
dustDensity=data7.toInt();

}
