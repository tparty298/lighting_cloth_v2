#include "ofApp.h"


int tmp=-1;
//--------------------------------------------------------------
void ofApp::setup(){
    //音関連
    fft.setup(pow(2.0,12.0));
    //画像関連
    TParty.load("images/TParty.png");
    cloth.load("images/cloth.png");
    cloth_image_positon.set(300,50);//cloth.pngの位置
    cloth_image_size.set(350,350*cloth_image_aspect_ratio);//cloth.pngのサイズ
    //GUI
    ofBackground(0,0,0);
    gui.setup();
    gui.add(hue_first.setup("hue_first",0,0,360));
    gui.add(hue_second.setup("hue_second",240,0,360));
    gui.add(sound_volume_ratio.setup("sound ratio",1,0,1));
    fft_draw_size.set(400,200);
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
    //音関連////////////////////////
    fft.update();
    ///////////////////////////////
    
    //色の値/////////////////////////デフォルトではhue_firstを送る
    hue_first_send=ofMap(hue_first,0,360,1,100);
    hue_second_send=ofMap(hue_second,0,360,101,200);
    ////////////////////////////////
    
    
    
    //モードについて////////////////////
    //mode=205;
    /////////////////////////////////
    
    
    
    //モードを戻す/これはupdateの最後////
    
    ////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::draw(){
    //音関連///////////////////////////
    vector<float> buffer;
    buffer=fft.getBins();
    ofNoFill();
    ofSetLineWidth(2.0);
    ofBeginShape();
    for(int i=0;i<buffer.size();i++){
        buffer[i]*=sound_volume_ratio;
        float x=ofMap(i,0,buffer.size(),0,ofGetWidth());
        float y=ofMap(buffer[i],0,1,ofGetHeight(),0);
        ofVertex(x, y);
    }
    ofEndShape();
    ///////////////////////////////////
    
    //シリアル通信////////////////////
    serialArduino.writeByte(Byte(hue_first_send));//hue//serialArduino.writeByte(Byte(hue_send));
    serialArduino.writeByte(Byte(hue_second_send));
    serialArduino.writeByte(Byte(mode));//serialArduino.writeByte(Byte(mode));
    std::cout<<hue_first_send<<" "<<hue_second_send<<" "<<mode<<std::endl;
    ////////////////////////////////
    
    //GUI/////////////////////////////
    TParty.draw(1025,25,150,120);
    cloth.draw(cloth_image_positon.x,cloth_image_positon.y,cloth_image_size.x,cloth_image_size.y);
    gui.draw();//これはGUIの最後に
    ///////////////////////////////////
    
    
    //余計だけど入れるところ/////////////
    string msg = ofToString((int) ofGetFrameRate()) + " fps";
    ofDrawBitmapString(msg, ofGetWidth() - 80, ofGetHeight() - 20);
    /////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key){
        case 'z':
            mode=201;
            break;
        case 'x':
            mode=202;
            break;
        case 'k':
            mode=203;
            break;
        case 'l':
            mode=204;
            break;
        case 'o':
            mode=205;
            break;
        case 'p':
            mode=206;
            break;
    }
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
