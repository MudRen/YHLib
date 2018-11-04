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
                printf("���� %d ������(��ʹ����)�����\n", sizeof(ob));
                
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
                printf("���� %d ����������롡\n", sizeof(ob));
                        
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
                return notify_fail("ָ���ʽ��overview <topic>\n");
        }
        printf("�ܹ�ʹ�� %d bytes �����塡\n", mem); 
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��overview <����>

TEXT
        
        );
        return 1;
}
