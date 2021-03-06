// overview.c
// by Lonely

#pragma save_binary

inherit F_CLEAN_UP;

#define MAX            10000

int main(object me, string arg)
{
        object *ob;
        int i, m, mem;
        string msg;

        mem = 0;
        msg = "";
        
        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;
        
        switch (arg) 
        {
        case "living":
                ob = livings();
                printf("共有 %d 个生物(含使用者)物件　\n", sizeof(ob));
                
                for (i = 0; i < sizeof(ob); i++)
                {
                        reset_eval_cost();  
                        if (! environment(ob[i]))
                        {
                                m = memory_info(ob[i]);
                                mem += m;
                                if (m > MAX)
                                msg += file_name(ob[i]) + "@@@" + m + "\n";
                        }       
                }
               
                write_file("/u/lonely/living.txt", msg);
                break;

        case "object":
                ob = objects();
                printf("共有 %d 个物件被载入　\n", sizeof(ob));
                        
                for (i = 0; i < sizeof(ob); i++)
                {
                        reset_eval_cost();
                        if (! environment(ob[i]))
                        {
                                m = memory_info(ob[i]);
                                mem += m;
                                if (m > MAX)
                                msg += file_name(ob[i]) + "@@@" + m + "\n";
                        } 
                }
                write_file("/u/lonely/object.txt", msg);
                break;
        default:
                return notify_fail("指令格式：overview <topic>\n");
        }
        printf("总共使用 %d bytes 记忆体　\n", mem); 
        return 1;
}

int help()
{
        write(@TEXT
指令格式：overview <主题>

TEXT
        
        );
        return 1;
}
