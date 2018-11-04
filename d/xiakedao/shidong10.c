// shidong10.c ʯ��

inherit ROOM;

#include <ansi.h>

string look_bi();

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ�ң���Լ���Ըо��������Ǽ�Ӳ��ʯ��(bi)��
ʯ���ڸɸɾ�����һ����Ⱦ��
LONG );
        set("exits", ([
               "east" : __DIR__"shidong9",
               "out"  : __DIR__"dating",
        ]));

        set("objects", ([
               __DIR__"obj/baihongjian" : 1,
        ]));

        set("item_desc",([
	        "bi"  : (: look_bi :),
        ]));

        setup();
}

void init()
{       
        add_action("do_canwu", "canwu");
} 

string look_bi()
{
       object me = this_player();
       string msg;
       
       if (me->query_skill("literate", 1)
           || me->query("learned_literate"))
       {
           msg = HIC "\n���ߵ�ʯ��ǰ����ϸ�ۿ�ʯ���ϵ����ݣ�����ʯ�ڲ���\n"
                 "�����״�����֡�����ϸ������Щ����ȴһ������\n" NOR;                    
       }
       else   
       {
           msg = HIW "\n���ߵ�ʯ��ǰ����ϸ�ۿ�ʯ���ϵ����ݣ�����ʯ�ڲ���\n"
                 "�����״�����֣��������δ�����飬�����㲢û����\n"
                 "����Щ���֡�����Ȼ�������������кܶ�ͼ����������\n"
                 "�����̡�������������������죬�����㵸���ƺ���ʲ\n"
                 "ô�������񹦾����������ס�롭��\n" NOR;
       }

       return msg;
}

int do_canwu(string msg)
{
    object me = this_player();

    string where, witch;
    
    if (! msg)return notify_fail("ʲô��\n");

    if (sscanf(msg, "%s from %s", witch, where) != 2)
          return notify_fail("��ʲô��\n");

    if (me->is_busy())
          return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
          return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");

    if (witch != "̫������"
        && witch != "�˷�����"
        && witch != "����һ��")
          return notify_fail("�������ʲô��\n");

    if (where != "bi")
          return notify_fail("����ûʲô�������İ���\n");

    if (me->query_skill("literate", 1)
        || me->query("learned_literate"))
          return notify_fail("�����ʯ�����˰���Ҳû����ʲô��\n");

    if ((int)me->query_skill("force", 1) < 240)
          return notify_fail("����ڹ���Ϊ�������޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("max_neili") < 6000)
          return notify_fail("���������Ϊ���㣬�޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("jing") < 100)
          return notify_fail("��ľ����޷����У��޷�����ʯ���ϵľ�ѧ��\n");

    if (me->query_skill("taixuan-gong", 1) < 200)
          return notify_fail("���̫������֪ʵ�����ޣ��޷�����ʯ���ϵľ�ѧ��\n");

    if (witch == "����һ��" 
        && me->query("can_perform/taixuan-gong/hun"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n");

    else 
    if (witch == "̫������" 
        && me->query("can_perform/taixuan-gong/xuan"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n");

    else 
    if (witch == "�˷�����" 
        && me->query("can_perform/taixuan-gong/po"))
          return notify_fail("�����ѧ�㲻���Ѿ�������\n"); 

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));

    if (random(13) == 1 && witch == "̫������")
    {
        me->add("taixuan_perform/xuan/count", 1);

        if (me->query("taixuan_perform/xuan/count") >= 60)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ��̫����������\n" NOR);

            me->set("can_perform/taixuan-gong/xuan", 1);
            me->delete("taixuan_perform/xuan/count");

            if (me->can_improve_skill("force"))
                    me->improve_skill("force", 1500000);
            if (me->can_improve_skill("taixuan-gong"))
                    me->improve_skill("taixuan-gong", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ�̫�����������������µ���ʶ������������಻��֮����\n" NOR);
        me->start_busy(2 + random(6));
        return 1;   
    }

    else 
    if (random(4) == 1 && witch == "����һ��")
    {
        me->add("taixuan_perform/hun/count", 1);

        if (me->query("taixuan_perform/hun/count") >= 30)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ������һ������\n" NOR);

            me->set("can_perform/taixuan-gong/hun", 1);
            me->delete("taixuan_perform/hun/count");

            if (me->can_improve_skill("force"))
                    me->improve_skill("force", 1500000);
            if (me->can_improve_skill("taixuan-gong"))
                    me->improve_skill("taixuan-gong", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ�����һ�������������µ���ʶ������������಻��֮����\n" NOR);
        me->start_busy(2 + random(6));
        return 1;   
    }

    else 
    if (random(12) == 1 && witch == "�˷�����")
    {
        me->add("taixuan_perform/po/count", 1);

        if (me->query("taixuan_perform/po/count") >= 70)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ���˾�ѧ���˷����ˡ���\n" NOR);

            me->set("can_perform/taixuan-gong/po", 1);
            me->delete("taixuan_perform/po/count");

            if (me->can_improve_skill("force"))
                    me->improve_skill("force", 1500000);
            if (me->can_improve_skill("taixuan-gong"))
                    me->improve_skill("taixuan-gong", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "��ԡ��˷����ˡ����������µ���ʶ������������಻��֮����\n" NOR);                me->start_busy(2 + random(6));
        return 1;   
    }

    else return notify_fail("����ͼ��ʯ�����о��йء�" + witch + "�������ݣ���ȴûʲôЧ����\n");

}
int valid_leave(object me,string dir)
{
        if (dir == "out")
                tell_object(me,"���߳���ʯ�������صس����ڴ���֮�С�\n");

        return ::valid_leave(me,dir);
}
