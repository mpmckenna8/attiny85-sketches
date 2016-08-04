/*
 * Writes songs
 */

int32_t US_IN_SEC = 1000000;
int32_t WHOLE_NOTE = US_IN_SEC / 2;
int32_t PAUSE = WHOLE_NOTE / 16;

int32_t C_NOTE = 262;
int32_t D_NOTE = 294;
int32_t E_NOTE = 330;
int32_t F_NOTE = 349;
int32_t G_NOTE = 392;
int32_t A_NOTE = 440;
int32_t B_NOTE = 494;

const int32_t NOTES[] = {
  C_NOTE,
  C_NOTE,
  C_NOTE,
  D_NOTE,
  E_NOTE,
  
  E_NOTE,
  D_NOTE,
  E_NOTE,
  F_NOTE,
  G_NOTE,

  B_NOTE,
  B_NOTE,
  B_NOTE,
  G_NOTE,
  G_NOTE,
  G_NOTE,
  E_NOTE,
  E_NOTE,
  E_NOTE,
  C_NOTE,
  C_NOTE,
  C_NOTE,

  G_NOTE,
  F_NOTE,
  E_NOTE,
  D_NOTE,
  C_NOTE,
};

const int32_t DURATIONS[] = {
  WHOLE_NOTE, 
  WHOLE_NOTE, 
  3*WHOLE_NOTE/4,
  WHOLE_NOTE/4, 
  WHOLE_NOTE,
  
  3*WHOLE_NOTE/4,
  WHOLE_NOTE/4, 
  3*WHOLE_NOTE/4,
  WHOLE_NOTE/4, 
  2*WHOLE_NOTE,

  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  WHOLE_NOTE/3,
  
  3*WHOLE_NOTE/4,
  WHOLE_NOTE/4, 
  3*WHOLE_NOTE/4,
  WHOLE_NOTE/4, 
  2*WHOLE_NOTE,
};

void setup() {
  pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
  
  int32_t i = 0;
  int32_t numNotes = sizeof(NOTES) / sizeof(int32_t);
  
  // the loop function runs over and over again forever
  while (true) {
    for (int32_t i = 0; i < numNotes; i++) {
      playNote(NOTES[i], DURATIONS[i]);
      playNote(0, PAUSE);
    }
  }
}

void playNote(int32_t freq, int32_t duration) {
  if (freq == 0) {
    delayMicroseconds(duration);
    return;
  }

  
  int32_t period = 1000000 / freq;
  int32_t numLoops = duration / period;
  for (int32_t i = 0; i < numLoops; i++) {
    delayMicroseconds(period);
    toggle();
  }
}

int32_t flag = 0;
void toggle() {
  flag = flag ? 0 : 255;
  analogWrite(4, flag);
}

void loop() {

}

