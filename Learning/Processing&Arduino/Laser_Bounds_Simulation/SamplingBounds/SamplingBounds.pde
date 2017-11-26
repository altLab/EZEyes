// Reference math functions http://sol.gfYile.net/interpolation/

//Declare Vars and Import Libs
float N, v, Y, A, B;


//Runs once
void setup() 
  {
    size(600 , 500);
    noLoop();
    
    // flip Y axis so the positive values are facing upwards on the screen
    scale(1, -1);
    translate(0,-height);
    
    N = 10;     // number of samples
    A = 0;      // Origin Value
    B = 2000;    // Destination value

    
    
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
      println("SQR " + Y);
    } 
    
    for (int i = 0; i <= N; i++)
    {
      v = i / N;
      Y = (B * v) + (A * (1 - v));
      
      float PY = i * (width/N);
      float Py = height * (Y/B);
      float Pw = 5;
      float Ph = 5;
      
      fill(0,255,0);
      ellipse( 300, Py , Pw, Ph);
      println("LIN " + Y);
  } 
    
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
      println("INVSQR " + Y);
  } 

  }
  
//Loops by default @ 60fps
void draw()
  {

  
  }
  