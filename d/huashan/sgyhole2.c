// Room: /d/huashan/sgyhole.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ���������۵�ɽ�������������ʯ����ȴ��������
�����������Ѿ�ʧ���ľ�����С�������ʯ��(wall)�Ϻܶ�С
�ˣ�ȫ�����������ƣ������������֮������ʮ�����
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "southup"   : __DIR__"sgyhole",
            "northdown" : __DIR__"sgyhole3"
        ]));
        set("item_desc", ([ 
            "wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L
TEXT
        ]));

        setup();
}
void init()
{
        add_action("do_mianbi", "mianbi");
        add_action("do_think", "think");
}

int do_think(string msg)
{
    object me = this_player();

    string where, witch;
    
    if (! msg)return notify_fail("ʲô��\n");

    if (sscanf(msg, "%s from %s", witch, where) != 2)
          return notify_fail("��ʲô��\n");

    if (witch != "�򽣷���")
          return notify_fail("�������ʲô��\n");

    if (where != "wall")
          return notify_fail("����ûʲô�������İ���\n");

    if (me->is_busy())
          return notify_fail("��������æ���ء�\n");

    if (me->is_fighting())
          return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");
   
    if (me->query("can_perform/zhurong-jian/wan"))
          return notify_fail("�㲻���Ѿ�������\n");

    if ((int)me->query_skill("zhurong-jian", 1) < 140)
          return notify_fail("��ף�ڽ���������죬�޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query_skill("force") < 220)
          return notify_fail("���ڹ���Ϊ�������޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("max_neili") < 1200)
          return notify_fail("���������Ϊ���㣬�޷���ͨʯ���ϵľ�ѧ��\n");

    if ((int)me->query("jing") < 100)
          return notify_fail("��ľ����޷����У��޷�����ʯ���ϵľ�ѧ��\n");

    me->start_busy(4 + random(4));

    if (random(10) != 1)   
          return notify_fail("����ϸ����ʯ���ϵľ�ѧ���������򣬵���ʼ���޷��ڻ��ͨ��\n");

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));

    write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
    write(HIC "������ͨ���˾�ѧ���򽣷��ơ���\n" NOR);

    me->set("can_perform/zhurong-jian/wan", 1);

    if (me->can_improve_skill("sword"))
            me->improve_skill("sword", 1500000);
    if (me->can_improve_skill("zhurong-jian"))
            me->improve_skill("zhurong-jian", 1500000);
    if (me->can_improve_skill("martial-cognize"))
            me->improve_skill("martial-cognize", 1500000);

    return 1;    
}

int do_mianbi()
{
        object ob;
        int c_skill;

        ob = this_player();

        c_skill = (int)ob->query_skill("zhurong-jian", 1);
        if (ob->query_skill("sword", 1) <= c_skill)
        {
                write("��Խ������˽���Ȼ̫�ͣ��޷�����ʯ�����ݡ�\n", ob);
                return 1; 
        }

        if (! ob->can_improve_skill("zhurong-jian"))
        {
                write("$N��ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (ob->query("jing") < 40)
        {
                write("�㾫�����ܼ��У������޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (c_skill >= 10)
        {
                write("�����ʯ������̫��ǳ�ˡ�\n");
                return 1;
        }

        message_vision("$N�����ʯ��������˼�����ã��ԡ�ף�ڽ�����"
                        "��������\n", ob);
        ob->improve_skill("zhurong-jian", 1 + random(ob->query("int")));
        ob->receive_damage("jing", 35);
        ob->start_busy(2);
        return 1;
}
