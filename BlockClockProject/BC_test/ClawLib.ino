void SLCC_hand_up()
{
  digitalWrite(CLAW_MTR, HIGH);
  while (!digitalRead(CLAW_UP));
  digitalWrite(CLAW_MTR, LOW);
}

void SLCC_hand_down()
{
  digitalWrite(CLAW_MTR, HIGH);
  while (!digitalRead(CLAW_DOWN));
  digitalWrite(CLAW_MTR, LOW);

}

void SLCC_hand_grasp()
{
  Serial << "Enter grasp angle : \n";
  int cg = Serial.parseInt();
 // analogWrite(CLAW_PWM, cg);// CLAW_Grasp);
// myservo.write(cg);
}

void SLCC_hand_release()
{
  analogWrite(CLAW_PWM, CLAW_Release);
}

