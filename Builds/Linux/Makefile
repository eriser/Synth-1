# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
BINDIR := build
LIBDIR := build
OBJDIR := build/intermediate/Debug
OUTDIR := build

ifeq ($(TARGET_ARCH),)
TARGET_ARCH := -march=native
endif

CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "HASNOEDITOR" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
CXXFLAGS += $(CFLAGS)
LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
LDDEPS :=
RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
TARGET := NewProject.so
BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
BINDIR := build
LIBDIR := build
OBJDIR := build/intermediate/Release
OUTDIR := build

ifeq ($(TARGET_ARCH),)
TARGET_ARCH := -march=native
endif

CPPFLAGS := $(DEPFLAGS) -std=c++11 -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -Os
CXXFLAGS += $(CFLAGS)
LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lGL -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt 
LDDEPS :=
RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "HASNOEDITOR" -D "JUCER_LINUX_MAKE_7346DA2A=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ~/SDKs/vstsdk2.4 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
TARGET := NewProject.so
BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
$(OBJDIR)/ThreadedImageComputer_a5caf0ce.o \
$(OBJDIR)/Granular_ab0ef9e9.o \
$(OBJDIR)/Envelope_2c60e259.o \
$(OBJDIR)/Oscillator_8a6cfe29.o \
$(OBJDIR)/Filter_cccb6f01.o \
$(OBJDIR)/Noise_da98d57b.o \
$(OBJDIR)/Delay_82360b64.o \
$(OBJDIR)/GUI_f2fe7e1c.o \
$(OBJDIR)/PluginProcessor_a059e380.o \
$(OBJDIR)/dRowAudio_6123b5ea.o \
$(OBJDIR)/juce_audio_basics_2442e4ea.o \
$(OBJDIR)/juce_audio_devices_a4c8a728.o \
$(OBJDIR)/juce_audio_formats_d349f0c8.o \
$(OBJDIR)/juce_audio_processors_44a134a2.o \
$(OBJDIR)/juce_audio_utils_f63b12e8.o \
$(OBJDIR)/juce_core_aff681cc.o \
$(OBJDIR)/juce_cryptography_25c7e826.o \
$(OBJDIR)/juce_data_structures_bdd6d488.o \
$(OBJDIR)/juce_events_79b2840.o \
$(OBJDIR)/juce_graphics_c8f1e7a4.o \
$(OBJDIR)/juce_gui_basics_a630dd20.o \
$(OBJDIR)/juce_gui_extra_7767d6a8.o \
$(OBJDIR)/juce_opengl_c7e3506c.o \
$(OBJDIR)/juce_PluginUtilities_e2e19a34.o \
$(OBJDIR)/juce_video_184321c8.o \
$(OBJDIR)/juce_VST_Wrapper_bb62e93d.o \
$(OBJDIR)/juce_VST3_Wrapper_77e7c73b.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
@echo Linking Synth
-@mkdir -p $(BINDIR)
-@mkdir -p $(LIBDIR)
-@mkdir -p $(OUTDIR)
@$(BLDCMD)

clean:
@echo Cleaning Synth
@$(CLEANCMD)

strip:
@echo Stripping Synth
-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/ThreadedImageComputer_a5caf0ce.o: ../../Source/ThreadedImageComputer.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling ThreadedImageComputer.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Granular_ab0ef9e9.o: ../../Source/Granular.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Granular.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Envelope_2c60e259.o: ../../Source/Envelope.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Envelope.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Oscillator_8a6cfe29.o: ../../Source/Oscillator.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Oscillator.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Filter_cccb6f01.o: ../../Source/Filter.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Filter.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Noise_da98d57b.o: ../../Source/Noise.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Noise.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Delay_82360b64.o: ../../Source/Delay.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling Delay.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/GUI_f2fe7e1c.o: ../../Source/GUI.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling GUI.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling PluginProcessor.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/dRowAudio_6123b5ea.o: ../../JuceLibraryCode/modules/dRowAudio/dRowAudio.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling dRowAudio.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_2442e4ea.o: ../../JuceLibraryCode/modules/juce_audio_basics/juce_audio_basics.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_audio_basics.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_a4c8a728.o: ../../JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_audio_devices.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_d349f0c8.o: ../../JuceLibraryCode/modules/juce_audio_formats/juce_audio_formats.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_audio_formats.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_44a134a2.o: ../../JuceLibraryCode/modules/juce_audio_processors/juce_audio_processors.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_audio_processors.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_utils_f63b12e8.o: ../../JuceLibraryCode/modules/juce_audio_utils/juce_audio_utils.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_audio_utils.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_aff681cc.o: ../../JuceLibraryCode/modules/juce_core/juce_core.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_core.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_cryptography_25c7e826.o: ../../JuceLibraryCode/modules/juce_cryptography/juce_cryptography.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_cryptography.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_bdd6d488.o: ../../JuceLibraryCode/modules/juce_data_structures/juce_data_structures.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_data_structures.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_79b2840.o: ../../JuceLibraryCode/modules/juce_events/juce_events.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_events.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_c8f1e7a4.o: ../../JuceLibraryCode/modules/juce_graphics/juce_graphics.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_graphics.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_a630dd20.o: ../../JuceLibraryCode/modules/juce_gui_basics/juce_gui_basics.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_gui_basics.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_7767d6a8.o: ../../JuceLibraryCode/modules/juce_gui_extra/juce_gui_extra.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_gui_extra.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_opengl_c7e3506c.o: ../../JuceLibraryCode/modules/juce_opengl/juce_opengl.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_opengl.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_e2e19a34.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_PluginUtilities.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_video_184321c8.o: ../../JuceLibraryCode/modules/juce_video/juce_video.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_video.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_bb62e93d.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_VST_Wrapper.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST3_Wrapper_77e7c73b.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST3/juce_VST3_Wrapper.cpp
-@mkdir -p $(OBJDIR)
@echo "Compiling juce_VST3_Wrapper.cpp"
@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
