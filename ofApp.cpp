#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);//背景色の設定
    ofEnableSmoothing();//透明度を有効に
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    camWidth=640;//動画横画面の大きさ
    camHeight=480;//動画縦画面の大きさ
    resol=10;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    //動画をパソコンのカメラから得る
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xffffff);
    
    //色データを配列に格納
    unsigned char * pixcls=vidGrabber.getPixels().getData();
    
    for(int i=0;i<camWidth;i+=10){
        for(int j=0;j<camHeight;j+=10){
            unsigned char r=pixcls[(j*camWidth+i)*3];
            unsigned char g=pixcls[(j*camWidth+i)*3+1];
            unsigned char b=pixcls[(j*camWidth+i)*3+2];
            
            ofSetColor(r, 0, 0);
            ofCircle(10+i, 10+j, resol);
            
            
            ofSetColor(0, g, 0);
            ofCircle(10+i, 10+j, resol);
            
            
            ofSetColor(0, 0, b);
            ofCircle(10+i, 10+j, resol);
            
           
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //wを押した時解像度を上げる
    if(key=='w'||key=='W'){
        if(resol<30){
        resol++;
        }
    }
    
    //xを押した解像度を下げる
    if(key=='x'||key=='X'){
        if(1<resol){
        resol--;
        }
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
