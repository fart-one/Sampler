#include <Sampler.h>

#define trigPin 5
#define echoPin 4

Sampler sampler;

void setup() {
  Serial.begin(9600);
  sampler
    .setBufferSize(40)
    .setMin(4.0)
    .setMax(100.0);
}

void loop() {
  float measure = singleMeasure();
  sampler.addSample(measure);

  // print raw measure
  Serial.print(measure);
  Serial.print(" ");

  // print invesed value for graph
  Serial.print(
    sampler.getMeasurement() * -1
  );
  
  Serial.println("");
  
  delay(50);

}

float singleMeasure() {

  long time;
  float distance;

  // generate triger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);

  // measure time
  time = pulseIn(echoPin, HIGH, 30000);

  // calculate distance
  distance = time / 58.0;

  return distance;
}