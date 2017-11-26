// Reference math functions http://sol.gfxile.net/interpolation/

//Declare Vars and Import Libs
float N, v, X, A, B;


//Runs once
void setup() 
  {
    size(400 , 400);
    noLoop();
    
    N = 10;
    B = 0;
    A = 400;
    
    
    for (int i = 0; i < N; i++)
    {
      v = i / N;
      v = v * v;
      X = (A * v) + (B * (1 - v));
      println(X);
      fill(255,0,0);
      ellipse(i * (width/N),height-X, 5, 5);
    } 
    
    for (int i = 0; i < N; i++)
    {
      v = i / N;
      X = (A * v) + (B * (1 - v));
      fill(0,255,0);
      println(X);
      ellipse(i * (width/N),height-X, 5, 5);
    } 
    
    for (int i = 0; i < N; i++)
    {
      v = i / N;
      v = 1 - (1 - v) * (1 - v);
      X = (A * v) + (B * (1 - v));
      fill(0,0,255);
      ellipse(i * (width/N),height-X, 5, 5);
    } 

  }
  
//Loops by default @ 60fps
void draw()
  {

  
  }
  