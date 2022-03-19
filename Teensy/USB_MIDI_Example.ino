/* Simple Teensy DIY USB-MIDI controller.
  Created by Liam Lacey, based on the Teensy USB-MIDI Buttons example code.

   Contains 8 push buttons for sending MIDI messages,
   and a toggle switch for setting whether the buttons
   send note messages or CC messages.

   The toggle switch is connected to input pin 0,
   and the push buttons are connected to input pins 1 - 8.

   You must select MIDI from the "Tools > USB Type" menu for this code to compile.

   To change the name of the USB-MIDI device, edit the STR_PRODUCT define
   in the /Applications/Arduino.app/Contents/Java/hardware/teensy/avr/cores/usb_midi/usb_private.h
   file. You may need to clear your computers cache of MIDI devices for the name change to be applied.

   See https://www.pjrc.com/teensy/td_midi.html for the Teensy MIDI library documentation.

*/
#define NUM_OF_BUTTONS 8
#define MS_DELAY 500

// the MIDI channel number to send messages
const int MIDI_CHAN = 1;


const int MIDI_MODE_NOTES = 0;
const int MIDI_MODE_CCS = 1;

//Variable that stores the current MIDI mode of the device (what type of messages the push buttons send).
int midiMode = MIDI_MODE_NOTES;

//Arrays the store the exact note and CC messages each push button will send.
const int MIDI_NOTE_NUMS[NUM_OF_BUTTONS] = {64, 66, 68, 69, 71, 73, 75, 76};
const int MIDI_NOTE_VELS[NUM_OF_BUTTONS] = {110, 110, 110, 110, 110, 110, 110, 110};
const int MIDI_CC_NUMS[NUM_OF_BUTTONS] = {24, 25, 26, 27, 20, 21, 22, 23};
const int MIDI_CC_VALS[NUM_OF_BUTTONS] = {127, 127, 127, 127, 127, 127, 127, 127};

//==============================================================================
//==============================================================================
//==============================================================================
//The setup function. Called once when the Teensy is turned on or restarted

void setup()
{

}

//==============================================================================
//==============================================================================
//==============================================================================
//The loop function. Called over-and-over once the setup function has been called.

void loop()
{
  
  for(int i = 0; i < NUM_OF_BUTTONS; i++){
//    usbMIDI.sendControlChange (MIDI_CC_NUMS[i], MIDI_CC_VALS[i], MIDI_CHAN);
//    delay(MS_DELAY);

    usbMIDI.sendNoteOn (MIDI_NOTE_NUMS[i], 110, MIDI_CHAN);
    delay(100);
    usbMIDI.sendNoteOff (MIDI_NOTE_NUMS[i], 0, MIDI_CHAN);
    delay(MS_DELAY);
//    usbMIDI.sendControlChange (MIDI_CC_NUMS[i], 0, MIDI_CHAN);
//    delay(1000);
//    while (usbMIDI.read())
//    {
//      // ignoring incoming messages, so don't do anything here.
//    }
  }
}
