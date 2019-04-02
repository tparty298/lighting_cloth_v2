#include "ofApp.h"


int tmp=-1;
//--------------------------------------------------------------
void ofApp::setup(){
    //GUI
    ofBackground(0,0,0);
    // 描画系設定
    //ofSetVerticalSync(true);
    //ofSetFrameRate(60);
    // シリアル通信
    serialArduino.listDevices();
    //serialArduino.setup(0, 9600);
    //serialArduino.setup("/dev/tty.usbmodem14441", 9600);
    if(!serialArduino.setup(1, 9600)) {
        // log and error and leave
        ofLogError() << "could not open serial port - listing serial devices";
        serialArduino.listDevices();
        OF_EXIT_APP(0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //Arduinoにフレームの始まりを伝える

    serialArduino.writeByte(Byte(255));
    serialArduino.writeByte(Byte(50));//r
    serialArduino.writeByte(Byte(254));
    serialArduino.writeByte(Byte(250));//g
    serialArduino.writeByte(Byte(253));
    serialArduino.writeByte(Byte(100));//b
    
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
