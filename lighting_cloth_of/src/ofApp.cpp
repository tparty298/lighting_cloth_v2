#include "ofApp.h"
#define RECIEVE_PORT 8000

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
    gui.add(value.setup("value",240,221,240));
    gui.add(sound_volume_ratio.setup("sound ratio",1,0,1));
    gui.add(sound_volume_min.setup("sound_volume_min",10,0,sound_volume_500));
    gui.add(sound_volume_max.setup("sound_volume_max",300,0,sound_volume_500));
    fft_draw_size.set(400,200);
    // 描画系設定
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    
    // シリアル通信
    //単数の時
    /*
    serialArduino.listDevices();
    if(!serialArduino.setup(1, 9600)) {
        // log and error and leave
        ofLogError() << "could not open serial port - listing serial devices";
        serialArduino.listDevices();
        OF_EXIT_APP(0);
    }
     */
    //複数の時
    serialArduino[0].listDevices();
    if(!serialArduino[0].setup(5, 9600)) {
        // log and error and leave
        ofLogError() << "0: could not open serial port - listing serial devices";
        //serialArduino1.listDevices();
        OF_EXIT_APP(0);
    }
    if(!serialArduino[1].setup(1, 9600)) {
        // log and error and leave
        ofLogError() << "1: could not open serial port - listing serial devices";
        //serialArduino2.listDevices();
        OF_EXIT_APP(0);
    }
    if(!serialArduino[2].setup(3, 9600)) {
        // log and error and leave
        ofLogError() << "2: could not open serial port - listing serial devices";
        //serialArduino3.listDevices();
        OF_EXIT_APP(0);
    }
    
    
    
    
    
    //色設定
    
    //OSC
    receiver.setup(RECIEVE_PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    //OSC/////////////////////////
    ////////////ここからOSCendまでコメントアウトするとGUIでも使えるようになる
    
    OSCrecv();
    hue_first=osc_in[1]*360;
    hue_second=osc_in[2]*360;
    value=ofMap(osc_in[0],0,1,221,240);
    if(mode_switch[0]=="bang"){
        mode=205;
    }
    if(mode_switch[1]=="bang"){
        mode=206;
    }
    if(mode_switch[2]=="bang"){
        mode=203;
    }
    if(mode_switch[3]=="bang"){
        mode=204;
    }
    if(mode_switch[3]=="bang"){
        mode=204;
    }
    if(mode_switch[4]=="bang"){
        mode=208;
    }
    if(mode_switch[5]=="bang"){
        mode=209;
    }
    if(mode_switch[6]=="bang"){
        mode=207;
    }
    
    /////////////////OSCend ここまでコメントアウトするとGUIから使えるようになる
    //////////////////////////////
    
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
    
    //OSC戻す
    for(int i=0;i<7;i++){
        mode_switch[i]=" ";
    }
    mode_volume=" ";
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
        buffer_sum+=buffer[i];
        float x=ofMap(i,0,buffer.size(),0,ofGetWidth());
        float y=ofMap(buffer[i],0,1,ofGetHeight(),0);
        ofVertex(x, y/3+ofGetHeight()-300);
    }
    ofEndShape();
    sound_volume_0to1=ofMap(buffer_sum,0,sound_volume_max,0,1);
    if(sound_volume_0to1>=1){
        sound_volume_0to1=1;
    }
    ofDrawBitmapString(sound_volume_0to1,200,200);//音量の表示
    ofDrawBitmapString(mode,200,500);
    ///////////////////////////////////
    
    //シリアル通信////////////////////
    //単数の時
    /*
    serialArduino.writeByte(Byte(hue_first_send));//hue//serialArduino.writeByte(Byte(hue_send));
    serialArduino.writeByte(Byte(hue_second_send));
    serialArduino.writeByte(Byte(mode));//serialArduino.writeByte(Byte(mode));
    serialArduino.writeByte(Byte(value));
    */
    //複数の時
    for(int i=0;i<3;i++){
        serialArduino[i].writeByte(Byte(hue_first_send));//hue//serialArduino.writeByte(Byte(hue_send));
        serialArduino[i].writeByte(Byte(hue_second_send));
        serialArduino[i].writeByte(Byte(mode));//serialArduino.writeByte(Byte(mode));
        serialArduino[i].writeByte(Byte(value));
    }
    //std::cout<<hue_first_send<<" "<<hue_second_send<<" "<<mode<<std::endl;
    ////////////////////////////////
    
    //GUI/////////////////////////////
    TParty.draw(1025,25,150,120);
    cloth.draw(cloth_image_positon.x,cloth_image_positon.y,cloth_image_size.x,cloth_image_size.y);
    gui.draw();//これはGUIの最後に
    ///////////////////////////////////
    
    
    //余計だけど入れるところ/////////////
    string msg = ofToString((int) ofGetFrameRate()) + " fps";
    ofDrawBitmapString(msg, ofGetWidth() - 80, ofGetHeight() - 20);
    //////////////////////////////////
    
    //変数の0化
    buffer_sum=0;
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
        case 'q':
            mode=207;
            break;
        case 'w':
            mode=208;
            break;
        case 'e':
            mode=209;
            break;
        case 'c':
            mode=210;
            break;
        default:
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

void ofApp::OSCrecv(){
    
    while( receiver.hasWaitingMessages() )
    {
        
        ofxOscMessage m;
        
        receiver.getNextMessage( &m );
        
        //OSC message setting
        if ( m.getAddress() == "/brightness" ){
            osc_in[0] = m.getArgAsFloat(0);
        }else if( m.getAddress() == "/hue1"){
            osc_in[1] = m.getArgAsFloat(0);
        }else if( m.getAddress() == "/hue2"){
            osc_in[2] = m.getArgAsFloat(0);
        }else if(m.getAddress() == "/switch_hue1"){
            mode_switch[0] = m.getArgAsString(0);
        }else if(m.getAddress() == "/switch_hue2"){
            mode_switch[1] = m.getArgAsString(0);
        }else if(m.getAddress() == "/k"){
            mode_switch[2] = m.getArgAsString(0);
        }else if(m.getAddress() == "/l"){
            mode_switch[3] = m.getArgAsString(0);
        }else if(m.getAddress() == "/w"){
            mode_switch[4] = m.getArgAsString(0);
        }else if(m.getAddress() == "/e"){
            mode_switch[5] = m.getArgAsString(0);
        }else if(m.getAddress() == "/q"){
            mode_switch[6] = m.getArgAsString(0);
        }
    }
}


