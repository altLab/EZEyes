
// define sensor points
PVector l1, l1_mouseP, mouseP;
float l1_mdist, l1_angle, l2_mdist;



void setup() {
  size(600, 500, P2D);
  smooth();
  
  textAlign(CENTER);
 
  l1 = new PVector(width/2 - 5, height-10);
  mouseP = new PVector(mouseX, mouseY);
  
}

void draw() {
 
 background(127);
 rect(0,0,width-1,height-1);
 noFill();
 textSize(20);
 
 point(l1.x,l1.y);
  
 mouseP.set(mouseX, mouseY);
   
 l1_mdist = dist(l1.x, l1.y, mouseX, mouseY);
 l1_mouseP = PVector.sub(l1, mouseP);
 l1_angle = degrees(l1_mouseP.heading())-90; 
 
 line(l1.x,l1.y,mouseP.x, mouseP.y);
 stroke(0, 255, 0);
  
  if (l1_angle < -25 || l1_angle > 25 || l1_mdist > 400){
    
   stroke(255, 0, 0);
   
    if (l1_angle < -25 || l1_angle > 25){
       text("Out of Bounds", width/2, height/2);
    }
    if (l1_mdist > 400){
       text("Sensor Maxed Out", width/2, height/2-30);
    }
   } else {
 text(int(l1_mdist*5), mouseX, mouseY-40);
 text(l1_angle, mouseX, mouseY-10);
 }

}

// Calculating angles > https://forum.processing.org/one/topic/calculating-angles.html