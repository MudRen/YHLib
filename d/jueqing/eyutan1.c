#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����̶����");
        set("long", @LONG
����̶��صף����Ʊ��ߡ�̶��(tan)һ�ź��ӻζ�����
ϸһ������������͵Ķ��㡣 ֻ����Զ������һ�����ڣ�����
����̶�������֪��ι�ȥ��

LONG);
        set("item_desc",([
               "tan" : HIC "̶�ж����Ⱥ�������ޱȡ� ����ֻ��"
                       "ʩչ�Ṧ��(cross)��ȥ�ˡ�\n" NOR,
        ]));

        set("no_clean_up", 0);

        setup();

}

void init()
{       
        add_action("do_cross", ({ "cross" }));
}

int do_cross(string arg)
{
        object me = this_player();
        object ob1, ob2, ob3;
        int n;
        string msg;

        if (! arg || arg != "tan" )
                return notify_fail("��Ҫ���Ķ�����\n");

        // ob1 ����̶����
        if (! ob1 = find_object(__DIR__"eyutan1"))
                ob1 = load_object(__DIR__"eyutan1");

        // ���Ṧ���������̶ˮ��,   ob2 ��̶
        if (! ob2 = find_object(__DIR__"eyutan2"))
                ob2 = load_object(__DIR__"eyutan2");

        // ob3 ����̶�԰�
        if (! ob3 = find_object(__DIR__"eyutan3"))
                ob3 = load_object(__DIR__"eyutan3");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        n = me->query_skill("dodge");
        
        if (n > 120)
        {   
            msg = HIY + me->name() + HIY "����ǰԾ���������̶��ֻ��" + me->name() +
                  HIY "������̶�Ͽ�ȴ�ֺ������£��ۼ�Ҫ׹��̶�С�ȴ��" + me->name() +
                  HIY "˫���ڶ��㱳��һ�㣬��̼�����԰���\n" NOR;
                      
            tell_room(ob1, sort_msg(msg), me);

            tell_object(me,  HIC "�����ǰԾ��������̶�����˫���ڶ��㱳��һ�㣬գ"
                             "�ۼ���\n���ö԰���\n\n" NOR);

            tell_room(ob3, HIG + me->name() + HIG "�Ӷ԰����˹�����\n" NOR, me);
        
            me->move(ob3);
        }     
        else
        {
            msg = HIR + me->name() + HIR "����ǰԾ���������̶��ֻ��" + me->name() +
                  HIR "������̶�Ͽ�ȴ�����Ѿ�������̶�С�\n" NOR;

            tell_room(ob1, sort_msg(msg), me);

            tell_object(me,  HIR "�����ǰԾ��������̶�����ȴ�о������Ѿ������ͷ"
                            "�Ѳ��ܣ�\nֻ�������ˡ�һ�������Ѿ�������̶֮�С�\n\n" NOR);
             
            me->move(ob2);
        } 

        return 1;
}


