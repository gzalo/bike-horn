#define NOTE_A  440
#define NOTE_B  494
#define NOTE_C  523
#define NOTE_D  587
#define NOTE_E  659
#define NOTE_F  698

const int melody[] = {NOTE_E, NOTE_B, NOTE_C, NOTE_D, NOTE_C, NOTE_B, NOTE_A, NOTE_A, NOTE_C, NOTE_E, NOTE_D, NOTE_C, NOTE_B, NOTE_B, NOTE_C, NOTE_D, NOTE_E, NOTE_C, NOTE_A, NOTE_A};
const int melodyLen = 20;

const int BUZZER = 4;
const int BUTTON = 0;
int idx = 0;
int prevStatus = HIGH;

void setup()
{
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  int newStatus = digitalRead(BUTTON);
    
  if(newStatus == LOW && prevStatus == HIGH){
  	tone(BUZZER,melody[idx]);
    idx = (idx + 1) % melodyLen;
  }
  
  if(newStatus == HIGH){
  	noTone(BUZZER);
  }
  
  prevStatus = newStatus;
  delay(50);
}