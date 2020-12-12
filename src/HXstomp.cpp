#include "HXstomp.h"
#include <Arduino.h>

HXstomp::HXstomp(byte channel)
{
    channel = constrain(channel - 1, 0, 15);
    this->channel = channel;
    this->presetNumber = 0;
    this->bankNumber = 1;
    this->bankLetter = 1;
    this->snapshotNumber = 1;
    this->exp1Position = 0;
    this->exp2Position = 0;
};

HXstomp::~HXstomp(){

};

void HXstomp::setSerial(Stream *serialObject)
{
    this->serial = serialObject;
};

void HXstomp::sendControlChange(byte outData1, byte outData2)
{
    outData1 = constrain(outData1, 0, 127);
    outData2 = constrain(outData2, 0, 127);
    byte command = CONTROL_CHANGE | channel;
    serial->write(command);
    serial->write(outData1);
    serial->write(outData2);
    delay(TIME_BETWEEN_MIDI_COMMANDS);
};

void HXstomp::sendProgramChange(byte outData1)
{
    outData1 = constrain(outData1, 0, 127);
    byte command = PROGRAM_CHANGE | channel;
    serial->write(command);
    serial->write(outData1);
    delay(TIME_BETWEEN_MIDI_COMMANDS);
};

byte HXstomp::channelNumberGet()
{
    return channel + 1;
};
void HXstomp::channelNumberSet(byte channel)
{
    this->channel = constrain(channel - 1, 0, 15);
};

void HXstomp::exp1(byte position, bool invertPolarity)
{
    position = constrain(position, 0, 100);
    if (invertPolarity == true)
    {
        position = map(position, 100, 0, 0, 127);
    }
    else
    {
        position = map(position, 0, 100, 0, 127);
    }
    byte value constrain(position, 0, 127);
    exp1Position = value;
    sendControlChange(CC_EXP1, value);
};
void HXstomp::exp2(byte position, bool invertPolarity)
{
    position = constrain(position, 0, 100);
    if (invertPolarity == true)
    {
        position = map(position, 100, 0, 0, 127);
    }
    else
    {
        position = map(position, 0, 100, 0, 127);
    }
    byte value constrain(position, 0, 127);
    exp2Position = value;
    sendControlChange(CC_EXP2, value);
};

void HXstomp::fs1()
{
    sendControlChange(CC_FS1, V_127);
};

void HXstomp::fs2()
{
    sendControlChange(CC_FS2, V_127);
};

void HXstomp::fs3()
{
    sendControlChange(CC_FS3, V_127);
};

void HXstomp::fs4()
{
    sendControlChange(CC_FS4, V_127);
};

void HXstomp::fs5()
{
    sendControlChange(CC_FS5, V_127);
};

void HXstomp::looperRecord()
{
    sendControlChange(CC_LOOPER_RECORD, V_RECORD);
};

void HXstomp::looperRecordOverdub()
{
    sendControlChange(CC_LOOPER_RECORD, V_REC_OVERDUB);
};

void HXstomp::looperPlay()
{
    sendControlChange(CC_LOOPER_PLAY_STOP, V_PLAY);
};

void HXstomp::looperStop()
{
    sendControlChange(CC_LOOPER_PLAY_STOP, V_STOP);
};

void HXstomp::looperPlayOnce()
{
    sendControlChange(CC_LOOPER_PLAY_ONCE, V_127);
};

void HXstomp::looperUndoRedo()
{
    sendControlChange(CC_LOOPER_UNDO_REDO, V_127);
};

void HXstomp::looperForward()
{
    sendControlChange(CC_LOOPER_REVERSE, V_LOOPER_NO_REVERSE);
};

void HXstomp::looperReverse()
{
    sendControlChange(CC_LOOPER_REVERSE, V_LOOPER_REVERSE);
};

void HXstomp::looperFullSpeed()
{
    sendControlChange(CC_LOOPER_FULL_HALF, V_LOOPER_FULL);
};

void HXstomp::looperHalfSpeed()
{
    sendControlChange(CC_LOOPER_FULL_HALF, V_LOOPER_HALF);
};

void HXstomp::tapTempo()
{

    sendControlChange(CC_TAP_TEMPO, V_127);
};

void HXstomp::tuner()
{
    sendControlChange(CC_TUNER, V_127);
};

void HXstomp::snapshot1()
{
    snapshotNumber = 1;
    sendControlChange(CC_SNAPSHOT_SELECT, V_SNAPSHOT_1);
};

void HXstomp::snapshot2()
{
    snapshotNumber = 2;
    sendControlChange(CC_SNAPSHOT_SELECT, V_SNAPSHOT_2);
};

void HXstomp::snapshot3()
{
    snapshotNumber = 3;
    sendControlChange(CC_SNAPSHOT_SELECT, V_SNAPSHOT_3);
};

void HXstomp::snapshotNext()
{
    sendControlChange(CC_SNAPSHOT_SELECT, V_SNAPSHOT_NEXT);
};

void HXstomp::snapshotPrev()
{
    sendControlChange(CC_SNAPSHOT_SELECT, V_SNAPSHOT_PREV);
};

void HXstomp::bypassAllON()
{
    sendControlChange(CC_ALL_BYPASS, V_BYPASS);
};

void HXstomp::bypassAllOFF()
{
    sendControlChange(CC_ALL_BYPASS, V_ON);
};

void HXstomp::modeStomp()
{
    sendControlChange(CC_MODE, V_MODE_STOMP);
};

void HXstomp::modeScrool()
{
    sendControlChange(CC_MODE, V_MODE_SCROLL);
};

void HXstomp::modePreset()
{
    sendControlChange(CC_MODE, V_MODE_PRESET);
};

void HXstomp::modeSnapshot()
{
    sendControlChange(CC_MODE, V_MODE_SNAPSHOT);
};

void HXstomp::modeNext()
{
    sendControlChange(CC_MODE, V_MODE_NEXT);
};

void HXstomp::modePrev()
{
    sendControlChange(CC_MODE, V_MODE_PREV);
};

void HXstomp::bankNext(bool samePosition)
{

    if (samePosition == false)
    {
        if (presetNumber < 126)
        {
            double x = (double)presetNumber / 3 - ((int)presetNumber / 3);
            if (x == 0)
            {
                presetNumber = presetNumber + 3;
                bankLetter = 1;
            }
            else if (x < 0.5)
            {
                presetNumber = presetNumber + 2;
                bankLetter = 2;
            }
            else if (x > 0.5)
            {
                presetNumber = presetNumber + 1;
                bankLetter = 3;
            }
            bankNumber = presetNumber / 3 + 1;
            if (presetNumber > 125)
            {
                presetNumber = 0;
                bankNumber = 1;
                bankLetter = 1;
            }
        }
    }
    else
    {
        if (presetNumber < 126)
        {
            presetNumber = presetNumber + 3;
            bankNumber = presetNumber / 3 + 1;
            if (presetNumber > 125)
            {
                presetNumber = 0;
                bankNumber = 1;
                bankLetter = 1;
            }
        }
    }
    sendProgramChange(presetNumber);
};

void HXstomp::bankPrev(bool samePosition)
{
    if (samePosition == false)
    {
        if (presetNumber == 0)
        {
            presetNumber = 123;
            bankNumber = 42;
            bankLetter = 1;
        }
        else if (presetNumber > 0)
        {
            double x = (double)presetNumber / 3 - ((int)presetNumber / 3);
            if (x == 0)
            {
                presetNumber = presetNumber - 3;
                bankLetter = 1;
            }
            else if (x < 0.5)
            {
                presetNumber = presetNumber - 2;
                bankLetter = 2;
            }
            else if (x > 0.5)
            {
                presetNumber = presetNumber - 1;
                bankLetter = 3;
            }
            bankNumber = presetNumber / 3 + 1;
        }
    }
    else
    {
        if (presetNumber == 0)
        {
            presetNumber = 123;
            bankNumber = 42;
            bankLetter = 1;
        }
        else if (presetNumber > 0)
        {
            presetNumber = presetNumber - 3;
            bankNumber = presetNumber / 3 + 1;
        }
    }
    sendProgramChange(presetNumber);
};

void HXstomp::presetNext()
{
    presetNumber++;
    if (presetNumber > 125)
    {
        presetNumber = 0;
    }
    bankNumber = presetNumber / 3 + 1;
    presetSet(presetNumber);
};

void HXstomp::presetPrev()
{
    presetNumber--;
    if (presetNumber < 0)
    {
        presetNumber = 125;
    }
    bankNumber = presetNumber / 3 + 1;
    presetSet(presetNumber);
};

byte HXstomp::presetGet()
{
    return presetNumber;
};

byte HXstomp::bankNumberGet()
{
    return bankNumber;
};

char HXstomp::bankLetterGet()
{
    if (bankLetter == 1)
    {
        return 'A';
    }
    else if (bankLetter == 2)
    {
        return 'B';
    }
    else if (bankLetter == 3)
    {
        return 'C';
    }
    else
    {
        return 'A';
    }
};

void HXstomp::bankSet(byte number, letter letter)
{
    number = constrain(number, 1, 42);
    bankNumber = number;
    int AorBorC = constrain(letter, 1, 3);
    bankLetter = AorBorC;
    AorBorC = map(AorBorC, 1, 3, 3, 1);
    presetNumber = number * 3 - AorBorC;
    sendProgramChange(presetNumber);
};

void HXstomp::bankSet(byte number, byte AorBorC)
{
    number = constrain(number, 1, 42);
    bankNumber = number;
    AorBorC = constrain(AorBorC, 1, 3);
    bankLetter = AorBorC;
    AorBorC = map(AorBorC, 1, 3, 3, 1);
    presetNumber = number * 3 - AorBorC;
    sendProgramChange(presetNumber);
};

void HXstomp::bankSetA()
{
    bankSet(bankNumber, A);
};

void HXstomp::bankSetB()
{
    bankSet(bankNumber, B);
};

void HXstomp::bankSetC()
{
    bankSet(bankNumber, C);
};

void HXstomp::presetSet(byte number)
{
    number = constrain(number, 0, 125);
    presetNumber = number;
    bankNumber = presetNumber / 3 + 1;
    sendProgramChange(presetNumber);
};

void HXstomp::snapshotSet(byte number)
{
    number = constrain(number, 1, 3);
    snapshotNumber = number;
    if (number == 1)
    {
        snapshot1();
    }
    else if (number == 2)
    {
        snapshot2();
    }
    else if (number == 3)
    {
        snapshot3();
    }
};

int HXstomp::getExp1Positon()
{
    return exp1Position;
}

int HXstomp::getExp2Positon()
{
    return exp2Position;
}