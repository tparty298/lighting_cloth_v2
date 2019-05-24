#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxEasyFft.h"
#include "ofxOsc.h"

using namespace std;

#define NUM_LED 296

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        //ofSerial serialArduino; // Arduinoのシリアル通信用
        ofSerial serialArduino[3];//複数台の時
    
    
        //音関連//////////////////////
        ofxEasyFft fft;
        float buffer_sum=0;
        float sound_volume_0to1;
        int sound_volume_500=500;
        bool using_volume=false;
        float frequency_volume_max=0;
        float frequency_volume_max_volume=0;
        float frequency_volume_max_ten_average_array[10]={0,0,0,0,0,0,0,0,0,0};
        float frequency_volume_max_ten_average=0;
        /////////////////////////////
    
        //GUI関係の変数////////////////
        ofxPanel gui;
        ofxIntSlider hue_first;
        ofxIntSlider hue_second;
        ofxFloatSlider sound_volume_ratio;
        ofxFloatSlider sound_volume_min;
        ofxFloatSlider sound_volume_max;
        ofxIntSlider value;
        ofxIntSlider LowPass;
        ofxIntSlider HighPass;
        ofxFloatSlider s_r_attenu;
        ofxIntSlider s_r_multi;
        ofxIntSlider fft_hue_min;
        ofxIntSlider fft_hue_max;
        int fft_hue=1;
        ofImage TParty;
        ofImage cloth;
        ofVec2f cloth_image_positon;
        ofVec2f cloth_image_size;
        double cloth_image_aspect_ratio=1.3424;
        ofVec2f fft_draw_size;
        ofxButton using_volume_button;
        ofxButton using_fft_hue_button;
        ofTrueTypeFont mic_on_or_off;
        ofTrueTypeFont fft_hue_on_or_off;
        /////////////////////////////
    
        //色関係の変数/////////////////
        int hue_send=1;
        int hue_first_send=1;
        int hue_second_send=101;
        int hue_first_send_change_flag=0;
        int hue_second_send_change_flag=0;
        bool using_fft_hue=false;
        int send_fft_hue=1;
        /////////////////////////////
    
        //モードのついての変数///////////
        int mode=201;
        int mode_change_flag=0;
        int bool_volume=0;
    
        ////////////////////////////
    
        //OSC/////////////////////
        ofxOscReceiver  receiver;
        void OSCrecv();
        float osc_in[6]; //brightness, hue1, hue2, volume_min, volume_max, sound_ratio
        string mode_switch[9];
        string mode_volume;
        //////////////////////////
};
