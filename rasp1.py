import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
LED_PIN = 11
GPIO.setup(LED_PIN, GPIO.OUT)

while True:
    GPIO.output(LED_PIN,True)

time.sleep(3)
GPIO.cleanup
