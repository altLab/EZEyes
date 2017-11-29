// Reference math functions http://sol.gfYile.net/interpolation/

//Declare Vars and Import Libs
float N, v, Y, A, B;



//Runs once
void setup() 
  {
    size(600 , 500);
    noLoop();
    
    N = 10;     // number of samples
    A = 0;      // Origin Value
    B = 2000;    // Destination value
    int Nray = int(N)+1;
    
    String[] SQR = new String[Nray];
    String[] LIN = new String[Nray];
    String[] INVSQR = new String[Nray];
    
    // flip Y axis so the positive values are facing upwards on the screen
    pushMatrix(); // push & pop Matrix makes the changes affect only the graphics printed on screen up utill pop
    scale(1, -1);
    translate(0,-height);
    
    for (int i = 0; i <= N; i++)
    {
      v = i / N;
      v = v * v;
      Y = (B * v) + (A * (1 - v));
      
      float PY = i * (width/N);
      float Py = height * (Y/B);
      float Pw = 5;
      float Ph = 5;
      
      fill(255,0,0);
      ellipse( 200, Py , Pw, Ph);
      String number = nfs(int(Y),1);
      SQR[i] = number;
    } 
    println(SQR);
    
    for (int i = 0; i <= N; i++)
    {
      v = i / N;
      Y = (B * v) + (A * (1 - v));
      
      float PY = i * (width/N);
      float Py = height * (Y/B);
      float Pw = 5;
      float Ph = 5;
      
      fill(0,200,0);
      ellipse( 300, Py , Pw, Ph);
      String number = nfs(int(Y),1);
      LIN[i] = number;
    } 
    
    println(LIN);
    
    for (int i = 0; i <= N; i++)
    {
      v = i / N;
      v = 1 - (1 - v) * (1 - v);
      Y = (B * v) + (A * (1 - v));
      
      float PY = i * (width/N);
      float Py = height * (Y/B);
      float Pw = 5;
      float Ph = 5;
      
      fill(0,0,255);
      ellipse( 400, Py , Pw, Ph);
      String number = nfs(int(Y),1);
      INVSQR[i] = number;
    } 
     popMatrix();
    
    println(INVSQR);
    fill(255);
    
    String strSQR = join(SQR, "\n");
    String strLIN = join(LIN, "\n");
    String strINVSQR = join(INVSQR, "\n");
    
    text(strSQR, 210, 210);
    text(strLIN, 310, 210);
    text(strINVSQR, 410, 210);
    
}

  
//Loops by default @ 60fps
void draw()
  {
  }