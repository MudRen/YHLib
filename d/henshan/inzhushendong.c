#include <ansi.h>
inherit ROOM;

string look_bi();
string look_pic1();
string look_pic2();
string look_pic3();

void create()
{
        set("short", "�����ɶ���");
        set("long", @LONG
���ܺܿտ���ż��˵��Ҳ�����������������￿�����ڹ�
�߻��㲻��ǧ�������ĳ����ѽ���Χɽ��(bi)�ڸǡ�
LONG);
	set("item_desc",([
	       "bi" :  (: look_bi :),
               "pic1": (: look_pic1 :),
               "pic2": (: look_pic2 :),
               "pic3": (: look_pic3 :),
               
               
	]));

	set("exits",([
	       "out":__DIR__"outzhushendong",
	]));	
	     	
       setup();
}

string look_bi()
{
      object me = this_player();

      if (! me->query_temp("gua"))
          return NOR + WHT "�����ѽ����ڸǣ���֪���������ʲô���㲻���뽫������ȥ����"
                 "������ʲô���ġ�\n" NOR;
      
      return HIY "\nֻ��ɽ���Ͽ���������ͼ��ͼ��������ֱ��������˱��䡣\n"
             "��һ��(pic1)���������˷���������Ϊ����\n"
             "�ڶ���(pic2)����������֮��ȴͻȻ��Ϊ�����ѹ�����֡�\n"
             "������(pic3)��Ϊ��֣�������ȴͻȻһ��Ϊ�壬��ʹ���ֲ�ͬ��ʽ��\n"
             "��Խ��Խ��֣��̲�ס����Ų���������\n\n" NOR;
      
}

string look_pic1()
{
      object me = this_player();

      if (! me->query_temp("gua"))
          return NOR + WHT "����û����Ҫ���Ķ�����\n" NOR;

     return HIY "\nͼ����������Ϊ�������˷��������䲻����\n" NOR;
}

string look_pic2()
{
      object me = this_player();

      if (! me->query_temp("gua"))
          return NOR + WHT "����û����Ҫ���Ķ�����\n" NOR;

     return HIY "\nͼ������ǧ���뷢��������޴��мܡ�\n" NOR;
}

string look_pic3()
{
      object me = this_player();

      if (! me->query_temp("gua"))
          return NOR + WHT "����û����Ҫ���Ķ�����\n" NOR;

     return HIY "\nͼ������һ��Ϊ�壬��ʹ���У��������о����ѹȺɽ��\n" NOR;
}

void init()
{              
	add_action("do_canwu",({"canwu","think"}));
        add_action("do_gua", ({"gua"}));
	
}

int do_gua(string arg)
{
    object me = this_player();

    if (me->is_busy())
          return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
          return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");

    if (! arg || arg != "bi")
          return notify_fail("��Ҫ��ʲô��\n");

    write(HIG "\n���ߵ�ɽ���ԣ���ɽ���ϵĳ���һһ��ȥ�����澰��һһ��¶�˳�����\n" NOR);
    me->set_temp("gua", 1);
   
    return 1;
    
}
int do_canwu(string msg)
{
    object me = this_player();

    string where, witch;
    
    if (! msg)return notify_fail("��Ҫ����ʲô��\n");

    if (sscanf(msg, "%s from %s", witch, where) != 2)
          return notify_fail("��Ҫ����ʲô��\n");

    if (me->is_busy())
          return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
          return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");

    if (witch != "pic1"
        && witch != "pic2"
        && witch != "pic3")
          return notify_fail("�������ʲô��\n");

    if (where != "bi")
          return notify_fail("����ûʲô�������İ���\n");

    if ((int)me->query_skill("martial-cognize", 1) < 220)
          return notify_fail("�����ѧ�����������޷�����ʯ���ϵ��书��\n");

    if ((int)me->query_skill("force", 1) < 180)
          return notify_fail("����ڹ���Ϊ�������޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("max_neili") < 3000)
          return notify_fail("���������Ϊ���㣬�޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("jing") < 100)
          return notify_fail("��ľ����޷����У��޷�����ʯ���ϵľ�ѧ��\n");

    if (me->query_skill("wushen-jian", 1) < 180)
          return notify_fail("��Ժ�ɽ������֪ʵ�����ޣ��޷�����ʯ���ϵľ�ѧ��\n");

    if (witch == "pic1" 
        && me->query("can_perform/wushen-jian/hui"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n");

    else 
    if (witch == "pic2" 
        && me->query("can_perform/wushen-jian/qian"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n");

    else 
    if (witch == "pic3" 
        && me->query("can_perform/wushen-jian/shen"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n"); 

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));

    if (random(2) == 1 && witch == "pic1")
    {
        me->add("wushen_perform/hui/count", 1);

        if (me->query("wushen_perform/hui/count") >= 10)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ���ط������ơ���\n" NOR);

            me->set("can_perform/wushen-jian/hui", 1);
            me->delete("wushen_perform/hui/count");

            if (me->can_improve_skill("sword"))
                    me->improve_skill("sword", 1500000);
            if (me->can_improve_skill("wushen-jian"))
                    me->improve_skill("wushen-jian", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ��ط������ơ����������µ���ʶ������������಻��֮����\n" NOR);
        me->start_busy(1 + random(2));
        return 1;   
    }

    else 
    if (random(4) == 1 && witch == "pic2")
    {
        me->add("wushen_perform/qian/count", 1);

        if (me->query("wushen_perform/qian/count") >= 16)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ��ǧ���ݺ��ơ���\n" NOR);

            me->set("can_perform/wushen-jian/qian", 1);
            me->delete("wushen_perform/qian/count");

            if (me->can_improve_skill("sword"))
                    me->improve_skill("sword", 1500000);
            if (me->can_improve_skill("wushen-jian"))
                    me->improve_skill("wushen-jian", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ�ǧ���ݺ��ơ����������µ���ʶ������������಻��֮����\n" NOR);
        me->start_busy(2 + random(3));
        return 1;   
    }

    else 
    if (random(5) == 1 && witch == "pic3")
    {
        me->add("wushen_perform/shen/count", 1);

        if (me->query("wushen_perform/shen/count") >= 20)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ������Ԫ�ơ���\n" NOR);

            me->set("can_perform/wushen-jian/shen", 1);
            me->delete("wushen_perform/shen/count");

            if (me->can_improve_skill("sword"))
                    me->improve_skill("sword", 1500000);
            if (me->can_improve_skill("wushen-jian"))
                    me->improve_skill("wushen-jian", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ�����Ԫ�ơ����������µ���ʶ������������಻��֮����\n" NOR);                
        me->start_busy(2 + random(3));
        return 1;   
    }

    else return notify_fail("����ͼ��ʯ�����о��йء���ɽ���񽣡������ݣ���ȴûʲôЧ����\n");

}