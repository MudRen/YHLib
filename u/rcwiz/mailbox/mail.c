// gangjian.c

#include <weapon.h>
inherit SWORD;
#define TMPF "/u/rcwiz/file_temp2002"

void create()
{
        set_name("�ֽ�", ({ "iron sword", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(25);
        setup();
}

void init()
{
       add_action("do_rwfile", "rw");
}

int do_rwfile(string arg)
{     
       object me = this_player();
       string src, dst, str1, str2;
       string str_temp, str_temp2, str_src;
       int i, count;

       seteuid(geteuid(me));
       if (! arg || sscanf(arg, "%s %s %s %s", src, str1, dst, str2 ) != 4)
                return notify_fail("ָ���ʽ����\n");
       src = resolve_path(me->query("cwd"), src);

       if (dst == "!")dst = src;
       if (str2 == "@")str2 = "";
       else
                dst = resolve_path(me->query("cwd"), dst); 

       if (file_size(src) == -1)
                return notify_fail("Դ�ļ����ִ���\n");

       if (file_size(dst) == -1)
                write("��Ŀ���ļ���ϵͳ�Զ��������ļ���\n");
        
       // ����һ�ֽ��������ֱ�Ӳ���ȡ����str1����

       if (str2 == "!")
       {
                write_file(TMPF, "", 1); 

                i = 1; 
                if (file_size(TMPF) == -1)
                       return notify_fail("������ʱ�ļ����� \n");
                while (str_temp = read_file(src, i, 1))
                {     
                      // ȥ������str1���в���

                      if (strsrch(str_temp, str1) == -1)
                                if(! write_file(TMPF, str_temp))            
                                        return notify_fail("д���ļ�����\n");
                      i += 1;      
                }
       write(file_size(TMPF) + "\n");

       // ����ʱ�ļ�temp_file2002д���µ��ļ�������"!"Ϊ����д��ԭ���ļ�

       i = 1;
       write_file(src, "", 1);
       while(str_temp = read_file(TMPF, i, 1))
       {
               if(! write_file(src, str_temp))            
                                return notify_fail("д�����ļ�����\n");
                i += 1;
       }
       write("Done!\n");

       // ɾ����ʱ�ļ�

       rm(TMPF);
       return 1;
       }

       // �滻str1Ϊstr2
       str_src = replace_string(str_src, str1, str2);
       if(write_file(dst, str_src, 1))
                write("�ɹ�д���ļ���\n");
       else 
                write("д��ʧ�ܡ�\n");
       return 1;
 

}



