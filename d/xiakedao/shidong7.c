// Room: /xiakedao/shidong7.c

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
                "west" : __DIR__"shidong8",
                "north" : __DIR__"shidong6",
        ]));
        set("no_clean_up", 0);
        set("item_desc",([
	        "bi"  : (: look_bi :),
                "weapon": "ͼ�������ֳֵ���������ӿ�����\n",
        ]));
        setup();
}

void init()
{       
        add_action("do_think", "think");
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
           msg = HIC "\n���ߵ�ʯ��ǰ����ϸ�ۿ�ʯ���ϵ����ݣ�����ʯ�ڲ���\n"
                 "�����״�����֣��������δ�����飬�����㲢û����\n"
                 "����Щ���֡�����Ȼ�������������кܶ�ͼ����������\n"
                 "�����̡����滭�Ÿ�ʽ����������е��ֳֳ�������\n"
                 "�����ոֵ���������ͼ���������б���(weapon)������\n"
                 "ͬ��ÿ��������书��ʽҲ��ͬ��������������ȴ�Ծ�\n"
                 "��¶ȫ�������������������ޱȣ�����Ÿ�����ʽ��\n"
                 "���ƺ�������������������̫������������У��ƺ���\n"
                 "���������������й�ϵ�� ����һʱȴҲ����(canwu)��\n"
                 "͸��������ˣ���ȴ�̲�ס�����ѧ(think)������\n" NOR;
       }

       return msg;
}

int do_think(string arg)
{
        object here, me = this_player();
        int add;

        if (! here = find_object(__DIR__"furong1"))
                here = load_object(__DIR__"furong1");

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

        if ((int)me->query_skill("taixuan-gong", 1) < 120)
                return notify_fail("�����ʯ���ϼ��ص��书������˵���ڸ��ӣ�һ"
                                   "ʱ��������\n");
        
        if ((int)me->query_skill("taixuan-gong", 1) >= 180)
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

    if (witch != "weapon")
          return notify_fail("�������ʲô��\n");

    if (where != "bi")
          return notify_fail("����ûʲô�������İ���\n");

    if (me->query_skill("literate", 1)
        || me->query("learned_literate"))
          return notify_fail("�����ʯ�����˰���Ҳû����ʲô��\n");

    if ((int)me->query_skill("force", 1) < 240)
          return notify_fail("����ڹ���Ϊ�������޷������������"
                             "̫����������������\n");

    if ((int)me->query("max_neili") < 6000)
          return notify_fail("���������Ϊ���㣬�޷������������"
                             "̫����������������\n");

    if ((int)me->query("jing") < 100)
          return notify_fail("��ľ����޷����У��޷������������"
                             "̫����������������\n");

    if (me->query_skill("taixuan-gong", 1) < 200)
          return notify_fail("���̫������֪ʵ�����ޣ��޷������������"
                             "̫����������������\n");

    if (me->query("can_learned/taixuan-gong/enable_weapon"))
          return notify_fail("ʯ���ϵľ����������ڻ��ͨ�������ٲ����ˡ�\n");

    me->receive_damage("jing", 95);

    me->start_busy(3 + random(5));

    if (random(6) == 1)
    {
        me->add("canwu_taixuan/count", 1);

        if (me->query("canwu_taixuan/count") >= 50)
        {
            write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
            write(HIC "������ͨ�����������̫����������������\n" NOR);

            me->set("can_learned/taixuan-gong/enable_weapon", 1);
            me->delete("canwu_taixuan/count");

            if (me->can_improve_skill("force"))
                    me->improve_skill("force", 1500000);
            if (me->can_improve_skill("taixuan-gong"))
                    me->improve_skill("taixuan-gong", 1500000);
            if (me->can_improve_skill("martial-cognize"))
                    me->improve_skill("martial-cognize", 1500000);

            return 1;
        }

        write(HIC "����������̫�����������������˸��µ���ʶ����������Ȼ����"
                  "�಻��֮����\n" NOR);
        return 1;   
    }
    else return notify_fail("����ϸ�о�ʯ�������̻������ݣ���ȴûʲôЧ����\n");

}