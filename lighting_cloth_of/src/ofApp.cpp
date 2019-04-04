#include "ofApp.h"


int tmp=-1;
//--------------------------------------------------------------
void ofApp::setup(){
    //GUI
    ofBackground(0,0,0);
    gui.setup();
    gui.add(hue.setup("hue",30,0,36));
    // 描画系設定
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    // シリアル通信
    serialArduino.listDevices();
    if(!serialArduino.setup(1, 9600)) {
        // log and error and leave
        ofLogError() << "could not open serial port - listing serial devices";
        serialArduino.listDevices();
        OF_EXIT_APP(0);
    }
    //色設定
}

//--------------------------------------------------------------
void ofApp::update(){
    serialArduino.writeByte(Byte(hue));//hue
    std::cout<<hue<<std::endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
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
