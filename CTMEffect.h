//
//  CTMEffect.h
//
//
//  Created by Ian Shelanskey on 6/11/13.
/*
 This library provides a basic control structure for the CTM to base more complex effects around.
 */





#ifndef ELEffect_h
#define ELEffect_h

#include "Arduino.h"


class DigitalPot;

class CTMEffect
{
   public:
    CTMEffect(int Dpin, int PCpin);
    void Fadeup(int val, int DfadeTo, float Dtime);
    void Fadedown(int val, int DfadeTo, float Dtime);
    void CCTup(int val, int CfadeTo, float Ctime);
    void CCTdown(int val, int CfadeTo, float Ctime);
    void Preset(int preset);
    int getDval();
    int getCval();
   private:
    DigitalPot dim;
    DigitalPot pc;
    int _Dpin;
    int _PCpin;
    int _Dval;
    int _Cval;
    int _Duse;
    int _Cuse;
    unsigned long _DlastFadeup;
    unsigned long _ClastFadeup;
    unsigned long _DlastFadedown;
    unsigned long _ClastFadedown;
    int _Dcheck;
    int _Ccheck;
};
#endif