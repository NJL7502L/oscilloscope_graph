#include <Arduino.h>
#include "parameter.h"

class Vect{
public:
  double x;
  double y;
};

Vect targetPoint[] = {
  {0    ,0.5  },
  {0.1  ,0.5  },
  {0.1  ,0.6  },
  {0.2  ,0.6  },
  {0.2  ,0.4  },
  {0.25 ,0.5  },
  {0.6  ,0.5  },
  {0.6  ,0    },
  {0.65 ,0.5  },
  {0.7  ,0.5  },
  {0.7  ,0.6  },
  {0.85 ,0.7  },
  {0.85 ,0.8  },
  {0.95 ,0.9  },
  {1    ,1    }
};

void setup() {
  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
  analogWrite(LED_BUILTIN,OUTPUT);
}

void plot(float x,float y){
  float outX = map(x*100,100,0,0,255);
  float outY = map(y*100,100,0,0,255);
  analogWrite(pinX,outX);
  analogWrite(pinY,outY);
}

void loop() {
  double dist = 0;
  double pointer = 0;

  for(int i = 0; i < sizeof(targetPoint) / sizeof(targetPoint[0]); i++){

    Vect diff;
    diff.x = targetPoint[i+1].x - targetPoint[i].x;
    diff.y = targetPoint[i+1].y - targetPoint[i].y;
    double a;
    if(diff.x == 0){
      if(diff.y > 0){
        a = 100000;
      }else if(diff.y < 0){
        a = -100000;
      }else{
        a = 0;
      }

    }else{
      a = diff.y/diff.x;
    }
    double theta = atan(a);
    dist += hypot(diff.x, diff.y);

    Vect movingPointer;
    movingPointer.x = targetPoint[i].x;
    movingPointer.y = targetPoint[i].y;

    while(pointer < dist){
      plot(movingPointer.x,movingPointer.y);
      
      movingPointer.x += 0.01 * cos(theta);
      movingPointer.y += 0.01 * sin(theta);
      pointer += 0.01;
      delay(500);
    }
  }
}
