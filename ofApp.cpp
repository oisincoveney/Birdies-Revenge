#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	mode = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (mode)
	{
	case 0: //start screen
		mode = m.display();
		break;
	case 1: //play
		mode = g.display();
		break;
	case 2:
		mode = p.display();
		break;
	case 3: //end
		mode = e.display();
		g.reset();
		break;
	case 4: //credits
		mode = c.display();
		break;
	case 5: //tutorial
		mode = t.display();
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (mode)
	{
	case 0: //start screen
		m.setKey(key);
		break;
	case 1: //play
		g.setKey(key);
		break;
	case 2: //pause
		p.setKey(key);
		break;
	case 3: //end
		e.setKey(key);
		break;
	case 5: //tutorial
		t.setKey(key);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	if (mode == 1) {
		g.setMouseX(x);
		g.setMouseY(y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	switch (mode)
	{
	case 0: //start screen
		m.setMouseX(x);
		m.setMouseY(y);
		break;
	case 1: //play
		g.playerShoot();
		break;
	case 2: //pause
		p.setMouseX(x);
		p.setMouseY(y);
		break;
	case 3: //end
		e.setMouseX(x);
		e.setMouseY(y);
		break;
	case 4: //credits
		c.setMouseX(x);
		c.setMouseY(y);
		break;
	case 5: //tutorial
		t.setMouseX(x);
		t.setMouseY(y);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}