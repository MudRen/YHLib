#include <ansi.h>
inherit ROOM;

       void create() 
       { 
                   set("short", HIY "\n\n�� �� �� �� �� ��" NOR);
                   set("long", HIG "�������׻ƻ�Ա�������ģ�ֻ������"
                               "���ܿ���������Զ��\n����ذڷ��źܶ�"
                               "�Զ��ۻ���(ASM)��\n" NOR
                   );
                   set("exits", ([
                          "out"  :  "/d/city/guangchang",
                   ]));

                   set("no_fight", 1); 
                   set("item_desc", ([ 
                          "asm"  :    "������Ļ����ʾ��" HIM + BLINK" �����(insert)��Ļ�Ա�� " NOR 
                                      "��������������\n�����Ÿ�����ֵİ�Ť��\n",
                   ]));

                   setup();     
       } 


void init()
{
        add_action("do_insert", "insert");
        add_action("do_pull", "pull");
        add_action("do_list", "list");
        add_action("do_buy", "want");
        
}
int do_insert(string arg)
{
        object me, ob;
        me = this_player();

        if (! arg || arg == "")
                return 0;

        if (arg == "card" || arg == "huiyuan card")
        {
                if (! ob = present("huiyuan card", me)) return 0;

                if (me->query("temp/insert"))
                        return notify_fail("����ûȡ��!\n");

                if (me->is_busy())
                {
                        return notify_fail("����æ���ء�\n");
                        return 1; 
                }
                destruct(ob);
                write(HIW "�㽫��Ƭ�����Զ��ۻ���...\n" NOR);
                write(HIY "�׻��Զ��ۻ������ڶ�ȡ�㿨�ϵ����ݣ����Ժ�...\n" NOR);
                me->set("temp/insert", 1);
                call_out("show", 4 + random(2));
                return 1;
        }
}

//���ݶ�ȡ��ϣ�������
int show()
{  
   int rmb;
   object me = this_player();
   rmb = this_player()->query("rmb");
   tell_object(me, HIC "��Ŀǰ�Ĵ��Ϊ" + chinese_number(rmb) + "Բ����ҡ�\n" NOR);
   write(HIG "���ݶ�ȡ�ɹ���������(list)��ʾ���Թ������Ʒ������(want)������Ʒ��\n" NOR);
   this_player()->set("temp/can_pull", 1);
     
   return 1; 
}

int do_list()
{
   string msg;
   if (! this_player()->query("temp/insert"))
   {
           write("���Ȳ����Ա����\n");
           return 1;
   }
  msg = HIC "�����ơ�                           \t�����á�            ���ɹ��ʡ�                ���۸�\n\n" NOR;
  msg +=HIG "������(Shenli wan)                     �����������            40%                    �� 2.00\n";
  msg +=HIG "�׻���Ԫ��(Baihu dan)                  �����������            70%                    �� 5.00\n";
  msg +=HIG "�����Ԫ�ɵ�(Zhuyuan xiandan)          �����������            85%                    ��10.00\n";
  msg +=HIW "���۵�(Zenghui dan)                    ������������            40%                    �� 2.00\n";
  msg +=HIW "�������(Qinglong dan)               ������������            70%                    �� 5.00\n";
  msg +=HIW "���ͨ���ɵ�(Tonghui xiandan)          ������������            85%                    ��10.00\n";
  msg +=HIY "���ٸ�(Fushou gao)                     ����������            40%                    �� 2.00\n";
  msg +=HIY "��ȸ���絤(Zhuque dan)                 ����������            70%                    �� 5.00\n";
  msg +=HIY "�����޼��ɵ�(Wuji xiandan)             ����������            85%                    ��10.00\n";
  msg +=HIR "׳�Ƿ�(Zhuanggu fen)                   �����������            40%                    �� 2.00\n";
  msg +=HIR "�������ǵ�(Xuanwu dan)                 �����������            70%                    �� 5.00\n";
  msg +=HIR "ϴ�������ɵ�(Xisui xiandan)            �����������            85%                    ��10.00\n\n\n" NOR;
  
  write(msg);
  return 1;

}

int do_pull(string arg)
{
        object me,ob;
        int rmb;
        me = this_player();

        if (! arg || (arg != "card" && arg != "huiyuan card"))
                return 1;

        if (me->is_busy())
        {
                return notify_fail("����æ���ء�\n");
        }
        // �жϿ�Ƭ�Ƿ�δȡ��
        if (me->query("temp/insert") && me->query("temp/can_pull"))
        {      
                rmb = me->query("rmb");
                tell_object(me, HIC "��Ŀǰ�Ĵ��Ϊ" + chinese_number(rmb) + "Բ����ҡ�\n" NOR);
                write(HIW "�㽫��Ƭ���׻��Զ��ۻ�����ȡ����\n" NOR);
                ob = new("/clone/gift/hycard.c");
                ob->move(me);
                me->delete("temp/insert");
                return 1;
        }
        write(HIR "��������!\n" NOR);
        return 1;
}


int do_buy(string arg)
{
    object me, ob;
    int rmb, feng,sun,lighting,water;
    
    me = this_player();
    rmb = me->query("rmb");
    
    if (! arg || arg == "") return 1;
    
    if (arg == "shenli dan")
    {
          if (rmb < 2)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/str1");
          ob->move(me);
          me->add("rmb", -2); 
          write(HIG "������һ�������裡\n" NOR);       
    } 
    else  if (arg == "baihu dan")
    {
          if (rmb < 5)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/str2");
          ob->move(me);
          me->add("rmb", -5);  
          write(HIG "������һ�Ű׻���Ԫ����\n" NOR);
    }    
    else if (arg == "zhuyuan xiandan")
    {
          if (rmb < 10)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/str3");
          ob->move(me);
          me->add("rmb", -10);  
          write(HIG "������һ�������Ԫ�ɵ���\n" NOR);
    }    
    else if (arg == "zenghui dan")
    {
          if (rmb < 2)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/int1");
          ob->move(me);
          me->add("rmb", -2);  
          write(HIG "������һ�����۵���\n" NOR);
    }        
    else if (arg == "qinglong dan")
    {
          if (rmb < 5)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/int2");
          ob->move(me);
          me->add("rmb", -5);  
          write(HIG "������һ�����������\n" NOR);
    }        
    else if (arg == "tonghui xiandan")
    {
          if (rmb < 10)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/int3");
          ob->move(me);
          me->add("rmb", -10);        
          write(HIG "������һ�����ͨ���ɵ���\n" NOR);
    }        
    else if (arg == "fushou gao")
    {
          if (rmb < 2)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/dex1");
          ob->move(me);
          me->add("rmb", -2);        
          write(HIG "������һ�鸣�ٸ࣡\n" NOR);
    }        
    else if (arg == "zhuque dan")
    {
          if (rmb < 5)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/dex2");
          ob->move(me);
          me->add("rmb", -5);    
          write(HIG "������һ����ȸ���絤��\n" NOR);      
    }        
    else if (arg == "wuji xiandan")
    {
          if (rmb < 10)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/dex3");
          ob->move(me);
          me->add("rmb", -10); 
          write(HIG "������һ�������޼��ɵ���\n" NOR);     
    }        
    else if (arg == "zhuanggu fen")
    {
          if (rmb < 2)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/con1");
          ob->move(me);
          me->add("rmb", -2); 
          write(HIG "������һ��׳�Ƿۣ�\n" NOR);       
    }        
    else if (arg == "xuanwu dan")
    {
          if (rmb < 5)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/con2");
          ob->move(me);
          me->add("rmb", -5);    
          write(HIG "������һ���������ǵ���\n" NOR);
    }        
    else if (arg == "xisui xiandan")
    {
          if (rmb < 10)
          { 
              write("�Բ���,��Ŀ�������Ѳ���,�뾡���ֵ!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/con3");
          ob->move(me);
          me->add("rmb", -10);      
          write(HIG "������һ��ϴ�������ɵ���\n" NOR);
    }        
    else{
          write(HIR "��������\n" NOR);
          return 1;
    }
    write(HIG "�������! �뿪ǰ��ǵ�ȡ��(pull)��Ƭ��\n");
    rmb = me->query("rmb");
    tell_object(me, HIC "��Ŀǰ�Ĵ��Ϊ" + chinese_number(rmb) + "Բ����ҡ�\n" NOR);
    if (me->query("rmb") < 10) 
          write(HIY "�������Ѳ��࣬Ϊ�����������Ĳ��㣬�뼰ʱ��ֵ��\n" NOR);
    return 1;
}


