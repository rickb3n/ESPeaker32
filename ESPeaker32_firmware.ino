#include "BluetoothA2DPSink.h"
//BUS I2S G22,G25,G26
//LED G32,G33 ok G34,G35 no, su G2 led builtin
//TOUCH G0 no,G2 circa ok, G4,G15,G13,G12 ok
const int touch5Pin = 13; // F1 T5 - Play/Pause
const int touch4Pin = 15; // F2 T4 - Previous
const int touch3Pin = 2;  // F3 T3 - Next //al gpio 2 c'è il led può dare fastidio
const int touch2Pin = 12;  // F4 T2 - Volume Down //Non posso usare gpio0 in quanto usanto per la programmazione
const int touch1Pin = 4;  // F5 T1 - Volume Up

//const int led7Pin = 34 //Only input, purtroppo
//const int led7Pin = 35 //Only input, purtroppo
const int led8Pin = 32;
const int led9Pin = 33;
const int threshold = 20; // sensibilità touch

bool isPlaying = false;

BluetoothA2DPSink a2dp_sink;

void setup() {
  //Serial.begin(115200);
  //delay(1000); // give me time to bring up serial monitor
  //Serial.println("ESP32 Touch Test");
  pinMode(led8Pin, OUTPUT);
  pinMode(led9Pin, OUTPUT);
  a2dp_sink.start("ESPeaker32");
}

void loop() {
  delay(10); // debounce

  handlePlayPause();
  handlePrevious();
  handleNext();
  handleVolumeDown(); //problemi con GPIO0 in quanto usato per la programmazione
  handleVolumeUp();
}

void handlePlayPause() {
  int touchValue = touchRead(touch5Pin);
  if (touchValue < threshold) {
    digitalWrite(led9Pin, HIGH);
    if (a2dp_sink.is_connected()) {
      if (isPlaying) {
        a2dp_sink.pause();
        isPlaying = false;
      } else {
        a2dp_sink.play();
        isPlaying = true;
      }
    }
    delay(250); // debounce
  } else {
    digitalWrite(led9Pin, LOW);
  }
}

void handlePrevious() {
  int touchValue = touchRead(touch4Pin);
  if (touchValue < threshold) {
    digitalWrite(led8Pin, HIGH);
    a2dp_sink.previous();
    delay(250); // debounce
  } else {
    digitalWrite(led8Pin, LOW);
  }
}

void handleNext() {
  int touchValue = touchRead(touch3Pin);
  if (touchValue < threshold) {
    digitalWrite(led8Pin, HIGH);
    a2dp_sink.next();
    delay(250); // debounce
  } else {
    digitalWrite(led8Pin, LOW);
  }
}

void handleVolumeDown() {
  int touchValue = touchRead(touch2Pin);
  if (touchValue < threshold) {
    digitalWrite(led8Pin, HIGH);
    decreaseVolume();
    delay(250); // debounce
  } else {
    digitalWrite(led8Pin, LOW);
  }
}

void handleVolumeUp() {
  int touchValue = touchRead(touch1Pin);
  if (touchValue < threshold) {
    digitalWrite(led8Pin, HIGH);
    increaseVolume();
    delay(250); // debounce
  } else {
    digitalWrite(led8Pin, LOW);
  }
}

void increaseVolume() {
  int volume = a2dp_sink.get_volume();
  if (volume < 127) {
    volume = min(volume + 10, 127); // Ensure volume does not exceed 127
    a2dp_sink.set_volume(volume);
  }
}

void decreaseVolume() {
  int volume = a2dp_sink.get_volume();
  if (volume > 0) {
    volume = max(volume - 10, 0); // Ensure volume does not go below 0
    a2dp_sink.set_volume(volume);
  }
}