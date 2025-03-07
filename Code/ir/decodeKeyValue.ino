String decodeKeyValue(long result)
{
  switch(result){
    case 0x16: return "0";
    case 0xC: return "1"; 
    case 0x18: return "2"; 
    case 0x5E: return "3"; 
    case 0x8: return "4"; 
    case 0x1C: return "5"; 
    case 0x5A: return "6"; 
    case 0x42: return "7"; 
    case 0x52: return "8"; 
    case 0x4A: return "9"; 
    case 0x9: return "+"; 
    case 0x15: return "-"; 
    case 0x7: return "EQ"; 
    case 0xD: return "U/SD";
    case 0x19: return "CYCLE";         
    case 0x44: return "PLAY/PAUSE";   
    case 0x43: return "FORWARD";   
    case 0x40: return "BACKWARD";   
    case 0x45: return "POWER";   
    case 0x47: return "MUTE";   
    case 0x46: return "MODE";       
    case 0x0: return "ERROR";   
    default: return "ERROR";
    }
}