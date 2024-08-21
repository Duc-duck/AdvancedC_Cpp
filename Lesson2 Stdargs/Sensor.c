#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum {
    OPEN_DOOR,
    LOCK_DOOR

} SmartHome;

void command(SmartHome type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case LOCK_DOOR: {
            char* door_id = va_arg(args,char*);
            bool permission = va_arg(args,int);          
            if(!permission)
                printf("NO LOCK PERMISSION FOR %s\n", door_id);
            else
                printf("%s LOCKED...\n", door_id);
            break;
        }
        case OPEN_DOOR: {
            char* door_id = va_arg(args,char*);
            if(va_arg(args,char*) != "TYPE PASSWORD")
                printf("WRONG PASSWORD, %s CAN'T OPEN", door_id);
            else 
                {
                    bool state = va_arg(args,int);
                    switch(state)
                    {
                        case true:
                        {
                            printf("%s OPENED \n", door_id);
                            break;
                        }
                        case false:
                        {
                            printf("%s OPEN FAILED \n", door_id);
                            break;
                        }
                    }
                }
            break;
        }
    }
    va_end(args);
}

int main() {
    bool state = false;
    command(LOCK_DOOR,"Main entrance", true);
    command(OPEN_DOOR,"Main entrance", "TYPE PASSWORDs", state);
    return 0;
}