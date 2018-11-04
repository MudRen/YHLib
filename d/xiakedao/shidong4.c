// Room: /xiakedao/shidong4.c

inherit ROOM;

#include <ansi.h>

string look_bi();

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ�������ܵ��Ű�յ�͵ƣ�ʹ����������ǳ���
����ɽ������ʯ��(bi)�����ǿ̻���ʲô�����������ס�뿴
����
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"shidong5",
                "south" : __FILE__,
                "north" : __DIR__"yingbin",
        ]));

        set("item_desc",([
	        "bi"  : (: look_bi :),
        ]));

        setup();
}

void init()
{       
        add_action("do_think", "think");
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
           msg = HIC "\n���ߵ�ʯ��ǰ����ϸ�ۿ�ʯ���ϵ����ݣ�����ʯ�ڲ���\n"
                 "�����״�����֣��������δ�����飬�����㲢û����\n"
                 "����Щ���֡�����Ȼ�������������кܶ�ͼ����������\n"
                 "�����̡����滭�Ÿ�ʽ����������е�վ��������\n"
                 "���ֳ���״�����ն�������  ������������ȴ�Ծ���¶\n"
                 "ȫ�������������������ޱȣ�����Ÿ�����ʽ����\n"
                 "�Ǿ����ޱȣ����̲�ס�����ѧ(think)�����ˡ�\n" NOR;
       }

       return msg;
}

int do_think(string arg)
{
        object here, me = this_player();
        int add;

        if (me->query("special_skill/clever"))
		add = me->query_int() / 4;
        else
		add = me->query_int() / 10;

        if (! living(me) || arg != "bi")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���ء�\n");

        if (me->query_skill("literate", 1) || me->query("learned_literate"))
                return notify_fail("�㷢��ʯ���ϵ��书���֮����һʱ������ᣡ\n");

        if ((int)me->query("int") < 38)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if ((int)me->query("dex") < 34)
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("��Ļ����ڹ���򲻹����޷�����ʯ��"
                                   "�ϵ��书��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬�޷�ѧϰʯ���ϵ��书��\n");

        if ((int)me->query("jing") < 85)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 60)
                return notify_fail("�����ʯ���ϼ��ص��书������˵���ڸ��ӣ�һ"
                                   "ʱ��������\n");
        
        if ((int)me->query_skill("taixuan-gong", 1) >= 120)
                return notify_fail("�����ʯ���ϼ��ص��书������˵̫ǳ�ˣ������"
                                   "ʲôҲûѧ����\n");

        me->receive_damage("jing", 75);

        if (me->can_improve_skill("taixuan-gong"))
                me->improve_skill("taixuan-gong", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������ص��񹦣�"
                       "��������\n" NOR, me);
        write(HIC "��ԡ�̫�����������µ�����\n" NOR);
        return 1;
}