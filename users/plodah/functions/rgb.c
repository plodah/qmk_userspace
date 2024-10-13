#pragma once

HSV plodah_rgblimit(HSV currenthsv, HSV targethsv, uint8_t minval){
  HSV output = targethsv;
  if(minval > currenthsv.v){
    output.v = minval;
  }
  else if(targethsv.v > currenthsv.v ){
    output.v = currenthsv.v;
  }
  return output;
}
