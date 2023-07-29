#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 100;
	for (int x = -200; x <= 200; x += 400) {

		for (int y = -200; y <= 200; y += 400) {

			auto deg_param = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -360, 360);
			for (int deg = 0; deg < 360; deg += 15) {

				auto location_1 = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				auto location_2 = glm::vec2(x + radius * cos((deg + deg_param) * DEG_TO_RAD), y + radius * sin((deg + deg_param) * DEG_TO_RAD));

				ofDrawCircle(location_1, 2.5);
				ofDrawCircle(location_2, 2.5);
				ofDrawLine(location_1, location_2);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}