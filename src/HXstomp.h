/**
 * @file HXstomp.h
 * @author Adam Waligora
 * @brief Library for controlling HX Stomp via Midi
 * @version 0.1
 * @date 2019-11-23
 * 
 * @copyright Copyright (c) 2019
 * This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef HXstomp_h
#define HXstomp_h

#include <Arduino.h>

const byte CC_EXP1 = 1;
const byte CC_EXP2 = 2;
const byte CC_FS1 = 49;
const byte CC_FS2 = 50;
const byte CC_FS3 = 51;
const byte CC_FS4 = 52;
const byte CC_FS5 = 53;
const byte CC_LOOPER_RECORD = 60;
const byte V_RECORD = 127;
const byte V_REC_OVERDUB = 0;
const byte CC_LOOPER_PLAY_STOP = 61;
const byte V_PLAY = 127;
const byte V_STOP = 0;
const byte CC_LOOPER_PLAY_ONCE = 62;
const byte CC_LOOPER_UNDO_REDO = 63;
const byte V_LOOPER_UNDO = 64;
const byte V_LOOPER_REDO = 127;
const byte CC_LOOPER_REVERSE = 65;
const byte V_LOOPER_NO_REVERSE = 0;
const byte V_LOOPER_REVERSE = 127;
const byte CC_LOOPER_FULL_HALF = 66;
const byte V_LOOPER_FULL = 0;
const byte V_LOOPER_HALF = 127;
const byte CC_TAP_TEMPO = 64;
const byte CC_TUNER = 68;
const byte CC_SNAPSHOT_SELECT = 69;
const byte V_SNAPSHOT_1 = 0;
const byte V_SNAPSHOT_2 = 1;
const byte V_SNAPSHOT_3 = 2;
const byte V_SNAPSHOT_NEXT = 8;
const byte V_SNAPSHOT_PREV = 9;
const byte CC_ALL_BYPASS = 70;
const byte V_BYPASS = 0;
const byte V_ON = 127;
const byte CC_MODE = 71;
const byte V_MODE_STOMP = 0;
const byte V_MODE_SCROLL = 1;
const byte V_MODE_PRESET = 2;
const byte V_MODE_SNAPSHOT = 3;
const byte V_MODE_NEXT = 4;
const byte V_MODE_PREV = 5;

const byte V_0 = 0;
const byte V_64 = 64;
const byte V_127 = 127;

const byte PROGRAM_CHANGE = 0xC0;
const byte CONTROL_CHANGE = 0xB0;
const byte TIME_BETWEEN_MIDI_COMMANDS = 20;



class HXstomp
{
private:
   byte channel;
   byte presetNumber;
   byte bankNumber;
   byte bankLetter;
   byte snapshotNumber;
   byte exp1Position;
   byte exp2Position;
   char presetName[5];
   Stream *serial;

public:
  enum letter
  {
    A = 1,
    B = 2,
    C = 3
  };

   /**
    * @brief Construct a new HXstomp::HXstomp object
    * 
    * @param channel The output channel on which the message will be sent
    (values from 1 to 16). Note: you cannot send to OMNI.
    */
   HXstomp(byte = 1);

   /**
     * @brief Destroy the HXstomp object
     * 
     */
   ~HXstomp();

   void setSerial(Stream *serialObject);

   /**
    * @brief Send Control Change message
    * 
    * @param outData1 The first data byte.
    * @param outData2 The second data byte
    */
   void sendControlChange(byte outData1, byte outData2);

   /**
     * @brief Send Program Change message
     * 
     * @param outData1 The first data byte.
     */
   void sendProgramChange(byte outData1);

   /**
     * @brief Get the Channel Number object
     * 
     * @return byte channel mumber
     */
   byte channelNumberGet();

   /**
     * @brief Set the Channel Number object
     * 
     * @param channel channel number
     */
   void channelNumberSet(byte channel);

   /**
   * @brief Sets the position of the EXP1 expression pedal
   * 
   * @param position percentage pedal position from 0 to 100
   * @param invertPolarity invert polarity TIP/RING
   */
   void exp1(byte position, bool invertPolarity = false);

   /**
   * @brief Sets the position of the EXP2 expression pedal
   * 
   * @param position percentage pedal position from 0 to 100
   * @param invertPolarity invert polarity TIP/RING
   */
   void exp2(byte position, bool invertPolarity = false);

   /**
     * @brief Switch the FS1 button
     * 
     */
   void fs1();

   /**
     * @brief Switch the FS2 button
     * 
     */
   void fs2();

   /**
     * @brief Switch the FS3 button
     * 
     */
   void fs3();

   /**
     * @brief Switch the FS4 button
     * 
     */
   void fs4();

   /**
     * @brief Switch the FS5 button
     * 
     */
   void fs5();

   /**
     * @brief Switch on loop recording
     * 
     */
   void looperRecord();

   /**
     * @brief Switch on loop overdub recording
     * 
     */
   void looperRecordOverdub();

   /**
     * @brief Switch on loop play
     * 
     */
   void looperPlay();

   /**
     * @brief Switch off  loop play
     * 
     */
   void looperStop();

   /**
     * @brief Turn on loop playback once.
     * 
     */
   void looperPlayOnce();

   /**
     * @brief Undo / Redo
     * 
     */
   void looperUndoRedo();

   /**
     * @brief Enable forward loop playback
     * 
     */
   void looperForward();

   /**
     * @brief Enable loop playback reverse
     * 
     */
   void looperReverse();

   /**
     * @brief Enable loop playback at full speed
     * 
     */
   void loopeFullSpeed();

   /**
     * @brief Enable loop playback at half speed
     * 
     */
   void looperHalfSpeed();

   /**
     * @brief Tap tempo click
     * 
     */
   void tapTempo();

   /**
     * @brief Tuner screen on/of
     * 
     */
   void tuner();

   /**
     * @brief Enable snapshot 1
     * 
     */
   void snapshot1();

   /**
     * @brief Enable snapshot 2
     * 
     */
   void snapshot2();

   /**
     * @brief Enable snapshot 3
     * 
     */
   void snapshot3();

   /**
     * @brief Next snapshot
     * 
     */
   void snapshotNext();

   /**
     * @brief Previous snapshot
     * 
     */
   void snapshotPrev();

   /**
     * @brief All bypass on
     * 
     */
   void bypassAllON();

   /**
     * @brief All bypass off
     * 
     */
   void bypassAllOFF();

   /**
     * @brief Enable stomp mode
     * 
     */
   void modeStomp();

   /**
     * @brief Enable scroll mode
     * 
     */
   void modeScrool();

   /**
     * @brief Enable preset mode
     * 
     */
   void modePreset();

   /**
     * @brief Enable preset snapshot
     * 
     */
   void modeSnapshot();

   /**
     * @brief Change to next mode
     * 
     */
   void modeNext();

   /**
     * @brief Change to previous mode
     * 
     */
   void modePrev();

   /**
    * @brief Change to next bank
    * 
    * @param samePosition bool - if false -  change to the first position of preset in the next bank, for example: current bank 10 preset B - next bank 10 preset A
    * if true - change to the same preset position in the next bank, for example:  current bank 10 preset B - next bank 10 preset B                         - 
    */
   void bankNext(bool samePosition = false);

   /**
  * @brief Change to previous bank
  * 
  * @param samePosition bool - if false -  change to the first position of preset in the previous bank, for example: current bank 10 preset B - next bank 9 preset A
  * if true - change to the same preset position in the previous  bank, for example:  current bank 10 preset B - next bank 9 preset B 
  *                         - 
  */
   void bankPrev(bool samePosition = false);

   /**
     * @brief Change to next preset
     * 
     */
   void presetNext();

   /**
     * @brief Change to previous preset
     * 
     */
   void presetPrev();

   /**
     * @brief Get the Preset Number 
     * 
     * @return byte preset number
     */
   byte presetGet();

   /**
     * @brief Get the Bank Number 
     * 
     * @return byte bank number
     */
   byte bankNumberGet();

   /**
     * @brief Get the Bank letter 
     * 
     * @return char bank letter
     */
   char bankLetterGet();

   /**
     * @brief Set the bank number on HX Stomp
     * 
     * @param number byte bank number from 1 - 42
     * @param letter letter bank letter A or B or C 
     */
   void bankSet(byte number, letter letter);

   /**
     * @brief Set the bank number on HX Stomp
     * 
     * @param number byte bank number from 1 - 42
     * @param AorBorC byte bank letter A = 1, B = 2, C = 3
     */
   void bankSet(byte number, byte AorBorC = 1);

   /**
     * @brief Set the preset number on HX Stomp
     * 
     * @param number byte preset number from 0 - 125
     */
   void presetSet(byte number);

   /**
     * @brief Set the Snapshot 
     * 
     * @param number byte number 1 or 2 or 3
     */
   void snapshotSet(byte number);

   /**
   * @brief Return Exp1 Positon 
   * 
   * @return int exp position
   */
   int getExp1Positon();

   /**
   * @brief Return Exp2 Positon 
   * 
   * @return int exp position
   */
   int getExp2Positon();
};

#endif