int PinRed=3;
int PinBlue=5;
int PinGreen=9;

int L1[]={122, 234, 21};
int L2[]={33, 53, 155};
int L3[]={200, 255, 12};

void setup()
{
  pinMode(PinRed, OUTPUT);
  pinMode(PinBlue, OUTPUT);
  pinMode(PinGreen, OUTPUT);
}

void loop()
{
  for(int i = 0; i < sizeof(L1)/2; i++){
    analogWrite(PinRed, L1[i]);
    delay(1000);
  }
  
  for(int i=0; i < sizeof(L2)/2 ; i++){
    analogWrite(PinBlue, L2[i]);
    delay(1000);
  }
  
  for(int i=0; i < sizeof(L3)/2 ; i++){
    analogWrite(PinGreen, L3[i]);
    delay(1000);
  }
}