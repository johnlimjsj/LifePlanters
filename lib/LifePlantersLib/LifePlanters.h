#ifndef LifePlanters_h
#define LifePlanters_h

#include <RunningAverage.h>
#include <I2CSoilMoistureSensor.h>
#include "SerialReadPrint.h"
#include <Servo.h>


#define SENSOR1_ADDR 0x20
#define null 1234567

class LifePlanters: public I2CSoilMoistureSensor
{
    // I2CSoilMoistureSensor soilSensor;
  public:
    // Constructors
    LifePlanters(uint8_t address);
    LifePlanters(uint8_t address, uint8_t pump_pin);
    LifePlanters(uint8_t addr, uint8_t pump, uint8_t light);
    LifePlanters(uint8_t addr, uint8_t pump, uint8_t light, uint8_t feeder);

/*************************************
    Sensor Stuff
**************************************/
    // also want to initialize LifePlanters with all the punp and light pins declared in the constructor
    void set_pump_pin(uint8_t pump_pin);
    void set_light_pwm_pin(uint8_t light_pin);
    void set_ph_pin(uint8_t ph_pin);

    void set_moisture_maplimits(int min, int max);
    void set_light_maplimits(int min, int max);

    void set_desired_moisture(int moistval);
    void set_desired_light(int lightval);
    // initialized variables

    
    // methods to initialize in setup()
    void checkStatus();
    bool changeSensorAddr(uint8_t newAddr);
    void findAllSensors();

    // methods to print stuff
    void printAllReadings();
    void printScaledMoisture();
    void printScaledLight();

    int readMoisture();
    int readLight();
    int readTemp();

    // Auto Controller methods
    void control_pump();
    void control_light();
/*************************************
    Feeder Stuff
**************************************/
    // Feeder Servo Setters
    void set_feeder_pin(uint8_t feeder_pin);
    void set_feed_position(int angle);
    void set_nofeed_position(int angle);
    void set_feed_duration(uint16_t duration);
    void set_feed_interval(uint8_t hour_interval, uint8_t minute_interval, uint8_t second_interval);
    void calibrate_servoMoveDuration(uint16_t duration);
    
    // Feeder Servo Controller methods
    void control_feeder(); 

    
 



    // data processing functions

  private:
    I2CSoilMoistureSensor soilSensor;

    uint8_t _pump_pin= NAN; 
    uint8_t _light_pin= NAN;
    uint8_t _feeder_pin=NAN;

    uint16_t _desired_moisture = 60;
    uint16_t _desired_light = 60;

    const uint8_t MOIST_ARR_SIZE=5;
    const uint8_t LIGHT_ARR_SIZE=5;
    const uint8_t TEMP_ARR_SIZE=5;
    const uint8_t PH_ARR_SIZE=5;

    const int in_min_moist = 236, in_max_moist = 655;
    const long in_min_light = 236, in_max_light = 60000;

    int _feed_angle;
    int _nofeed_angle;
    uint16_t _feed_duration = 5000;
    uint16_t _servo_MoveDuration = 100;
    unsigned long _feed_interval = 100000;
    unsigned long _prevfeedtime;

    double _filter_moist, _filter_light, _filter_temp;

    int out_min_moist = 0, out_max_moist = 100, out_min_light = 0, out_max_light = 100;

    void _activatePump(int curr_moisture);
    int _activateLight(int curr_light_intensity);

    double _mapping(long out_min, long out_max, long in_reading, long in_min, long in_max, uint8_t mode);


};

enum KEYS
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

#endif