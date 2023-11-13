// Constants defining Arduino pin connections
const int TRIG_PIN = 6;        // Pin connected to Ultrasonic Sensor's TRIG terminal
const int ECHO_PIN = 7;        // Pin connected to Ultrasonic Sensor's ECHO terminal
const int SPEAKER_PIN = 5;     // Pin connected to the speaker
const int VIBRATOR_PIN = 4;    // Pin connected to the vibrator

// Threshold distance for triggering actions (in centimeters)
const int DISTANCE_THRESHOLD = 50;

// Variables for measuring distance
float duration_us, distance_cm;

void setup() {
    Serial.begin(9600);

    // Setup code to run once
    pinMode(TRIG_PIN, OUTPUT);    // Set TRIG_PIN to output mode
    pinMode(ECHO_PIN, INPUT);     // Set ECHO_PIN to input mode
    pinMode(SPEAKER_PIN, OUTPUT); // Set SPEAKER_PIN to output mode
    pinMode(VIBRATOR_PIN, OUTPUT);// Set VIBRATOR_PIN to output mode
}

void loop() {
    // Main code to run repeatedly

    // Generate a 10-microsecond pulse to TRIG_PIN to trigger the ultrasonic sensor
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the duration of the pulse from ECHO_PIN, which corresponds to the rebound
    duration_us = pulseIn(ECHO_PIN, HIGH);

    // Calculate the distance in centimeters
    distance_cm = 0.017 * duration_us;

    // Print the measured distance to the serial monitor
    Serial.println(distance_cm);

    // Check if the measured distance is below the defined threshold
    if (distance_cm < DISTANCE_THRESHOLD) {
        Serial.println("ACTION: Turning ON Speaker and Vibrator");
        digitalWrite(SPEAKER_PIN, HIGH);   // Turn on the speaker
        digitalWrite(VIBRATOR_PIN, HIGH);  // Turn on the vibrator
    } else {
        Serial.println("ACTION: Turning OFF Speaker and Vibrator");
        digitalWrite(SPEAKER_PIN, LOW);    // Turn off the speaker
        digitalWrite(VIBRATOR_PIN, LOW);   // Turn off the vibrator
    }

    delay(100); // Delay to control the loop speed
}
