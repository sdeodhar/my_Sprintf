#include <stdio.h> 
#include <stdarg.h>
#include <string.h> 

char *convert(unsigned int num, int base) 
{ 

	  static char Representation[]= "0123456789ABCDEF";
	  static char buffer[50]; 
	  char *ptr; 
  
	  ptr = &buffer[49]; 
	  *ptr = '\0'; 
  
	  do 
	  { 
		*--ptr = Representation[num%base]; 
		num /= base; 
	  }while(num != 0); 
  
  	  return(ptr); 
}


void sq_sprintf(char *buf, char const *fmt, ...)
{

  	char *traverse; 
  	int i; 
	char *s;
   
//Module 1: Initializing Myprintf's arguments 

	  va_list arg; 
	  va_start(arg, fmt);
 
//printf("start of sprintf\n");
 	 for(traverse = fmt; *traverse != '\0'; traverse++) 
  	 { 

  		  while( *traverse != '%' ) 
  		  { 
  			    *buf = *traverse;				//putchar(*traverse);
			    if(*traverse == '\0'){break;}
			    buf++;
  			    traverse++; 
  		  } 
    		  //buf++;

  		  if(*traverse == '\0'){break;} 
    		  traverse++;

  		  //Module 2: Fetching and executing arguments
		switch(*traverse) 
    		{ 
    			  case 'c' : i = va_arg(arg,int);    //Fetch char argument
        			    *buf = i;			     //putchar(i);  if writing printf
        			    break; 
            
    			  case 'd' : i = va_arg(arg,int);     //Fetch Decimal/Integer argument
        			    if(i<0) 
        			    { 
        			      i = -i;
        			      *buf = '-';	      //putchar('-'); if writing printf
				      buf++;
        			    } 
        			    s = convert(i,10);	      //puts(convert(i,10));if writing printf
				    while(*s != '\0')
				    { 
					*buf = *s; s++; buf++; 
				    }
				    //*buf = '\0';
        			    break; 
            
      			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
     				  s = convert(i,8);		//puts(convert(i,8));if writing printf
				  while(*s != '\0')
				  { 
					*buf = *s; s++; buf++; 
				  }
				    //*buf = '\0';
        			    break; 
            
			case 's': s = va_arg(arg,char *);     //Fetch string
        			    			      //puts(s); if writing printf
				  while(*s != '\0')
				  { 
					*buf = *s; s++;buf++; 
				  }
				    //*buf = '\0';
        			    break; 
            
		        case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
        			  s = convert(i,16);		//  puts(convert(i,16));if writing printf
				  while(*s != '\0')
				  { 
					*buf = *s; s++; buf++; 
				  }
				    //*buf = '\0';
            			  break;

			default: break; 
    		}  
  	} 
  *buf = '\0';
  	//Module 3: Closing argument list to necessary clean-up
	
	  va_end(arg); 
//printf("end of sprintf\n");

}

int main() 
{
	  char buf[256];

	  sq_sprintf(buf, "This is a simple test case.");
	  printf("%s\n", buf);
  	 
	  sq_sprintf(buf, "This is %s test case.", "string");
	  printf("%s\n", buf);
  
	  sq_sprintf(buf, "This has %s %s", "two", "strings");
	  printf("%s\n", buf);
  
	  sq_sprintf(buf, "%d + %d = %d", 25, -20, 5);
	  printf("%s\n", buf);

}
