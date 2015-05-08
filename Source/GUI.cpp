/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (osc1Pitch = new Slider ("new slider"));
    osc1Pitch->setRange (-24, 24, 1);
    osc1Pitch->setSliderStyle (Slider::RotaryVerticalDrag);
    osc1Pitch->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    osc1Pitch->addListener (this);

    addAndMakeVisible (osc1PulseWidth = new Slider ("new slider"));
    osc1PulseWidth->setRange (0.1, 0.9, 0);
    osc1PulseWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    osc1PulseWidth->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    osc1PulseWidth->addListener (this);

    addAndMakeVisible (osc1Shape = new Slider ("new slider"));
    osc1Shape->setRange (0, 4, 0);
    osc1Shape->setSliderStyle (Slider::RotaryVerticalDrag);
    osc1Shape->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    osc1Shape->addListener (this);

    addAndMakeVisible (osc1Gain = new Slider ("new slider"));
    osc1Gain->setRange (0, 1, 0);
    osc1Gain->setSliderStyle (Slider::RotaryVerticalDrag);
    osc1Gain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    osc1Gain->addListener (this);

    addAndMakeVisible (Console = new TextEditor ("new text editor"));
    Console->setMultiLine (false);
    Console->setReturnKeyStartsNewLine (false);
    Console->setReadOnly (false);
    Console->setScrollbarsShown (true);
    Console->setCaretVisible (true);
    Console->setPopupMenuEnabled (true);
    Console->setText (String::empty);

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("scan Midi Messages"));
    textButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    osc1Pitch = nullptr;
    osc1PulseWidth = nullptr;
    osc1Shape = nullptr;
    osc1Gain = nullptr;
    Console = nullptr;
    textButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    osc1Pitch->setBounds (25, 25, 75, 75);
    osc1PulseWidth->setBounds (115, 25, 75, 75);
    osc1Shape->setBounds (205, 25, 75, 75);
    osc1Gain->setBounds (295, 25, 75, 75);
    Console->setBounds (7, 196, 200, 200);
    textButton->setBounds (10, 165, 195, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == osc1Pitch)
    {
        //[UserSliderCode_osc1Pitch] -- add your slider handling code here..
      processor.guiToOSC (1,sliderThatWasMoved->getValue ());
        //[/UserSliderCode_osc1Pitch]
    }
    else if (sliderThatWasMoved == osc1PulseWidth)
    {
        //[UserSliderCode_osc1PulseWidth] -- add your slider handling code here..
      processor.guiToOSC (2,sliderThatWasMoved->getValue ());
        //[/UserSliderCode_osc1PulseWidth]
    }
    else if (sliderThatWasMoved == osc1Shape)
    {
        //[UserSliderCode_osc1Shape] -- add your slider handling code here..
      processor.guiToOSC (3,sliderThatWasMoved->getValue ());
        //[/UserSliderCode_osc1Shape]
    }
    else if (sliderThatWasMoved == osc1Gain)
    {
        //[UserSliderCode_osc1Gain] -- add your slider handling code here..
      processor.guiToOSC (4,sliderThatWasMoved->getValue ());
        //[/UserSliderCode_osc1Gain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
  String content;
  String newContent;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
      for (int i = 0; i < 256; i++)
	{
	  for (int message = 0; message < 4; message++)
	    {
	      char temp[25];
	      sprintf (temp, "%d", processor.noteOnMessage[message][i]);
	      newContent = temp;
	    }
	}

      content.append (newContent, 25);
      
      Console->setText (content);
      
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="NewProjectAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="5" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="757e225442717ed8" memberName="osc1Pitch"
          virtualName="" explicitFocusOrder="0" pos="25 25 75 75" min="-24"
          max="24" int="1" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="55f85e1e6f639b9c" memberName="osc1PulseWidth"
          virtualName="" explicitFocusOrder="0" pos="115 25 75 75" min="0.10000000000000000555"
          max="0.9000000000000000222" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="14d6e36a3c68c36c" memberName="osc1Shape"
          virtualName="" explicitFocusOrder="0" pos="205 25 75 75" min="0"
          max="4" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="4e9da2e738d73a06" memberName="osc1Gain"
          virtualName="" explicitFocusOrder="0" pos="295 25 75 75" min="0"
          max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTEDITOR name="new text editor" id="2808e95e908bbc05" memberName="Console"
              virtualName="" explicitFocusOrder="0" pos="7 196 200 200" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="ee8d903a23f46faa" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="10 165 195 24" buttonText="scan Midi Messages"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
