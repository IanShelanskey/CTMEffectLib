//  CTMEffect.cpp
/*
 Coded by Ian Shelanskey ( ianshela@buffalo.edu )
 Design by Lynne Koscielniak with Dyan Burlingame (lk2@buffalo.edu,dlo@buffalo.edu)
 
 * Date : 6/11/13
 * All code (c)2013 all rights reserved
 
 
 Project MIST
 supported by University at Buffalo's TECHNE Institute for Arts and Emerging Technologies
 
 ------------------------------------------------
 Library methods:
    
    CTMEffect init : Set the pinouts connected to the digital potentiometers; Dpin              
                     is dimmer, PCpin is for Presets or color temperature.
 
    Fadedown(int val, int DfadeTo, float Dtime) : Fades intensity down from val to DfadeTo in Dtime
 
    Fadeup(int val, int DfadeTo, float Dtime)   : Fades intesity up from val to DfadeTo in Dtime
    
    CCTdown(int val, int DfadeTo, float Dtime) : Fades CCT down from val to DfadeTo in Dtime
 
    CCTup(int val, int DfadeTo, float Dtime)   : Fades CCT up from val to DfadeTo in Dtime
 
    Preset(int preset) : switches between 5 presets
 
 -------------------------------------------------
 */

#include "Arduino.h"
#include "DigitalPot.h"
#include "CTMEffect.h"



CTMEffect::CTMEffect(int Dpin, int PCpin) : dim(Dpin) , pc(PCpin)
{
    _Dval = 0;
    _Cval = 0;
    _DlastFadeup = millis();
    _DlastFadedown = millis();
    _ClastFadeup = millis();
    _ClastFadedown = millis();
    
}

void CTMEffect::Fadedown(int val, int DfadeTo, float Dtime)
{
    
    if (_Duse = 0)                                  
        {
            _DlastFadeup = millis();
            Serial.println("Fade down started");
            _Dval = val;
            _Duse = 1;                              
            //Serial.println("_Duse set to 1");
        }
    if((millis() - _DlastFadeup) >= ((Dtime*1000)/51))
        {
            //Serial.println("Second if statement");
            //Serial.println((millis()-_DlastFadeup));
            _DlastFadeup = millis();
            _Dval += 5;
            if (_Dval>=DfadeTo)
            {
                Serial.println("FADE DOWN COMPLETE");
                _Dval = DfadeTo;
                dim.set(_Dval);
                _Duse = 0;
                return;
            }
            Serial.println("FADING DOWN");
            Serial.println(_Dval);
            dim.set(_Dval);
            //Serial.println("if statement complete");
        }

}
void CTMEffect::Fadeup(int val, int DfadeTo, float Dtime)
{
    
    if (_Duse = 0)
    {
        _DlastFadeup = millis();
        Serial.println("Fade up started");
        _Dval = val;
        _Duse = 1;
        //Serial.println("_Duse set to 1");
    }
    if((millis() - _DlastFadeup) >= ((Dtime*1000)/51))
    {
        //Serial.println("Second if statement");
        //Serial.println((millis()-_DlastFadeup));
        _DlastFadeup = millis();
        _Dval -= 5;
        if (_Dval<=DfadeTo)
        {
            Serial.println("FADE UP COMPLETE");
            _Dval = DfadeTo;
            dim.set(_Dval);
            _Duse = 0;
            return;
        }
        Serial.println("FADING UP");
        Serial.println(_Dval);
        dim.set(_Dval);
        //Serial.println("if statement complete");
    }
    
}
void CTMEffect::CCTdown(int val, int CfadeTo, float Ctime)
{
    
    if (_Cuse = 0)
    {
        _ClastFadeup = millis();
        Serial.println("CCT down started");
        _Cval = val;
        _Cuse = 1;
        //Serial.println("_Duse set to 1");
    }
    if((millis() - _ClastFadeup) >= ((Ctime*1000)/51))
    {
        //Serial.println("Second if statement");
        //Serial.println((millis()-_ClastFadeup));
        _ClastFadeup = millis();
        _Cval += 5;
        if (_Cval>=CfadeTo)
        {
            Serial.println("CCT DOWN COMPLETE");
            _Cval = CfadeTo;
            pc.set(_Cval);
            _Cuse = 0;
            return;
        }
        Serial.println("CCT-ing DOWN");
        Serial.println(_Cval);
        pc.set(_Cval);
        //Serial.println("if statement complete");
    }
}

void CTMEffect::CCTup(int val, int CfadeTo, float Ctime)
{
    
    if (_Cuse = 0)
    {
        _ClastFadeup = millis();
        Serial.println("CCT up started");
        _Cval = val;
        _Cuse = 1;
        //Serial.println("_Duse set to 1");
    }
    if((millis() - _ClastFadeup) >= ((Ctime*1000)/51))
    {
        //Serial.println("Second if statement");
        //Serial.println((millis()-_ClastFadeup));
        _ClastFadeup = millis();
        _Cval -= 5;
        if (_Cval<=CfadeTo)
        {
            Serial.println("CCT UP COMPLETE");
            _Cval = CfadeTo;
            pc.set(_Cval);
            _Cuse = 0;
            return;
        }
        Serial.println("CCT-ing UP");
        Serial.println(_Cval);
        pc.set(_Cval);
        //Serial.println("if statement complete");
    }
}


void CTMEffect::Preset(int preset)
{
   switch (preset)
    {
        case 1:
            pc.set(50);
            break;
        case 2:
            pc.set(100);
            break;
        case 3:
            pc.set(150);
            break;
        case 4:
            pc.set(200);
            break;
        case 5:
            pc.set(250);
            break;
            
        default:
            break;
    }
}

int CTMEffect :: getDval()
{
    return (_Dval);
}

int CTMEffect :: getCval()
{
    return (_Cval);
}




